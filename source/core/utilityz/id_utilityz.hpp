
#ifndef SLAZERZ_01_ID_UTILITYZ_001_HPP
#define SLAZERZ_01_ID_UTILITYZ_001_HPP


//
/*
*
*                 |\ UTILITYZ/|
*	in own namespace  
*
*/


namespace Utility 
{

class id_generator
{

inline static long next_id = {0};
public : 
static long get_next()
{
  next_id++; 
  return next_id;
}

};
}

template<typename T>
struct self_counter
{
  static inline unsigned int obj_created =0;
  static inline unsigned int obj_alive   =0;

 unsigned int objects_destoryed()
  {
    return obj_created- obj_alive; 
  }

 self_counter(const self_counter&)
{
  obj_created++;
  obj_alive++;
}
 self_counter()
{
  obj_created++;
  obj_alive++;
}

  protected :
    ~self_counter()
    {
      obj_alive--;
    }  
};



struct E_ID : public self_counter<E_ID>
{
 long id; 
 E_ID()
 {
  id  = Utility::id_generator::get_next();
 }
 long operator () ()
  {
    return id; 
  }

  bool operator==(const E_ID& other) const
  {
    return id == other.id; 
  } 
}; 


struct hasher_eid
{

  std::size_t operator()(const E_ID& e) const 
{
        size_t res = 17;
        res = res * 31 + std::hash<long>()(e.id);
        return res;
}

};
    

/*
template<typename SELF, typename ConT = long>
class OBJ_ID : public self_counter<OBJ_ID>
{
  public : 
  ConT id; 
  ConT return_id();
  ConT operator () ()
  {
    return id; 
  }
}; */ 
#endif