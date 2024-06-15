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
		void* Create_Person_impl(char const* const name, int const age);

		__PERSON_DLL_DECLSPEC
		void Destroy_Person_impl(void** const self_p);

		__PERSON_DLL_DECLSPEC
		char const* Person_impl_name(void const* const self);

		__PERSON_DLL_DECLSPEC
		int Person_impl_age(void const* const self);

		__PERSON_DLL_DECLSPEC
		void Person_impl_Hello(Person const& person);
	}

}

#undef __PERSON_DLL_DECLSPEC
//========//========//========//========//=======#//========//========//========//========//=======#


prac::Person::Person(char const* const name_, int const age_) 
:	_pimpl( dll::Create_Person_impl(name_, age_) ){}

prac::Person::~Person(){  dll::Destroy_Person_impl(&_pimpl);  }

char const* prac::Person::name() const noexcept{  return dll::Person_impl_name(_pimpl);  }
int prac::Person::age() const noexcept{  return dll::Person_impl_age(_pimpl);  }

void prac::Person::Hello(Person const& person) noexcept{  dll::Person_impl_Hello(person);  }


#endif // end of #ifndef _PRAC_PERSON_