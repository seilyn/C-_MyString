#include "String.h"
#include <iostream>

int main()
{
	String string1("C++ Programming");
	String string2("Made By Cy");

	std::cout << "Capacity : " << string1.capacity() << std::endl;
	std::cout << "문자열의 길이 : " << string1.length() << std::endl;
	std::cout << "문자열의 크기 : " << string1.size() << std::endl;

	//string1.Print();
	string2.Print();

	//string1.assign("asdfasdf");
	string2.append("poqwer");
	string2.Print();
	
	return 0;
}