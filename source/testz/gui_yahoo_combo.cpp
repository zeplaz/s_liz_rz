
//combing yahh and gui?


#include "../yahoofinace/yah_req_threader.hpp"

#include "../core/opengl_utility.hpp"
#include "../core/engine.hpp"

struct yahoo_MCP
{
	parser_quote_yah pq;
	quote_bank qb;
	std::shared_ptr<quote_bank> s_qb; 
	Atomic_Pointer<quote_bank> ap_bank;
	
	thread_worker<quote_bank,quote_req_pak,quote_yah> yah_thead_worker;

	yahoo_MCP() : yah_thead_worker(process_call_yahoo)  
	{
		s_qb = std::make_shared<quote_bank>(qb); 
		ap_bank.store(s_qb);
	}

	void shutdown()
	{
		yah_thead_worker.shutdown();
	}


void genrate_single_quote(quote_req_pak req)
{
	Key the_rquested_key = yah_thead_worker.create_request(&ap_bank ,req);

}

void retrive_single_quote(Key the_rquested_key)
{
	 Atomic_Pointer<quote_yah> active_quote;

	int code =  s_qb->retreive(active_quote,the_rquested_key);
	fmt::print("\n stauscode::{} \n\n", code);

	if(code ==0)
	{
		std::shared_ptr<quote_yah> qyhut = active_quote.load();
		fmt::print("symbol::{}\n", qyhut->symbol);
		for(size_t i = 0; i< qyhut->num_spots(); i++)
		{
			fmt::print("thespotzbeat::{}",qyhut->spots.at(i).to_string());
		}
	}
}


};

int main( int argc, char** argv)
{
	//startup
	yahoo_MCP yah_MCP; 
	//std::thread background_thread_yah(std::ref(yah_MCP.yah_thead_worker));



	engine mengine; 
    mengine.ignition();
  //  mengine.load_testz_systems();

    fmt::print("\n--->> main about to cycle\n");
    mengine.cycle();
    
    mengine.shutdown();

/*
glm::vec4 clear_colouer { 0.3,0.3,0.4, 0.4};
bool show_another_window = true;
 while (!glfwWindowShouldClose(mrender.window))
    {


    	 glfwPollEvents();

    	         ImGui_ImplOpenGL3_NewFrame();
        mgui.ImGui_ImplGlfw_NewFrame(mrender.window);
        ImGui::NewFrame();
    	  if (show_another_window)
        {
            ImGui::Begin("Another Window", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
            ImGui::Text("Hello from another window!");
            if (ImGui::Button("Close Me"))
                show_another_window = false;
            ImGui::End();
        }

         ImGui::Render();


         int display_w, display_h;
        glfwGetFramebufferSize(mrender.window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
    	  glClearColor(0.2f, 0.2f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);


        /////DRAW

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());



        ///swap


        glfwSwapBuffers(mrender.window);

        ///
    }

*/

//shutdown 
	yah_MCP.shutdown();
//	background_thread_yah.join();
	return 0; 
}
