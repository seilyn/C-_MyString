#pragma once
#include <iostream>
#include "String.h"

class Text : public String
{
public:
	Text();
	Text(const char* str);
	Text(const String& str);
	Text(const Text& txt);
	~Text();
	
	int lines(); // ���� ���ڿ��� �� �� ��ȯ

	Text& append(const char* s);
	Text& append(const String& str);
	Text& append(const Text& text);

private:
	char* stringdata;
	int stringlength;
};