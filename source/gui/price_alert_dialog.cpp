


#include "price_aler_dialog.hpp"

ImU32 price_alert_comp::get_pice_alert_colour(Degree_Colour& in_dc, float alpha)
{		
	ImU32 p_colour; 

	switch(in_dc)
	{	

		case DARK_GREEN_03 :
		{p_colour = (Dark_Green_03,alpha);}
		
		case MID_GREEN_02 : 
		{p_colour = (Mid_Green_02,alpha);}
		
		case LIGHT_GREEN_01 :
		{p_colour = (Light_Green_01,alpha);}

		case GREEN_YELLOW_00:
		{p_colour = (Light_Green_01,alpha);}

		case YELLOW_00:
		{p_colour = (Light_Green_01,alpha);}

		case RED_YELLOW_n00:
		{p_colour = (Light_Green_01,alpha);}

		case LIGHT_RED_n01:
		{p_colour = (Light_Green_01,alpha);}

		case MID_RED_n02:
		{p_colour = (Light_Green_01,alpha);}

		case DARK_RED_n03:
		
		{p_colour = (Dark_Red_n03,alpha);}
		
   
		default : 
		{p_colour = (ERROR_COLOUR,alpha);} 

		
	}
	 return p_colour; 
}

     void price_alert_comp::write()
     {
     		ImGui::Begin(it->im_win_parmz.title.c_str(),&it->remain_open, it->im_win_flag);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
           
           //	
            	
            	auto draw = ImGui::GetBackgroundDrawList();

            	draw->AddRectFilled();
            		for(int i =0; i< num_price_alerts)
            		{

					ImVec2 up_left();


					ImVec2 lower_right(10,)            			
            		}
 				ImDrawFlags flags |=ImDrawFlags_RoundCornersAll;

			AddRectFilled(&up_left, &lower_right,  col, 0.1f ,flags );                     // a: upper-left, b: lower-right (== upper-left + size)  

			AddImage(ImTextureID user_texture_id, const ImVec2& p_min, const ImVec2& p_max, const ImVec2& uv_min = ImVec2(0, 0), 
		 const ImVec2& uv_max = ImVec2(1, 1), ImU32 col = IM_COL32_WHITE);

			AddImageQuad(ImTextureID user_texture_id, const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, const ImVec2& p4, const ImVec2& uv1 = ImVec2(0, 0),
 			const ImVec2& uv2 = ImVec2(1, 0), 	const ImVec2& uv3 = ImVec2(1, 1), const ImVec2& uv4 = ImVec2(0, 1), ImU32 col = IM_COL32_WHITE);
    
           ImGui::Text(LED.symbol_label.c_str());

            

            if (ImGui::Button("Close Me"))
                it->remain_open = false;
            // 

            ImGui::Image((void*)(GLuint64*)it->texture_handle, ImVec2(20,20));
            gh_imgui.widget(IMGUI_WIDGET_SEPARATOR)

            ImGui::End();

     }


     void input_symbol_price_box:: write()
    {
        //ImGui::Begin("Add Price Alert");

        ImGui::TextInputComboBox("Symbol_Pair", buffer_symbol, 20, GUI_Symbols, IM_ARRAYSIZE(GUI_Symbols), 0);
        ImGui::InputFloat("Price", &price_buffer,0.0001,0.01);

        ImGui::RadioButton("Roof", &e, 0); ImGui::SameLine();
        ImGui::RadioButton("Floor", &e, 1); ImGui::SameLine();
    
      //  ImGui::B

      //  ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV( 7.0f, 0.6f, 0.6f));
        if(ImGui::Button("Submit"))
        {
            std::cout << "send telagram to price control to update and add price alrt\n";
        }
    }