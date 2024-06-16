#include "Person.hpp"


namespace prac::impl
{

	class Person;

}
//========//========//========//========//=======#//========//========//========//========//=======#


class prac::impl::Person
{
public:
	Person(char const* const name_, int const age_) noexcept;

	char const* name() const noexcept;
	int age() const noexcept;

	static char const* How_to_work() noexcept;

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


char const* prac::impl::Person::How_to_work() noexcept
{
	return "DLL implementation works by pimpl pattern.";
}
//========//========//========//========//=======#//========//========//========//========//=======#


void* prac::dll::Construct_Person_impl(char const* const name, int const age)
{
	return new impl::Person(name, age);
}

void* prac::dll::Copy_Construct_Person_impl(void const* const person)
{
	return new impl::Person( *reinterpret_cast<impl::Person const*>(person) );
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
		delete reinterpret_cast<impl::Person const*>(*pp),  
		*pp = nullptr;
}

void* prac::dll::Copy_Assign_Person_impl(void** const self_p, void const* const person)
{
	*reinterpret_cast<impl::Person*>(*self_p) = *reinterpret_cast<impl::Person const*>(person);

	return *self_p;
}

void* prac::dll::Move_Assign_Person_impl(void** const self_p, void** const person_p)
{
	void* const res = *self_p = *person_p;

	*person_p = nullptr;

	return res;
}


char const* prac::dll::Person_impl_name(void const* const p)
{
	return reinterpret_cast<impl::Person const*>(p)->name();
}

int prac::dll::Person_impl_age(void const* const p)
{
	return reinterpret_cast<impl::Person const*>(p)->age();
}

char const* prac::dll::Person_impl_How_to_work(){  return impl::Person::How_to_work();  }
//========//========//========//========//=======#//========//========//========//========//=======#
