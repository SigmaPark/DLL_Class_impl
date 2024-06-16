#pragma once
#ifndef _PRAC_PERSON_
#define _PRAC_PERSON_


namespace prac
{

	class Person;

}
//========//========//========//========//=======#//========//========//========//========//=======#


class prac::Person
{
public:
	Person(char const* const name_, int const age_);
	Person(Person const& person);
	Person(Person&& person) noexcept;

	~Person();

	Person& operator=(Person const& person);
	Person& operator=(Person&& person) noexcept;

	char const* name() const noexcept;
	int age() const noexcept;

	static char const* How_to_work() noexcept; 

private:
	void* _pimpl;
};
//========//========//========//========//=======#//========//========//========//========//=======#


#ifdef BUILD_DLL_LIBRARY
	#define __PERSON_DLL_DECLSPEC __declspec(dllexport)
#else
	#define __PERSON_DLL_DECLSPEC __declspec(dllimport)
#endif

namespace prac::dll
{

	extern "C"
	{
		__PERSON_DLL_DECLSPEC
		void* Construct_Person_impl(char const* const name, int const age);

		__PERSON_DLL_DECLSPEC
		void* Copy_Construct_Person_impl(void const* const person);

		__PERSON_DLL_DECLSPEC
		void* Move_Construct_Person_impl(void** const person_p);

		__PERSON_DLL_DECLSPEC
		void Destruct_Person_impl(void** const self_p);

		__PERSON_DLL_DECLSPEC
		void* Copy_Assign_Person_impl(void** const self_p, void const* const person);

		__PERSON_DLL_DECLSPEC
		void* Move_Assign_Person_impl(void** const self_p, void** const person_p);

		__PERSON_DLL_DECLSPEC
		char const* Person_impl_name(void const* const self);

		__PERSON_DLL_DECLSPEC
		int Person_impl_age(void const* const self);

		__PERSON_DLL_DECLSPEC
		char const* Person_impl_How_to_work();
	}

}

#undef __PERSON_DLL_DECLSPEC
//========//========//========//========//=======#//========//========//========//========//=======#


prac::Person::Person(char const* const name_, int const age_) 
:	_pimpl( dll::Construct_Person_impl(name_, age_) ){}

prac::Person::Person(Person const& person)
:	_pimpl( dll::Copy_Construct_Person_impl(person._pimpl) ){}

prac::Person::Person(Person&& person) noexcept
:	_pimpl( dll::Move_Construct_Person_impl(&person._pimpl) ){}

prac::Person::~Person(){  dll::Destruct_Person_impl(&_pimpl);  }

prac::Person& prac::Person::operator=(Person const& person)
{
	return *reinterpret_cast<Person*>( dll::Copy_Assign_Person_impl(&_pimpl, person._pimpl) );
}

prac::Person& prac::Person::operator=(Person&& person) noexcept
{
	return *reinterpret_cast<Person*>( dll::Move_Assign_Person_impl(&_pimpl, &person._pimpl) );
}


char const* prac::Person::name() const noexcept{  return dll::Person_impl_name(_pimpl);  }
int prac::Person::age() const noexcept{  return dll::Person_impl_age(_pimpl);  }
char const* prac::Person::How_to_work() noexcept{  return dll::Person_impl_How_to_work();  }


#endif // end of #ifndef _PRAC_PERSON_