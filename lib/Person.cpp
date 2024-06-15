#include "Person.hpp"
#include <iostream>


namespace prac::impl
{

	class Person;

	static Person& To_Person(void* const p) noexcept;
	static Person const& To_Person(void const* const p) noexcept;

}
//========//========//========//========//=======#//========//========//========//========//=======#


class prac::impl::Person
{
public:
	Person(char const* const name_, int const age_);

	char const* name() const noexcept;
	int age() const noexcept;

	static void Hello(prac::Person const& person) noexcept;

private:
	char const* _name;
	int _age;
};


prac::impl::Person
::	Person(char const* const name_, int const age_) : _name(name_), _age(age_){}


char const* prac::impl::Person
::	name() const noexcept{  return _name;  }


int prac::impl::Person
::	age() const noexcept{  return _age;  }


void prac::impl::Person::Hello(prac::Person const& person) noexcept
{
	std::cout
	<<	"Hello. My name is " << person.name() << " and I'm " << person.age() << " years old." 
	<<	std::endl;
}
//--------//--------//--------//--------//-------#//--------//--------//--------//--------//-------#


prac::impl::Person& prac::impl::To_Person(void* const p) noexcept
{
	return *reinterpret_cast<Person*>(p);
}

prac::impl::Person const& prac::impl::To_Person(void const* const p) noexcept
{
	return *reinterpret_cast<Person const*>(p);
}
//========//========//========//========//=======#//========//========//========//========//=======#


void* prac::dll::Create_Person_impl(char const* const name, int const age)
{
	return new impl::Person(name, age);
}


void prac::dll::Destroy_Person_impl(void** const pp)
{
	if(*pp != nullptr)
		delete &impl::To_Person(*pp),  
		*pp = nullptr;
}


char const* prac::dll::Person_impl_name(void const* const p)
{
	return impl::To_Person(p).name();
}


int prac::dll::Person_impl_age(void const* const p)
{
	return impl::To_Person(p).age();
}


void prac::dll::Person_impl_Hello(Person const& person)
{
	impl::Person::Hello(person);
}
//========//========//========//========//=======#//========//========//========//========//=======#
