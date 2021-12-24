
//analytics.


constexpr int RED_CLOSE   =-1; 
constexpr int GREEN_CLOSE = 1;
constexpr int NO_CHANGE   = 0; 

constexpr int NEG_POLARITY =-1; 
constexpr int POS_POLARITY = 1;
constexpr int BOTH_POLIARY = 0; 


struct data_spot
{
	double open;
	double close;

	double max_high;
	double max_low;

	int close_drection; 

	double wick_ratio; 



};
struct varancez
{

	int cal_close_drection(data_spot const& ds)
	{
		if(ds.open > ds.close)
			return -1; 
		if(ds.close > ds.open)
			return 1; 
		if( ds.open == ds.close)
			return 0 ; 
	}

	double postive_close_wick_length(data_spot const& ds)
	{
		if(ds.max_high < ds.close || ds.max_high == ds.close)
			return 0.0; 
		else
		{
			return ds.max_high - ds.close; 
		}	
	}
	double negtive_close_wick_length(data_spot const& ds)
	{
		if(ds.max_low > ds.close || ds.max_low == ds.close)
			return 0.0; 
		else
		{
			ds.max_low - ds.close;  
		}	
	}


	double postive_open_wick_length(data_spot const& ds)
	{
		if(ds.max_high < ds.open || ds.max_high == ds.open)
			return 0.0; 
		else
		{
			return ds.max_high - ds.open; 
		}	
	}
	double negtive_open_wick_length(data_spot const& ds)
	{
		if(ds.max_low > ds.open || ds.max_low == ds.open)
			return 0.0; 
		else
		{
			ds.open - ds.max_low;  
		}	
	}


//postive wiki, negtive wik, double wik
	double cal_wick_radio(day_spot const& ds, int polarity)
	{
		if(polarity == NEG_POLARITY)
		{
			if(ds.close_drection == RED_CLOSE)
			{
				
				
			}

			else if (ds.close_drection == )

		}

		if(ds.close_drection < 0)
		{	
	
		}
		

	}




};
