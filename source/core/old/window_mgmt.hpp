

void window_glfw::set_windowSize_callback()
{
    
  curr_window = nullptr;
  glfwSetWindowSizeCallback(window,[](GLFWwindow* window, int w, int h)
    {

     for (auto& itr : g_lWindows)
     {
          if (itr->m_pWindow == a_pWindow)
          {
               window = itr;
               window->m_uiWidth = a_iWidth;
               window->m_uiHeight = a_iHeight;
               window->m_m4Projection = glm::perspective(45.0f, float(a_iWidth)/float(a_iHeight), 0.1f, 1000.0f);
          }
     }
 
     GLFWwindow* previousContext = g_hCurrentContext;
     glfwMakeContextCurrent(window);
     glViewport(0, 0, a_iWidth, a_iHeight);
     glfwMakeContextCurrent(previousContext);


    glfwSetWindowSize(window, w, h);    
    });



typedef std::shared_ptr<window_glfw> Windowglfw_ptr;

struct window_map : public std::unordered_map<E_ID,Windowglfw_ptr,hasher_eid>
{
    void operator() (Windowglfw_ptr in_win)
    {
        this->insert(std::make_pair(in_win->id, in_win));
    }

    void remove(E_ID id)
    {   
        this->erase(id);
    }
};

struct window_list : public std::forward_list<Windowglfw_ptr>
{
    void operator() (Windowglfw_ptr in_win)
    {
        this->push_front(in_win);
    }

    void idremove(E_ID id)
    {   
        this->remove_if([]( Windowglfw_ptr n){ return n.flag_collectable; }); 
    }

    //currnly set to id sort. but should add a priory sort..?
    void idsort()
    {this->sort()}
  

  

};
/*
class windows_MGMT
{
    //window_map w_map; 
    //window_list w_list;
    

    shared_ptr<window_glfw> curr_window = nullptr;
    public : 
    
    unsigned int open_windows = 0; 
      E_ID create_window(int w, int h, std::string title)
    {   
        ERRORCODE  co;
        auto sp = std::make_shared<window_glfw>();

        co  = sp->setup_glfw_context();
          std::cout <<  "ERROR CODE setup_glfw_context::" << error_to_string(co) << ":::sutff::\n";
        co  = sp->create_window(w, h, title);
        
        std::cout <<  "ERROR CODE CREATION WINDOW::" << error_to_string(co) << ":::sutff::\n";
        sp->glew_check();

      //  w_map(sp);
        open_windows++;
        curr_window = sp; 
        return sp->id;
    }
    
    //MUST BE CALLED BY MAIN THREAD!!!
    static bool poll_tno_close();
   


};

*/
/*
struct window_array : public std::array<glfw_window*,MAX_GLFW_WINDOWS>
{
    size_t n_windows = 0; 
    size_t i_next = 0; 

    std::priority_queue<size_t>
    size_t insert_rv(glfw_window* in_win)
    {
        if(i_next == 5)
        {
            std::cout << "ERROR max window allowed";
            return SIZE_MAX; 
        }
        this->[i_next] = in_win; 
        n_windows++;


        return n_windows-1; 
    }

};*/

#endif





bool windows_MGMT::poll_tno_close()
    {   
       // std::cout << "polling for close window..\n";
     
      for(auto it =  w_map.begin(); it != w_map.end(); it++)
        {   
            int win =  it->second->is_window_open();
            std::cout << "window to be closed?;" << win << "\n";
            if( 0 != win)
            { 
                std::cout << "window to be closed;\n";
                it->second->shutdown();
                w_map.remove(it->first);
                open_windows--;
            }
        }
        if(open_windows <1)
        { 
          return false;
        }
        else
        {
          return true;     
        }        
    }