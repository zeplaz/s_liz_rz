//tela post.

#ifndef SLAZERZ_01_TELA_POST_001_HPP
#define SLAZERZ_01_TELA_POST_001_HPP

#include <vector>
#include <string>
#include <queue>
#include <set>

#include <tuple>

#include <algorithm>

struct callable{};
struct equttable{};

struct trazmitable{};
struct ecoutable{};
struct tranzmitative{};
struct receptive{};

struct tag_default_pak{};


//struct messagable{};
struct telable{};

namespace SL_ZER
{
	namespace Utility{
		long generate_entity_ID()
		{
			static long next_ID{0};
			return next_ID++;
		}
	}
}


constexpr uint32_t TEL_FLAG_PRICE_ALERT = 0x00010; 
constexpr uint32_t TEL_FLAG_OPEN_WINDOW = 0x00030;

enum Destination
{
GUI,
PRICE_COMANDER,
ANALITICS
};


enum Tela_Type
{	NONE,
	Gui_Request_Price_Alert
};



enum class Gui_Requests
{	
	NONE,
	PRICE_ALERT_REQ,
	OPEN_ANYLTIC_WINDOW,
	OPEN_PRICE_ALERT_WINDOW
};



template<typename RequestsArgType>
class equtter_reqest;


template<typename RequestsArgType>
class mediator
{
    typedef std::vector<equtter_reqest<RequestsArgType>*> request_list;

    private : 
    static mediator<RequestsArgType>* instance; 

    static mediator<RequestsArgType>& get_insta()
    {
    	if(!instance)
    	{
    		instance = new mediator();
    	}
    	return *instance; 
    }

    protected :
    request_list equtters;

    void fire_request(equtter_reqest<RequestsArgType>* eq_req)
    {
    	for(auto it = equtters.begin(); it != equtters.end(); it++)
    	{

    	}
    }
    void registar_equtter(equtter_reqest<RequestsArgType>* eq_rest)
    {
    	equtters.push_back(eq_rest);
    }

};



struct entity{

	long id = -1; 

	entity()
	{
	 id = SL_ZER::Utility::generate_entity_ID();

	}
};


struct rooted_entity :entity
{
	entity* root; 
	bool isa_root; 
	rooted_entity(entity* in_root)
	{
		id =  SL_ZER::Utility::generate_entity_ID();
		isa_root = false;
		root = in_root; 
	}

	void set_root(entity* in_e)
	{
		root = in_e;
		isa_root = false; 
	}
};

typedef std::tuple<uint32_t,std::array<std::string,3>> flag_3word;



template<typename destionation>
struct package
{
};


template<>
struct package<tag_default_pak>
{	
	std::string info{""};
	uint32_t flags{0};	 

	flag_3word data;	

	package(std::string dec, uint32_t f)
	{
		info =dec;
		flags = f; 
	}

	package(std::string dec, uint32_t f, flag_3word dat)
	{
		info =dec;
		flags = f;
		data =dat;  
	}

	void add_flag(uint32_t fl)
	{
		flags |=fl; 
	}
	~package()
	{

	}

	private : 
	package();

	friend class package_factory;
};



template<typename... Tup_types> 
struct channel_package
{
std::tuple<Tup_types...> data;
friend channel_conections<channel_package<Tup_types...>>;

};

template<typename CRTP, class RET>
class factory 
{	
	public : 
	RET interface()
	{
		 static_cast<CRTP*>(this)->operator();
	}
};
/*
class pak_factory : factory<pak_factory,package>
{
	package oprator()();
};



package pak_factory::oprator()(uint32_t pak_req)
	{
		swtich(pak_req)
		{

			case :
			{}
			case : 
			{}
			case :
			{}
			default : 
			{}

		}
		return 
	}
};


*/

struct telagram : entity 
{
	int priorty=0;
	void* destination;
	
	package<tag_default_pak> pak; 

};



class tela_post_MCP
{
	static std::set<int> used_ids;
	std::priority_queue<telagram> waiting_telaz;

};










//000000000000000000000000000000000000000




template<typename derived>
struct messagable{

	
	bool handle(messagable<derived> const& msg_e);
};


template<class derived>
bool messagable::handle(messagable<derived> const& msg_e, telagram& tela)
{
  derived const& d1 = static_cast<derived const&>(msg_e);

	return d1.handle(tela);     
}


struct node
{
	bool isa_root = true;
	node* root; 

	int leaf_count; 
};


template<typename derived>
struct trazmiter{

	std::vector<telagram> to_tranzmit;
	template<derived>
	void trazmit();
	

	
};




template<typename... abilityz>
class ability : public abilityz...
{

};


class entity_window : public ability<receptive,ecoutable,tranzmitative>
{

};



struct gui_event_subscribe{};
struct gui_interface{};


struct interfaceable{};

template<typename RET>
struct channel_conections{
	auto& request_data()
	{
		return static_cast<RET*>(this)->request; 
	}
}


template<typename type, typename abilityz, typename tag_log>
void cycle_and_execute_ablity(channel_conections<type>* p, abilityz,tag_log 1)
{
	auto& data = p->request_data();
	////
}

template<typename T>
struct ecoutai_posts : T 
{
	

	void tranzmit_msg()
	{
		SL_ZER::Utility::cycle_and_execute_ablity(this, ability<trazmiter<T>>, [] (auto& a)
				{
					a.trazmit();
				});
	}
	void receve_tela()
	{
			SL_ZER::Utility::for_each(this, ability<receptive>, [] (auto& a)
				{
					a.handle_tela();
				});
	}
};


struct dialog{};

struct recever   
{
	int id; 
	void deregistar(long id);
	void registar(long   id);

	void process_tela(telagram tela); 
};

enum class Tela_IDs : std::uint64_t
{
	NONE,
	GENREAL,
	GUI_TELA

};

auto font_dialoq = dialog();

/*
template<typename... Ts>
class composition : public call_<detail::make_base<composition<Ts..>>, Ts...>

{
std::tuple<call_<Ts, Ts...>...> data;
};

template<typename...Ts>
auto v_box_layout(Ts...args)
{
	return compose(ability<gui_event_subscribe>.interface<gui_interface>, args...);
}
*/

/*

struct tela_gui : public trazmitable
{
	using id = std::intergal_constant<std::unint16_t,GUI_TELA>;
	std::string info;
	std::uint64_t flags;
};


template<typename B>
struct gui_interface : B {
template<typename E>
	auto tranzmit_event(E& e)
	{
		return for_each(this,ability<gui_event_subscribe>, gather<E>,[a= acess_to(this),&](auto& m ){m.tranzmit_event(e,a);});
	}

	template<typename E,typename A>
	auto tranzmit_event(E& e, A a)
	{
	return for_each(this, ability<gui_event_subscribe>,gather<E> ,[&](auto& m){m.tranzmit_event(e,a);});	
	}
		
	
};

template<typename T>
struct on_keypress{
	template<A,R>
	auto consume_event( keypress_event e, A a, R root)
	{

		root.tranzmit_event(signal_event(signal_name<T> a));
	}
};

struct equtter : public  trazmiter{

	public : 
	void registar(equttable* equt);
	void deregistar(equttable* ecut);

};


struct dispatcher : public : trazmiter
{

};

class gui_equtter : public equtter
{

};
*/
#endif