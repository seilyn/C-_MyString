#pragma once
#include <iostream>
class String
{
public:
	String();
	String(const char* s);
	String(const String& s);
	~String();

	String& assign(const String& str);
	String& assign(const char* s);
	String& append(const String& str);
	String& append(const char* s);

	String& operator+=(const String& str);
	String& operator+=(const char* s);
	String& operator=(const String& str);
	String& operator=(const char* s);

	//String 3 Level
	String operator+(const String& str);
	String operator+(const char* s);
	friend std::ostream& operator<<(std::ostream& os, const String& str);
	friend std::istream& operator>>(std::istream& is, String& str);
	
	////////////////

	const char print(bool show = true);
	// void Print();
	int length();
	int capacity();
	int size();

	char& operator[](int index);
	void shrink_to_fit();

private:
	char* string_data; // ���ڿ��� �����͸� ����Ű�� pointer ����
	int string_len; // ���ڿ��� ����
	int capacity_len;
};

