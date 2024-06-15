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
	~Person();

	char const* name() const noexcept;
	int age() const noexcept;

	static void Hello(Person const& person) noexcept; 

	class impl;

private:
	impl* _pimpl;
};
//========//========//========//========//=======#//========//========//========//========//=======#


#ifdef BUILD_DLL_LIBRARY
	#define __PERSON_DLL_DECLSPEC __declspec(dllexport)
#else
	#define __PERSON_DLL_DECLSPEC __declspec(dllimport)
#endif

namespace prac
{

	extern "C"
	{
		__PERSON_DLL_DECLSPEC
		Person::impl* __Create_Person_impl(char const* const name_, int const age_);

		__PERSON_DLL_DECLSPEC
		void __Destroy_Person_impl(Person::impl*& self);

		__PERSON_DLL_DECLSPEC
		char const* __Person_impl_name(Person::impl const* const self);

		__PERSON_DLL_DECLSPEC
		int __Person_impl_age(Person::impl const* const self);

		__PERSON_DLL_DECLSPEC
		void __Person_impl_Hello(Person::impl const* const person);
	}

}

#undef __PERSON_DLL_DECLSPEC
//========//========//========//========//=======#//========//========//========//========//=======#


prac::Person
::	Person(char const* const name_, int const age_) : _pimpl( __Create_Person_impl(name_, age_) )
{}

prac::Person
::	~Person(){  __Destroy_Person_impl(_pimpl);  }

char const* prac::Person::name() const noexcept{  return __Person_impl_name(_pimpl);  }
int prac::Person::age() const noexcept{  return __Person_impl_age(_pimpl);  }
void prac::Person::Hello(Person const& person) noexcept{  __Person_impl_Hello(person._pimpl);  }


#endif // end of #ifndef _PRAC_PERSON_