#include "String.h"
#include <iostream>

int main()
{
	String string1("C++ Programming");
	String string2("string2");
	String string3("String3");
	String string4("Hi");
	String string5("Hello");
	String string6("ABCD");
	String string7;
	String string8 = "";

	std::cout << "==== String 1 ====" << std::endl;
	std::cout << "capacity() Test : " << string1.capacity() << std::endl;
	std::cout << "Length() Test " << string1.length() << std::endl;
	std::cout << "size() Test : " << string1.size() << std::endl;

	//========== Append ========== 
	string2.append("Append Test");
	string2.print(true);

	string3.append(string2);
	string2.print(true);

	//========== 연산자 오버로딩 (=) ==========
	string4 = string3;
	string4.print(true); 

	string5 = "String4 Test";
	string5.print(true);

	string5 += string4;
	string5.print(true);

	string6 += "EFG";
	string6.print(true);
	//========== 연산자 오버로딩 ([]) ==========
	std::cout << string7[3];

	//========== Assign ==========
	string7.assign("asdf");
	string7.print(true);

	string7.assign(string6);
	string7.print(true);
	string7.capacity();

	string7.shrink_to_fit();
	string7.capacity();
	
	return 0;
}