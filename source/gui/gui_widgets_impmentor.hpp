

#include  "imgui_windowBuilder.hpp"
#include "gui_components_02.hpp"





extern const char* GUI_Symbols[];

enum Degree_Colour
{
 DARK_GREEN_03,
 MID_GREEN_02,
 LIGHT_GREEN_01,
 GREEN_YELLOW_00,
 YELLOW_00,
 RED_YELLOW_n00,
 LIGHT_RED_n01,
 MID_RED_n02,
 DARK_RED_n03
};


const ImColor Dark_Green_03(120,210,120);
const ImColor Mid_Green_02(10,210,86);
const ImColor Light_Green_01(12,50,12);
const ImColor Green_Yellow_00(100,130,5);
const ImColor Yellow_00(160,170,5);
const ImColor Red_Yellow_n00(130,100,5);
const ImColor Light_Red_n01(101,10,20);
const ImColor Mid_Red_n02(200,80,80);
const ImColor Dark_Red_n03(220,12,120);
const ImColor ERROR_COLOUR(100,100,100);

struct im_gui_window_parmz
    {
        bool move_from_title = true;
        bool is_docking = true;
        bool is_viewporting = false; 

        

         bool no_titlebar = false;
         bool no_scrollbar = false;
         bool no_menu = false;
         bool no_move = false;
         bool no_resize = false;
         bool no_collapse = false;
         bool no_close = false;
         bool no_nav = false;
         bool no_background = false;
         bool no_bring_to_front = false;

          
        inline void  set_window_flags(ImGuiWindowFlags& window_flags)
        {
            

            if (no_titlebar)        window_flags |= ImGuiWindowFlags_NoTitleBar;
            if (no_scrollbar)       window_flags |= ImGuiWindowFlags_NoScrollbar;
            if (!no_menu)           window_flags |= ImGuiWindowFlags_MenuBar;
            if (no_move)            window_flags |= ImGuiWindowFlags_NoMove;
            if (no_resize)          window_flags |= ImGuiWindowFlags_NoResize;
            if (no_collapse)        window_flags |= ImGuiWindowFlags_NoCollapse;
            if (no_nav)             window_flags |= ImGuiWindowFlags_NoNav;
            if (no_background)      window_flags |= ImGuiWindowFlags_NoBackground;
            if (no_bring_to_front)  window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus;
            //if (no_close)           p_open = nullptr; // Don't pass our bool* to Begin
        }
    };

   namespace SL_ZER
   {
      ImVec4 DEF_active_colour{10,200,20,80}; 
      Imvec4 DEF_inactive_colour{40,40,40,60}; 
   } 
  


struct imgui_button
{
   ImVec4  active_colour =     DEF_active_colour; 
   ImVec4  inactive_colour =   DEF_inactive_colour;

};

struct butten_widget : public gui_widgets<gui_compoent,imgui_button>
{
    Button_Type button_type; 
}; 



struct confirm_button : public  butten_widget
{
 this->name = "confirmButton";    
 button_type = Button_Type::confirm_button; 
 paramz.has_label = true;
 paramz.title = "Confirm";
};

struct submit_button : public butten_widget
{
    button_type = Button_Type::submit_button; 

};
struct save_button
{
 button_type = Button_Type::save_button; 
};

struct close_button : public  butten_widget
{
 this->name = "closeButton";       
 button_type = Button_Type::close_button; 
 paramz.has_label = true; 
 paramz.title = "close"; 
};


//struct text_input : public gui_widgets<>

struct user_text_input_form :public gui_widgets<gui_compoent>
{
    
    user_text_input_form(std::string formtext)
    {
        paramz.text = formtext;
    }
    user_text_input_form()
    {
        paramz.text = "Input data here"; 
    }

    close_button bclose; 
    submit_button bsubmit; 
    std::string buffer;    

}; 

struct display_popup gui_widgets<gui_compoent>
{
    
    display_popup(std::string dtext)
    {
        paramz.text = dtext;
    }

    close_button bclose; 
}; 


typedef std::variant<user_text_input_form,display_popup> Gui_Widget_Variants;




class widget_factorory
{
    Gui_Widget_Variants operator()(Gui_widget_Type  gui_type)
    {
        switch (gui_type)

        {
          case : Gui_widget_Type::Text_PopUp
          {

          }

          case :Gui_widget_Type::User_Text_Input
          {

          }
         default :    
         {
            fmt::print
         }
        }

    } 
}; 


typedef std::variant<>

constexpr uint BUFFER_SIZE_USER_FORM_INPUT; 

void draw_user_text_form()
{   

    ImGui::InputText(, buf, bufSize);

    if (ImGui::IsWindowFocused() && !ImGui::IsAnyItemActive())

//    ImGui::SetKeyboardFocusHere(keyboardFocus);
}

struct gui_widgets_imp
{
    
void* operator(std::variant) 

void begin(std::string label)
    {
         ImGui::Begin(label.c_str());    
    }
    

   void end()
   {
    ImGui::End();
   }     
void create();
void close();
void draw();
void 
};
struct gui_component_render
{   

    void begin(std::string label)
    {

    }
};


/*


void sample()

{

try{
    std::get<float>(w);                // (7)
  }
  catch (std::bad_variant_access&) {}
}
*/

/*std::vector<std::variant<char, long, float, int, double, long long>>      // 1
               vecVariant = {5, '2', 5.4, 100ll, 2011l, 3.5f, 2017};
  
    for (auto& v: vecVariant){
        std::visit([](auto arg){std::cout << arg << " ";}, v);                // 2
    */

/*class abstract_gui_widget_factory
{
  gui_widget operator() 
  {
    gui_widget gw;

    return gw; 
  }
};
*/

    /*

        void add_compoent();
    void write_im_gui_compnentlist(std::forward_list<price_alert_comp>::iterator it)
    {   

        std::cout << "##->write_im_gui_compnentlist...\n";
    }

    void write_price_alert_group(std::forward_list<price_alert_comp>::iterator it)
    {   
        ImGui::Begin("price_alerts")
        ImGui::BeginGroup(); 
        
        
         ImGui::EndGroup();
         ImGui::End();
    }

    ////
    // TEST FUNCIONS/
    /////
    //std::forward_list<gui_compoent> gui_componets_list; 


void add_gui_compent_test()
{   
        gui_compoent ts1_gui_1;
        ts1_gui_1.im_win_parmz.title= "new test window";
        ts1_gui_1.im_win_parmz.set_window_flags(ts1_gui_1.im_win_flag);

        gui_componets_list.push_front(ts1_gui_1);


    //gui_componets_list.emplace_front();
}*/

//----------------------------------------------
    
/*
        gui_io.ConfigWindowsMoveFromTitleBarOnly = parmz.move_from_title;
 
        if(parmz.is_docking)
        {
              gui_io.ConfigFlags |= ImGuiConfigFlags_DockingEnable; 
        }    
        
        if(parmz.is_viewporting)
        {
              gui_io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
        }

      
        gui_io.BackendRendererName  = "imgui_mofifed_opengl_4.X";
        gui_io.KeyMap[ImGuiKey_Delete] = GLFW_KEY_DELETE;
        gui_io.KeyMap[ImGuiKey_Backspace] = GLFW_KEY_BACKSPACE;
}

*/