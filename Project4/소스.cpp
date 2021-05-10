#include <iostream>
#include "StringClass.h"

int main()
{
	MyString str("MyString Test");
	MyString str1(str);

	str.Println();
	str1.Print();

	MyString str3("");
	

	return 0;
}