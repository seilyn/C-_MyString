#pragma once
class MyString
{
public:
	MyString(char c);
	MyString(const char* str);
	MyString(const MyString& str);
	
	int strLen(const char* str);
	void Print() const;
	void Println() const;
	int Length() const;
	~MyString();
private:
	char* stringContent; // 문자열 데이터를 가리키는 포인터
	int stringLength; // 문자열 길이
};
MyString::MyString(char c)
{
	stringContent = new char[1];
	stringContent[0] = c;
	stringLength = 1;
}

MyString::MyString(const char* str)
{
	stringLength = strLen(str);
	stringContent = new char[stringLength];

	for (int i = 0; i != stringLength; i++)
	{
		stringContent[i] = str[i];
	}
}
MyString::MyString(const MyString& str)
{
	stringLength = str.stringLength;
	stringContent = new char[stringLength];
	for (int i = 0; i != stringLength; i++)
	{
		stringContent[i] = str.stringContent[i];
	}
}

MyString::~MyString() { delete[] stringContent; }

void MyString::Print() const
{
	for (int i = 0; i != stringLength; i++)
	{
		std::cout << stringContent[i];
	}
}

void MyString::Println() const
{
	for (int i = 0; i != stringLength; i++)
	{
		std::cout << stringContent[i];
	}
	std::cout << std::endl;
}

int MyString::Length() const
{
	return stringLength;
}
int MyString::strLen(const char* str)
{
	int i;
	for (i = 0;; i++)
	{
		if (str[i] == NULL) break;
	}
	return i;
}