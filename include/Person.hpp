#pragma once
#ifndef _PRAC_PERSON_
#define _PRAC_PERSON_


namespace prac
{

	class Person;

}


class prac::Person
{
public:
	Person(char const* const name_, int const age_);
	~Person();

	char const* name() const noexcept;
	int age() const noexcept;

	static void Hello(Person const& person) noexcept; 

private:
	char const* _name;
	int _age;
};


#endif // end of #ifndef _PRAC_PERSON_