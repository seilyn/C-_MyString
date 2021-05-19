#pragma once
#include <iostream>
class String
{
#pragma region �⺻ ������
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

#pragma region ������ �����ε�
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

#pragma region �ΰ� �Լ�
	const char print(bool show = true);
	int length();
	int capacity();
	int size();
	void shrink_to_fit();
#pragma endregion

#pragma region �����ڿ� ���Լ�
	void init();
	void init(const char* in);
	void init(const String& in) noexcept;
#pragma endregion

private:
	char* string_data; // ���ڿ��� �����͸� ����Ű�� pointer ����
	int string_len; // ���ڿ��� ����
	int capacity_len;
};

