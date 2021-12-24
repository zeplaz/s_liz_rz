

//telapost_render.hpp

#include <forward_list>

struct render_package
{

	bool ghost = false; 
};


struct render_packages : public std::forward_list<render_package>
{
	

};


struct gui_package
{

	bool ghost = false; 
};


struct gui_packages : public std::forward_list<gui_package>
{
	

};

struct render_requester
{

	render_packages render_paks; 
	gui_packages gui_paks; 

	render_packages& request_render_packs()
	{
		return render_paks; 
	}


};
