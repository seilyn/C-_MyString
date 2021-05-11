#include "String.h"
#include <iostream>

int main()
{
	String string1("C++ Programming");
	String string2("Made By Cy");
	String string3;
	String string4;
	String string5("Hello");
	String string6("ABCD");

	std::cout << "Capacity : " << string1.capacity() << std::endl;
	std::cout << "문자열의 길이 : " << string1.length() << std::endl;
	std::cout << "문자열의 크기 : " << string1.size() << std::endl;

	//string1.Print();
	string2.Print();

	//string1.assign("asdfasdf");
	string2.append("poqwer");
	string2.Print();

	string3 = string2;
	string3.Print(); 

	string4 = "String4 Test";
	string4.Print();

	string5 += string4;
	string5.Print();

	string6 += "EFG";
	string6.Print();

	return 0;
}