#pragma once
#ifndef _PRAC_PERSON_IMPL_HPP_
#define _PRAC_PERSON_IMPL_HPP_

#ifdef BUILD_DLL_LIBRARY
	#define __PERSON_DLL_DECLSPEC __declspec(dllexport)
#else
	#define __PERSON_DLL_DECLSPEC __declspec(dllimport)
#endif


#include "Person.hpp"


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
//========//========//========//========//=======#//========//========//========//========//=======#


#undef __PERSON_DLL_DECLSPEC

#endif // end of #ifndef _PRAC_PERSON_IMPL_HPP_