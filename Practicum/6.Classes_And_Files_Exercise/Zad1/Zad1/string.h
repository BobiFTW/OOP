#ifndef HEADER_H
#define HEADER_H

class String {

private:
	char* str;

public:
	String(const char* str);
	String(String const& str);
	String& operator= (const char*);
	String& operator= (const String& str);
	~String();
	String(String&& str);
	String& operator= (String&& str);
	char operator[](unsigned index);
	String operator+(const String& str) const;
	String operator+(const char* str) const;
};

String operator+(const char* lStr, const String& rStr);

#endif // !HEADER_H
