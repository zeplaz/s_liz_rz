


#ifndef SLIZERZ_01_GLFW_WINDOW_BUILDER_01_HPP
#define SLIZERZ_01_FKFW_WINDOW_BUILDER_01_HPP

#include <unordered_map>
#include <memory>   
#include "utilityz/id_utilityz.hpp"

#include "utilityz/errorhandler.hpp"

#include <iostream>
constexpr int DEFAULT_WINDOW_WIDTH  = 500;
constexpr int DEFAULT_WINDOW_HIGHT  = 500;

constexpr int DEFAULT_MAIN_VEWPORT_WIDTH  = 700;
constexpr int DEFAULT_MAIN_VEWPORT_HIGHT  = 700;
class GLFWwindow; 

struct window_glfw
{   

//public params
    E_ID id; 
    bool flag_collectable = false; 
    GLFWwindow* window = nullptr; 
    GLEWContext* context_prt = nullptr;
    
    private :
    
    unsigned int frameportbuffer_width;  
    unsigned int frameportbuffer_height;
    
    glm::mat4    m_m4Projection;
    glm::mat4    m_m4ViewMatrix;

    int lowleft_x=0;
    int lowleft_y=0;     

public: 

    ~window_glfw();

    ERRORCODE setup_glfw_context();
    ERRORCODE create_window(int width, int hight, std::string title);

    ERRORCODE  glew_check();

    void shutdown();
    int is_window_open();

private: 
    void set_viewport_callback();
    void set_windowSize_callback();
    void set_debug_context();

};
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

class windows_MGMT
{
    window_map w_map; 
    window_list w_list;
    

    GLFWwindow* curr_window = nullptr;
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

        w_map(sp);
        open_windows++;
        return sp->id;
    }
    
    //MUST BE CALLED BY MAIN THREAD!!!
    static bool poll_tno_close();
   


};


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