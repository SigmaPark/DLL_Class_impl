#include "Person.hpp"
#include <iostream>


namespace prac::impl
{

	class Person;

	static Person* To_Person(void* const p) noexcept;
	static Person const* To_Person(void const* const p) noexcept;

}
//========//========//========//========//=======#//========//========//========//========//=======#


class prac::impl::Person
{
public:
	Person(char const* const name_, int const age_) noexcept;

	char const* name() const noexcept;
	int age() const noexcept;

	static void How_to_work(prac::Person const& person) noexcept;

private:
	char const* _name;
	int _age;
};


prac::impl::Person
::	Person(char const* const name_, int const age_) noexcept : _name(name_), _age(age_){}


char const* prac::impl::Person
::	name() const noexcept{  return _name;  }


int prac::impl::Person
::	age() const noexcept{  return _age;  }


void prac::impl::Person::How_to_work(prac::Person const& person) noexcept
{
	std::cout << "My dll implementation works by pimpl pattern." << std::endl;
}
//--------//--------//--------//--------//-------#//--------//--------//--------//--------//-------#


prac::impl::Person* prac::impl::To_Person(void* const p) noexcept
{
	return reinterpret_cast<Person*>(p);
}

prac::impl::Person const* prac::impl::To_Person(void const* const p) noexcept
{
	return reinterpret_cast<Person const*>(p);
}
//========//========//========//========//=======#//========//========//========//========//=======#


void* prac::dll::Construct_Person_impl(char const* const name, int const age)
{
	return new impl::Person(name, age);
}

void* prac::dll::Copy_Construct_Person_impl(void const* const person)
{
	return new impl::Person( *impl::To_Person(person) );
}

void* prac::dll::Move_Construct_Person_impl(void** const person_p)
{
	void* res = *person_p;

	*person_p = nullptr;

	return res;
}

void prac::dll::Destruct_Person_impl(void** const pp)
{
	if(*pp != nullptr)
		delete impl::To_Person(*pp),  
		*pp = nullptr;
}

void* prac::dll::Copy_Assign_Person_impl(void* const self, void const* const person)
{
	*impl::To_Person(self) = *impl::To_Person(person);

	return self;
}

void* prac::dll::Move_Assign_Person_impl(void** const self_p, void** const person_p)
{
	void* const res = *self_p = *person_p;

	*person_p = nullptr;

	return res;
}

void prac::dll::Person_impl_swap(void** const self_p, void** const person_p)
{
	void* const temp = *self_p;

	*self_p = *person_p;
	*person_p = temp;
}


char const* prac::dll::Person_impl_name(void const* const p)
{
	return impl::To_Person(p)->name();
}

int prac::dll::Person_impl_age(void const* const p)
{
	return impl::To_Person(p)->age();
}

void prac::dll::Person_impl_How_to_work(Person const& person)
{
	impl::Person::How_to_work(person);
}
//========//========//========//========//=======#//========//========//========//========//=======#
