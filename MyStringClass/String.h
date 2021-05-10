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
	// String& operator=(const String& str);
	// String& operator=(const char* s);

	String& append(const String& str);
	//String& append(const char* s);
	// String& operator+=(const String& str);
	// String& operator+=(const char* s);

	void Print();
	int length();
	int capacity();
	int size();

private:
	char* string_data; // ���ڿ��� �����͸� ����Ű�� pointer ����
	int string_len; // ���ڿ��� ����
	int capacity_len;
};

