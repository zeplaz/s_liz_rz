
//price alert dialog



#ifndef SLIZERZ_01_BINANCE_PRICE_ALERT_DIALOG_IMGUI_HPP
#define SLIZERZ_01_BINANCE_PRICE_ALERT_DIALOG_IMGUI_HPP

class input_symbol_price_box{
    
     char buffer_symbol[20];
     float price_buffer;
     int e = 0;
      
    //conferm. button
     public : 
    void write();

};

struct price_alert_LED
{
 ImU32  status_col;

 std::string symbol_label{""};
 double price=0.0;
 std::string last_time{""}; 
 int count =0;
 
 
 glm::vec2 uv{0.0,0.0};
 GLuint64 texture_handle{0};


 void set_time(long d)
 {
 	last_time = std::ctime(&d);
 }

 void set_count(int in)
 {
 	count = in;
 }


};


struct price_alert_comp :  

	price_alert_LED LED; 
	

	price_alert_comp(std::string& in_sym, double in_price)
	{
		LED.price = in_price;
		LED.symbol_label = in_sym; 
        text = "Price_Alert";
		//LED.time= std::ctime(&date); 
    }

    ImU32 get_pice_alert_colour(Degree_Colour& in_dc, float alpha);
     void write();
     
};

#endif