#include "Person.hpp"
#include <iostream>


namespace prac::impl
{

	class Person;

}


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
//========//========//========//========//=======#//========//========//========//========//=======#


static prac::impl::Person* To_impl(void* const p)
{
	return reinterpret_cast<prac::impl::Person*>(p);
}

static prac::impl::Person const* To_impl(void const* const p)
{
	return reinterpret_cast<prac::impl::Person const*>(p);
}


void* prac::dll::Create_Person_impl(char const* const name, int const age)
{
	return new impl::Person(name, age);
}


void prac::dll::Destroy_Person_impl(void** const pp)
{
	if(*pp != nullptr)
		delete ::To_impl(*pp),  
		*pp = nullptr;
}


char const* prac::dll::Person_impl_name(void const* const p)
{
	return ::To_impl(p)->name();
}


int prac::dll::Person_impl_age(void const* const p)
{
	return ::To_impl(p)->age();
}


void prac::dll::Person_impl_Hello(Person const& person)
{
	impl::Person::Hello(person);
}
//========//========//========//========//=======#//========//========//========//========//=======#
