#pragma once
#include <iostream>
#include "String.h"

class Text : public String
{
public:
	Text();
	Text(const char* str);
	Text(const String& str);
	Text(const Text& str);
	~Text();

	std::ostream& operator<<(std::ostream& out, Text& txt);

	int lines(); // 저장 문자열의 줄 수 반환

	Text& append(const char* s);
	Text& append(const String& str);
	Text& append(const Text& text);
private:
	char stringdata;
	int stringlength;
};