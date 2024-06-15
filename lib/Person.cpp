#include "Person.hpp"
#include <iostream>


class prac::Person::impl
{
public:
	impl(char const* const name_, int const age_);

	char const* name() const noexcept;
	int age() const noexcept;

	static void Hello(Person const& person) noexcept;

private:
	char const* _name;
	int _age;
};


prac::Person::impl
::	impl(char const* const name_, int const age_) : _name(name_), _age(age_){}


char const* prac::Person::impl
::	name() const noexcept{  return _name;  }


int prac::Person::impl
::	age() const noexcept{  return _age;  }


void prac::Person::impl::Hello(Person const& person) noexcept
{
	std::cout
	<<	"Hello. My name is " << person.name() << " and I'm " << person.age() << " years old." 
	<<	std::endl;
}
//========//========//========//========//=======#//========//========//========//========//=======#


prac::Person::impl* prac::dll::Create_Person_impl(char const* const name_, int const age_)
{
	return new Person::impl(name_, age_);
}


void prac::dll::Destroy_Person_impl(Person::impl*& p)
{
	if(p != nullptr)
		delete p,  
		p = nullptr;
}


char const* prac::dll::Person_impl_name(Person::impl const* const p)
{
	return p->name();
}


int prac::dll::Person_impl_age(Person::impl const* const p)
{
	return p->age();
}


void prac::dll::Person_impl_Hello(Person const& person)
{
	Person::impl::Hello(person);
}
//========//========//========//========//=======#//========//========//========//========//=======#
