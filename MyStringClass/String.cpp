#include "String.h"
#include <iostream>

String::String()
{
	string_len = 0;
	string_data = NULL;
}

String::String(const char* s)
{
	int len = 0;
	for (int i = 0; s[i] != '\0'; i++) 
	{
		len++;
	}
	string_len = len; 
	string_data = new char[string_len];
	capacity_len = string_len;

	for (int i = 0; i != string_len; i++) // 
	{
		string_data[i] = s[i];
	}
}

String::String(const String& s)
{
	string_len = s.string_len;
	string_data = new char[string_len];
	capacity_len = string_len;

	for (int i = 0; i != string_len; i++)
	{
		string_data[i] = s.string_data[i];
	}
}
// 2021-05-10 추가된부분
String& String::assign(const String& str)
{
	if (str.string_len > string_len) { // 새로운 문자열이 기존 문자열보다 더 크기가 크면 
		delete[] string_data;          // 지우고 다시 할당
		string_data = new char[str.string_len]; 
	} 
	for (int i = 0; i != string_len; i++)
	{
		string_data[i] = str.string_data[i];
	}
	string_len = str.string_len;
	return (*this);
}

String& String::assign(const char* str)
{
	int string_len = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		string_len++;
	}
	if (string_len > capacity_len) // 재할당
	{
		delete[] string_data;
	}
	for (int i = 0; i != string_len; i++)
	{
		string_data[i] = str[i];
	}
	return (*this);
}

String& String::append(const String& str)
{ 
	char* string_data_temp = new char[string_len + str.string_len + 1];
	for (int i = 0; i != string_len; ++i)
	{
		string_data_temp[i] = string_data[i];
	}
	for (int i = 0; i != str.string_len; ++i)
	{
		string_data_temp[i + string_len] = str.string_data[i];
	}
	
	delete[] string_data;
	string_data = string_data_temp;
	string_len += str.string_len;
	return (*this);
}


// 2021-05-10

String::~String()
{
	delete[] string_data;
}

void String::Print()
{
	for (int i = 0; i != string_len; i++)
	{
		std::cout << string_data[i];
	}
	std::cout << std::endl;
}

int String::length()
{
	return string_len;
}

int String::capacity()
{
	return capacity_len;
}

int String::size() // 크기
{
	return (char*)(&string_data + 1) - (char*)(&string_data);
}