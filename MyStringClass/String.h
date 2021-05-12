#pragma once

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

	const char print(bool show = true);
	// void Print();
	int length();
	int capacity();
	int size();

	char& operator[](int index);
	void shrink_to_fit();
private:
	char* string_data; // 문자열의 데이터를 가리키는 pointer 변수
	int string_len; // 문자열의 길이
	int capacity_len;
};

