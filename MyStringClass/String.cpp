#include "String.h"
#include <iostream>

String::String()
{
	string_len = 0;
	string_data = NULL;
	capacity_len = 0;
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

	for (int i = 0; i != string_len; i++) 
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

String& String::assign(const String& str)
{
	if (str.string_len > string_len) { 
		string_len = str.string_len;       
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
		capacity_len = string_len;
		string_data = new char[capacity_len];
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
String& String::append(const char* s)
{
	String str(s);
	return append(str);
}

// 2021-05-10

// 2021-05-11
String& String::operator=(const String& str)
{
	delete[] string_data;
	string_len = str.string_len;
	string_data = new char[string_len];
	
	for (int i = 0; i != string_len; i++) // strcpy 
	{
		string_data[i] = str.string_data[i];
	}
	return (*this);
}

String& String::operator=(const char* s)
{
	string_len = 0;
	for (int i = 0; s[i] != '\0'; i++)
	{
		string_len++; // char* s의 length
	}
	string_data = new char[string_len + 1];
	for (int i = 0; i < string_len; i++)
	{
		string_data[i] = s[i];
	}
	return (*this);
}

String& String::operator+=(const String& str)
{
	char* string_data_temp; 
	string_data_temp = new char[string_len + str.string_len];

	for (int i = 0; i != string_len; i++)
	{
		string_data_temp[i] = string_data[i];
	}
	for (int i = 0; i != str.string_len; i++)
	{
		string_data_temp[i + string_len] = str.string_data[i];
	}
	delete[] string_data;
	string_data = string_data_temp;
	string_len = string_len + str.string_len;

	return (*this);
}

String& String::operator+=(const char* s)
{
	int temp_len = 0;
	char* string_temp_s;
	for (int i = 0; s[i] != '\0'; i++) // strcpy 
	{
		temp_len++;
	}
	string_temp_s = new char[string_len + temp_len + 1];
	for (int i = 0; i != string_len; i++)
	{
		string_temp_s[i] = string_data[i];
	}
	for (int i = 0; i != temp_len; i++)
	{
		string_temp_s[i + string_len] = s[i];
	}
	string_data = string_temp_s;
	string_len += temp_len;

	return (*this);
}

String::~String()
{
	delete[] string_data;
}

char& String::operator[](int index)
{
	try
	{
		if (index >= string_len || index < 0)
		{
			if (index < 0) index = 0;
			else throw ("Error: Out of Bound");
		}
		else return string_data[index];
	}
	catch (const char* st)
	{
		std::cout << st;
	}
}

const char String::print(bool show) // 수정한 print 함수
{
	if (show == true)
	{
		for (int i = 0; i != string_len; i++)
		{
			std::cout << string_data[i];
		}
		std::cout << std::endl;
	}
	else if (show == false) return 0;

	return *string_data;
}

//void String::Print() 
//{
//	for (int i = 0; i != string_len; i++)
//	{
//		std::cout << string_data[i];
//	}
//	std::cout << std::endl;
//}

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
void String::shrink_to_fit()
{
	if (capacity_len > string_len)
	{
		char* string_data_temp;

		capacity_len = string_len;
		string_data_temp = new char[capacity_len];
		for (int i = 0; i != string_len; i++)
		{
			string_data_temp[i] = string_data[i];
		}
		string_data = string_data_temp;
		string_len = capacity_len;
	}
}