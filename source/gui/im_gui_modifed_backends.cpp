
#include "im_gui_modifed_backends.hpp"


void SL_ZER::HelpMarker(const char* desc)
{
    ImGui::TextDisabled("(?)");
    if (ImGui::IsItemHovered())
    {
        ImGui::BeginTooltip();
        ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
        ImGui::TextUnformatted(desc);
        ImGui::PopTextWrapPos();
        ImGui::EndTooltip();
    }
}


//  idk whats going on here, clipbord from glfw this is a wrapper could likley be done away with.. should be
//a template function which takes diffrent windinowsins sdl, glfw etc and builds it out (at complie time etc)
 const char* SL_ZER::clip::ImGui_ImplGlfw_GetClipboardText(void* user_data)
{
    return glfwGetClipboardString((GLFWwindow*)user_data);
}

 void SL_ZER::clip::ImGui_ImplGlfw_SetClipboardText(void* user_data, const char* text)
{
    glfwSetClipboardString((GLFWwindow*)user_data, text);
}



void SL_ZER::callbacks::ImGui_ImplGlfw_MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
    if (imgui_backend::g_PrevUserCallbackMousebutton != NULL)
        imgui_backend::g_PrevUserCallbackMousebutton(window, button, action, mods);

    if (action == GLFW_PRESS && button >= 0 && button < IM_ARRAYSIZE(imgui_backend::g_MouseJustPressed))
        imgui_backend::g_MouseJustPressed[button] = true;
}

void SL_ZER::callbacks::ImGui_ImplGlfw_ScrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
    if (imgui_backend::g_PrevUserCallbackScroll != NULL)
        imgui_backend::g_PrevUserCallbackScroll(window, xoffset, yoffset);

    ImGuiIO& io = ImGui::GetIO();
    io.MouseWheelH += (float)xoffset;
    io.MouseWheel += (float)yoffset;
}



void SL_ZER::callbacks::ImGui_ImplGlfw_KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (imgui_backend::g_PrevUserCallbackKey != NULL)
        imgui_backend::g_PrevUserCallbackKey(window, key, scancode, action, mods);

    ImGuiIO& io = ImGui::GetIO();
    if (key >= 0 && key < IM_ARRAYSIZE(io.KeysDown))
    {
        if (action == GLFW_PRESS)
            io.KeysDown[key] = true;
        if (action == GLFW_RELEASE)
            io.KeysDown[key] = false;
    }

    // Modifiers are not reliable across systems
    io.KeyCtrl = io.KeysDown[GLFW_KEY_LEFT_CONTROL] || io.KeysDown[GLFW_KEY_RIGHT_CONTROL];
    io.KeyShift = io.KeysDown[GLFW_KEY_LEFT_SHIFT] || io.KeysDown[GLFW_KEY_RIGHT_SHIFT];
    io.KeyAlt = io.KeysDown[GLFW_KEY_LEFT_ALT] || io.KeysDown[GLFW_KEY_RIGHT_ALT];
#ifdef _WIN32
    io.KeySuper = false;
#else
    io.KeySuper = io.KeysDown[GLFW_KEY_LEFT_SUPER] || io.KeysDown[GLFW_KEY_RIGHT_SUPER];
#endif
}

void SL_ZER::callbacks::ImGui_ImplGlfw_CharCallback(GLFWwindow* window, unsigned int c)
{
    if (imgui_backend::g_PrevUserCallbackChar != NULL)
        imgui_backend::g_PrevUserCallbackChar(window, c);

    ImGuiIO& io = ImGui::GetIO();
    io.AddInputCharacter(c);
}


/////// the im_gui layer with some functions whould could use a rewrite.

 void imgui_glfw_ctler::ImGui_ImplGlfw_UpdateMousePosAndButtons(GLFWwindow* g_Window)
{
    // Update buttons
    ImGuiIO& io = ImGui::GetIO();
    for (int i = 0; i < IM_ARRAYSIZE(io.MouseDown); i++)
    {
        // If a mouse press event came, always pass it as "mouse held this frame", so we don't miss click-release events that are shorter than 1 frame.
        io.MouseDown[i] = im_backend.g_MouseJustPressed[i] || glfwGetMouseButton(g_Window, i) != 0;
        im_backend.g_MouseJustPressed[i] = false;
    }

    // Update mouse position
    const ImVec2 mouse_pos_backup = io.MousePos;
    io.MousePos = ImVec2(-FLT_MAX, -FLT_MAX);
#ifdef __EMSCRIPTEN__
    const bool focused = true; // Emscripten
#else
    const bool focused = glfwGetWindowAttrib(g_Window, GLFW_FOCUSED) != 0;
#endif
    if (focused)
    {
        if (io.WantSetMousePos)
        {
            glfwSetCursorPos(g_Window, (double)mouse_pos_backup.x, (double)mouse_pos_backup.y);
        }
        else
        {
            double mouse_x, mouse_y;
            glfwGetCursorPos(g_Window, &mouse_x, &mouse_y);
            io.MousePos = ImVec2((float)mouse_x, (float)mouse_y);
        }
    }
}


void  imgui_glfw_ctler::ImGui_ImplGlfw_NewFrame(GLFWwindow* Window)
{
    ImGuiIO& io = ImGui::GetIO();
    IM_ASSERT(io.Fonts->IsBuilt() && "Font atlas not built! It is generally built by the renderer backend. Missing call to renderer _NewFrame() function? e.g. ImGui_ImplOpenGL3_NewFrame().");

    // Setup display size (every frame to accommodate for window resizing)
    int w, h;
    int display_w, display_h;
    glfwGetWindowSize(Window, &w, &h);
    glfwGetFramebufferSize(Window, &display_w, &display_h);
    io.DisplaySize = ImVec2((float)w, (float)h);
    if (w > 0 && h > 0)
        io.DisplayFramebufferScale = ImVec2((float)display_w / w, (float)display_h / h);

    // Setup time step
    double current_time = glfwGetTime();
    io.DeltaTime = im_backend.g_Time > 0.0 ? (float)(current_time - im_backend.g_Time) : (float)(1.0f / 60.0f);
    im_backend.g_Time = current_time;

    this->ImGui_ImplGlfw_UpdateMousePosAndButtons(Window);
    this->ImGui_ImplGlfw_UpdateMouseCursor(Window);

    // Update game controllers (if enabled and available)
    this->ImGui_ImplGlfw_UpdateGamepads();
}


 void  imgui_glfw_ctler::ImGui_ImplGlfw_UpdateMouseCursor(GLFWwindow* g_Window)
{
    ImGuiIO& io = ImGui::GetIO();
    if ((io.ConfigFlags & ImGuiConfigFlags_NoMouseCursorChange) || glfwGetInputMode(g_Window, GLFW_CURSOR) == GLFW_CURSOR_DISABLED)
        return;

    ImGuiMouseCursor imgui_cursor = ImGui::GetMouseCursor();
    if (imgui_cursor == ImGuiMouseCursor_None || io.MouseDrawCursor)
    {
        // Hide OS mouse cursor if imgui is drawing it or if it wants no cursor
        glfwSetInputMode(g_Window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
    }
    else
    {
        // Show OS mouse cursor
        // FIXME-PLATFORM: Unfocused windows seems to fail changing the mouse cursor with GLFW 3.2, but 3.3 works here.
        glfwSetCursor(g_Window,im_backend.g_MouseCursors[imgui_cursor] ? im_backend.g_MouseCursors[imgui_cursor] : im_backend.g_MouseCursors[ImGuiMouseCursor_Arrow]);
        glfwSetInputMode(g_Window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    }
}

void  imgui_glfw_ctler::ImGui_ImplGlfw_UpdateGamepads()
{
    ImGuiIO& io = ImGui::GetIO();
    memset(io.NavInputs, 0, sizeof(io.NavInputs));
    if ((io.ConfigFlags & ImGuiConfigFlags_NavEnableGamepad) == 0)
        return;

    // Update gamepad inputs
    #define MAP_BUTTON(NAV_NO, BUTTON_NO)       { if (buttons_count > BUTTON_NO && buttons[BUTTON_NO] == GLFW_PRESS) io.NavInputs[NAV_NO] = 1.0f; }
    #define MAP_ANALOG(NAV_NO, AXIS_NO, V0, V1) { float v = (axes_count > AXIS_NO) ? axes[AXIS_NO] : V0; v = (v - V0) / (V1 - V0); if (v > 1.0f) v = 1.0f; if (io.NavInputs[NAV_NO] < v) io.NavInputs[NAV_NO] = v; }
    int axes_count = 0, buttons_count = 0;
    const float* axes = glfwGetJoystickAxes(GLFW_JOYSTICK_1, &axes_count);
    const unsigned char* buttons = glfwGetJoystickButtons(GLFW_JOYSTICK_1, &buttons_count);
    MAP_BUTTON(ImGuiNavInput_Activate,   0);     // Cross / A
    MAP_BUTTON(ImGuiNavInput_Cancel,     1);     // Circle / B
    MAP_BUTTON(ImGuiNavInput_Menu,       2);     // Square / X
    MAP_BUTTON(ImGuiNavInput_Input,      3);     // Triangle / Y
    MAP_BUTTON(ImGuiNavInput_DpadLeft,   13);    // D-Pad Left
    MAP_BUTTON(ImGuiNavInput_DpadRight,  11);    // D-Pad Right
    MAP_BUTTON(ImGuiNavInput_DpadUp,     10);    // D-Pad Up
    MAP_BUTTON(ImGuiNavInput_DpadDown,   12);    // D-Pad Down
    MAP_BUTTON(ImGuiNavInput_FocusPrev,  4);     // L1 / LB
    MAP_BUTTON(ImGuiNavInput_FocusNext,  5);     // R1 / RB
    MAP_BUTTON(ImGuiNavInput_TweakSlow,  4);     // L1 / LB
    MAP_BUTTON(ImGuiNavInput_TweakFast,  5);     // R1 / RB
    MAP_ANALOG(ImGuiNavInput_LStickLeft, 0,  -0.3f,  -0.9f);
    MAP_ANALOG(ImGuiNavInput_LStickRight,0,  +0.3f,  +0.9f);
    MAP_ANALOG(ImGuiNavInput_LStickUp,   1,  +0.3f,  +0.9f);
    MAP_ANALOG(ImGuiNavInput_LStickDown, 1,  -0.3f,  -0.9f);
    #undef MAP_BUTTON
    #undef MAP_ANALOG
    if (axes_count > 0 && buttons_count > 0)
        io.BackendFlags |= ImGuiBackendFlags_HasGamepad;
    else
        io.BackendFlags &= ~ImGuiBackendFlags_HasGamepad;
}


bool imgui_glfw_ctler::ImGui_ImplGlfw_Init_redux(GLFWwindow* window, bool install_callbacks, GlfwClientApi client_api)
{

    g_Time = 0.0;

    // Setup backend capabilities flags
    ImGuiIO& io = ImGui::GetIO();
    io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;         // We can honor GetMouseCursor() values (optional)
    io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;          // We can honor io.WantSetMousePos requests (optional, rarely used)
    io.BackendPlatformName = "imgui_impl_glfw";

    // Keyboard mapping. Dear ImGui will use those indices to peek into the io.KeysDown[] array.
    io.KeyMap[ImGuiKey_Tab] = GLFW_KEY_TAB;
    io.KeyMap[ImGuiKey_LeftArrow] = GLFW_KEY_LEFT;
    io.KeyMap[ImGuiKey_RightArrow] = GLFW_KEY_RIGHT;
    io.KeyMap[ImGuiKey_UpArrow] = GLFW_KEY_UP;
    io.KeyMap[ImGuiKey_DownArrow] = GLFW_KEY_DOWN;
    io.KeyMap[ImGuiKey_PageUp] = GLFW_KEY_PAGE_UP;
    io.KeyMap[ImGuiKey_PageDown] = GLFW_KEY_PAGE_DOWN;
    io.KeyMap[ImGuiKey_Home] = GLFW_KEY_HOME;
    io.KeyMap[ImGuiKey_End] = GLFW_KEY_END;
    io.KeyMap[ImGuiKey_Insert] = GLFW_KEY_INSERT;
    io.KeyMap[ImGuiKey_Delete] = GLFW_KEY_DELETE;
    io.KeyMap[ImGuiKey_Backspace] = GLFW_KEY_BACKSPACE;
    io.KeyMap[ImGuiKey_Space] = GLFW_KEY_SPACE;
    io.KeyMap[ImGuiKey_Enter] = GLFW_KEY_ENTER;
    io.KeyMap[ImGuiKey_Escape] = GLFW_KEY_ESCAPE;
    io.KeyMap[ImGuiKey_KeyPadEnter] = GLFW_KEY_KP_ENTER;
    io.KeyMap[ImGuiKey_A] = GLFW_KEY_A;
    io.KeyMap[ImGuiKey_C] = GLFW_KEY_C;
    io.KeyMap[ImGuiKey_V] = GLFW_KEY_V;
    io.KeyMap[ImGuiKey_X] = GLFW_KEY_X;
    io.KeyMap[ImGuiKey_Y] = GLFW_KEY_Y;
    io.KeyMap[ImGuiKey_Z] = GLFW_KEY_Z;

    io.SetClipboardTextFn =  SL_ZER::clip::ImGui_ImplGlfw_SetClipboardText;
    io.GetClipboardTextFn =  SL_ZER::clip::ImGui_ImplGlfw_GetClipboardText;
    io.ClipboardUserData = window;
#if defined(_WIN32)
    io.ImeWindowHandle = (void*)glfwGetWin32Window(window);
#endif

    // Create mouse cursors
    // (By design, on X11 cursors are user configurable and some cursors may be missing. When a cursor doesn't exist,
    // GLFW will emit an error which will often be printed by the app, so we temporarily disable error reporting.
    // Missing cursors will return NULL and our _UpdateMouseCursor() function will use the Arrow cursor instead.)
    GLFWerrorfun prev_error_callback = glfwSetErrorCallback(NULL);
    im_backend.g_MouseCursors[ImGuiMouseCursor_Arrow] = glfwCreateStandardCursor(GLFW_ARROW_CURSOR);
    im_backend.g_MouseCursors[ImGuiMouseCursor_TextInput] = glfwCreateStandardCursor(GLFW_IBEAM_CURSOR);
    im_backend.g_MouseCursors[ImGuiMouseCursor_ResizeNS] = glfwCreateStandardCursor(GLFW_VRESIZE_CURSOR);
    im_backend.g_MouseCursors[ImGuiMouseCursor_ResizeEW] = glfwCreateStandardCursor(GLFW_HRESIZE_CURSOR);
    im_backend.g_MouseCursors[ImGuiMouseCursor_Hand] = glfwCreateStandardCursor(GLFW_HAND_CURSOR);
#if GLFW_HAS_NEW_CURSORS
    im_backend.g_MouseCursors[ImGuiMouseCursor_ResizeAll] = glfwCreateStandardCursor(GLFW_RESIZE_ALL_CURSOR);
    im_backend.g_MouseCursors[ImGuiMouseCursor_ResizeNESW] = glfwCreateStandardCursor(GLFW_RESIZE_NESW_CURSOR);
    im_backend.g_MouseCursors[ImGuiMouseCursor_ResizeNWSE] = glfwCreateStandardCursor(GLFW_RESIZE_NWSE_CURSOR);
    im_backend.g_MouseCursors[ImGuiMouseCursor_NotAllowed] = glfwCreateStandardCursor(GLFW_NOT_ALLOWED_CURSOR);
#else
    im_backend.g_MouseCursors[ImGuiMouseCursor_ResizeAll] = glfwCreateStandardCursor(GLFW_ARROW_CURSOR);
    im_backend.g_MouseCursors[ImGuiMouseCursor_ResizeNESW] = glfwCreateStandardCursor(GLFW_ARROW_CURSOR);
    im_backend.g_MouseCursors[ImGuiMouseCursor_ResizeNWSE] = glfwCreateStandardCursor(GLFW_ARROW_CURSOR);
    im_backend.g_MouseCursors[ImGuiMouseCursor_NotAllowed] = glfwCreateStandardCursor(GLFW_ARROW_CURSOR);
#endif
    glfwSetErrorCallback(prev_error_callback);

    // Chain GLFW callbacks: our callbacks will call the user's previously installed callbacks, if any.
    im_backend.g_PrevUserCallbackMousebutton = NULL;
    im_backend.g_PrevUserCallbackScroll = NULL;
    im_backend.g_PrevUserCallbackKey = NULL;
    im_backend.g_PrevUserCallbackChar = NULL;
    if (install_callbacks)
    {
        im_backend.g_InstalledCallbacks = true;

        im_backend.g_PrevUserCallbackMousebutton = glfwSetMouseButtonCallback(window,  SL_ZER::callbacks::ImGui_ImplGlfw_MouseButtonCallback);
        im_backend.g_PrevUserCallbackScroll = glfwSetScrollCallback(window,  SL_ZER::callbacks::ImGui_ImplGlfw_ScrollCallback);
        im_backend.g_PrevUserCallbackKey = glfwSetKeyCallback(window,  SL_ZER::callbacks::ImGui_ImplGlfw_KeyCallback);
        im_backend.g_PrevUserCallbackChar = glfwSetCharCallback(window,  SL_ZER::callbacks::ImGui_ImplGlfw_CharCallback);
    }

    im_backend.g_ClientApi = client_api;
    return true;
}