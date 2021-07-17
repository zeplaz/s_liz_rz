
#ifndef SLIZERZ_01_TEXT_COMBO_BOX_EXETNION_IMGUI_01_HPP
#define SLIZERZ_01_TEXT_COMBO_BOX_EXETNION_IMGUI_01_HPP
/**
 * modfied from 
BY HaSa1002 
https://github.com/ocornut/imgui/issues/2057
*/

#include "../im_gui_modifed_backends.hpp"
#include <string>

namespace ImGui {
	//extern sf::Keyboard::Key; //This key is set by SFML. I had trouble using the correct ImGui Keys, since I only got Count as Key. See the TODOs in propose()
	
	
	bool identical(const char* buf, const char* item);

	int propose(ImGuiInputTextCallbackData* data);
	
	bool TextInputComboBox(const char* id, std::string& str, size_t maxInputSize, const char* items[], 
						 size_t item_len, short showMaxItems);


	// Creates a ComboBox with free text inout and completion proposals
	// Pass your items via items
	// showMaxItems determines how many items are shown, when the dropdown is open; if 0 is passed the complete list will be shown; you will want normaly a value of 8
	bool TextInputComboBox(const char* id, char* buffer, size_t maxInputSize, const char* items[], 
		size_t item_len, short showMaxItems);
}
#endif