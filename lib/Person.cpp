#include "Person.hpp"
#include "Person_impl.hxx"


prac::Person
::	Person(char const* const name_, int const age_) : _pimpl( __Create_Person_impl(name_, age_) )
{}

prac::Person
::	~Person(){  __Destroy_Person_impl(_pimpl);  }

char const* prac::Person::name() const noexcept{  return __Person_impl_name(_pimpl);  }
int prac::Person::age() const noexcept{  return __Person_impl_age(_pimpl);  }
void prac::Person::Hello(Person const& person) noexcept{  __Person_impl_Hello(person._pimpl);  }
//========//========//========//========//=======#//========//========//========//========//=======#