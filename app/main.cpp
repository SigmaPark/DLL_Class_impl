#include "Person.hpp"
#include <iostream>


static void Hello(prac::Person const& person) 
{
	std::cout
	<<	"Hello, my name is " << person.name() 
	<<	" and I'm " << person.age() << " years old." 
	<<	std::endl
	<<	prac::Person::How_to_work()
	<<	std::endl;
}


int main()
{
	prac::Person const person("Michael", 40);

	::Hello(person);

	return 0;
}