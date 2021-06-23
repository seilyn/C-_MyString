#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Text.h"
#include "String.h"
#include <string>

#pragma region 기본 생성자
Text::Text() : String()
{
	stringdata = new char[1];
	stringdata[0] = '\n';
	stringlength = 1;
}
Text::Text(const char* str) : String(str)
{
	stringlength = strlen(str);
	stringdata = new char[stringlength + 2];
	for (int i = 0; i <= stringlength; ++i)
	{
		stringdata[i] = str[i];
		if (stringdata[i] == '\0') stringdata[i] = '\n';
	}
	
}
Text::Text(const Text& txt) : String(txt)
{	
	stringlength = txt.stringlength;
	stringdata = new char[stringlength + 1];
	for (int i = 0; i != stringlength; i++)
	{
		stringdata[i] = txt.stringdata[i]; 
		if (stringdata[i] == '\0') stringdata[i] = '\n';
	}
}

Text::Text(const String& str) : String(str) {}
#pragma endregion
#pragma region 소멸자
Text::~Text()
{
	delete[] stringdata;
}
#pragma endregion

#pragma region 연산자 오버로딩
std::ostream& operator<<(std::ostream& out, Text& txt)
{
	out << Text(txt);
	return out;
}
#pragma endregion

#pragma region lines, append 함수
int Text::lines()
{
	int line = 0;
	for (int i = 0; i != stringlength; i++)
	{
		line++;
	}
	return line;
}
Text& Text::append(const char* s)
{
	Text txt(s);
	return append(txt);
}
Text& Text::append(const String& str)
{	
	Text::append(str);
	return (*this);
}
Text& Text::append(const Text& text)
{
	String::append(text);
	return (*this);
}
#pragma endregion