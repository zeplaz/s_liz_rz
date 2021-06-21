
#ifndef SLAZERZ_01_UTILITYZ_001_HPP
#define SLAZERZ_01_UTILITYZ_001_HPP

//#include "../binace_contoler/binace_mgmt.hpp"
//#include "render.hpp"
//#include "../analytic_processor_MCP.hpp"
//#include "../gui/render_gui_MCP.hpp"

//
/*
*
*                 |\ UTILITYZ/|
*	in own namespace  and are deifned later where spesfied
*
*/
//#include "enumz_et_defultz.hpp"

#include <string>

enum class Symbol_Tag: uint32_t;
enum class Systems_Online : uint32_t;
namespace Utility 
{
	std::string Symbol_Tag_to_string(Symbol_Tag in_tag); //->DEFINED IN:
	Symbol_Tag  string_to_symbol(std::string symbol);
	std::string which_systems(Systems_Online sym_comp);
}


#endif