#include "String.h"
#include <iostream>

#pragma region 생성자 & 소멸자
String::String()
{
	this->init();
}

String::String(const char* s)
{
	this->init(s);
}

String::String(const String& s)
{
	this->init(s);
}

String::~String()
{
	if (string_data != NULL)
	{
		delete[] string_data;
	}
}
#pragma endregion

#pragma region Assign, Append
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
#pragma endregion

#pragma region 연산자 오버로딩
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
	string_data_temp = new char[string_len + str.string_len + 1];

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
	for (int i = 0; s[i] != '\0'; i++) 
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

String String::operator+(const String& str)
{
	char* string_data_temp = new char[string_len + str.string_len + 1];
	
	for (int i = 0; i != string_len; i++)
	{
		string_data_temp[i] = string_data[i];
	}
	for (int i = 0; i != str.string_len; i++)
	{
		string_data_temp[i + string_len] = str.string_data[i];
	}
	string_data = string_data_temp;
	string_len += str.string_len;

	return (*this);
}

String String::operator+(const char* s)
{
	int temp_len = 0;
	for (int i = 0; s[i] != '\0'; i++)
	{
		temp_len++;
	}
	char* string_data_temp = new char[string_len + temp_len + 1];
	for (int i = 0; i != string_len; i++)
	{
		string_data_temp[i] = string_data[i];
	}
	for (int i = 0; i != temp_len; i++)
	{
		string_data_temp[i + temp_len] = s[i];
	}
	string_data = string_data_temp;
	string_len = string_len + temp_len;

	return (*this);
}

std::ostream& operator<<(std::ostream& os, const String& str)
{
	for (int i = 0; i != str.string_len; i++)
	{
		os << str.string_data[i];
	}
	return os;
}

std::istream& operator>>(std::istream& is, String& str)
{
	char* string_data_temp = new char;
	is >> string_data_temp;
	str = String(string_data_temp);
	return is;
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
#pragma endregion
#pragma region 부가 함수
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

	//return *string_data;
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

#pragma endregion
#pragma region 생성자용 부함수
void String::init()
{
	string_len = 0;
	string_data = new char[string_len + 1];
	string_data[0] = '\0';
}
void String::init(const char* in)
{
	int size = 0;
	for (int i = 0; in[i] != '\0'; i++)
	{
		size++;
	}
	string_len = size;
	capacity_len = string_len;
	string_data = new char[this->string_len + 1];
	for (int i = 0; i != string_len; i++)
	{
		string_data[i] = in[i];
	}
}
void String::init(const String& in) noexcept
{
	string_len = in.string_len;
	string_data = new char[string_len + 1];
	capacity_len = string_len;

	for (int i = 0; i != in.string_len; i++)
	{
		string_data[i] = in.string_data[i];
	}
}
#pragma endregion