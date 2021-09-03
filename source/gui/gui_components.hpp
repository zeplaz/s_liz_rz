//gui_componets

#ifndef SLAZERZ_01_GUI_COMPOENETS_INVENTORY_001_HPP
#define SLAZERZ_01_GUI_COMPOENETS_INVENTORY_001_HPP


//structale parts
struct box{};
struct pane{};
struct table{};
struct devider{};
struct menu{};
struct label{};

//event ablityz

struct recivez_user_input{};
struct recivez_keys     : recivez_user_input {};
struct recivez_mouse    : recivez_user_input {};


//functional ablity
struct accepts_user_text : recivez_keys {};


//ablities//
struct callable{};
struct equttable{};

struct trazmitable{};
struct receptive{};

template<typename derived>
struct messagable{

	template<typename derived>
	bool handle(messagable<derived> const& msg_e);
};

template<class derived>
bool handle(messagable<derived> const& msg_e, telagram& tela);
{
  Derived const& d1 = static_cast<Derived const&>(msg_e);

  d1.handle();     
}
struct telable{};

struct tranzmitative{};

/*

template<typename... Ts>
class composition:public call_<detail::make_base<composition<Ts...>>, Ts...> {};

/*
template <typename... Mixinz>
class composition : public call_<std::detail::make_base<composition<<Mixinz>>, Mixinz...> 
{
	std::tuple<call_<Mixinz,Mixinz...>...> data;

};
*/

//explicit gui_compoent(equttable const& Equttable) : equttable(Equttable) {}
	
	
class dialog 
{
};



class dialog_in_textbox : public dialog{}; 

template <class T> entity_window<T>*  downcast(entity_window<T>* p) { return p; }

#endif