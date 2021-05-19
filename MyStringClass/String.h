#pragma once
#include <iostream>
class String
{
#pragma region 기본 생성자
public:
	String();
	String(const char* s);
	String(const String& s);
	~String();
#pragma endregion

#pragma region assign, append
	String& assign(const String& str);
	String& assign(const char* s);
	String& append(const String& str);
	String& append(const char* s);
#pragma endregion

#pragma region 연산자 오버로딩
	String& operator+=(const String& str);
	String& operator+=(const char* s);
	String& operator=(const String& str);
	String& operator=(const char* s);
	String operator+(const String& str);
	String operator+(const char* s);
	char& operator[](int index);
	friend std::ostream& operator<<(std::ostream& os, const String& str);
	friend std::istream& operator>>(std::istream& is, String& str);
#pragma endregion

#pragma region 부가 함수
	const char print(bool show = true);
	int length();
	int capacity();
	int size();
	void shrink_to_fit();
#pragma endregion

#pragma region 생성자용 부함수
	void init();
	void init(const char* in);
	void init(const String& in) noexcept;
#pragma endregion

private:
	char* string_data; // 문자열의 데이터를 가리키는 pointer 변수
	int string_len; // 문자열의 길이
	int capacity_len;
};

