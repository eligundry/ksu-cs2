/*
 * Author      : Eli Gundry
 * Date        : 02/15/2012
 * Name        : string
 * Description : My own implementation of the string datatype
 */

#include "string.h"

/*
 * Initalizes string to '\0'
 * Ex: string str(); 
 */
String::String()
{
	s = new char[default_size]; 
	capacity = default_size;
	strLength = 0;
	s[0] = '\0';
}

/*
 * Initalizes string to a specified size
 * Ex: String str(50); 
 */
String::String(const int size)
{
	capacity = size;
	s = new char[capacity];
	strLength = 0;
	s[0] = '\0';
}

/*
 * Initalizes string to a single char passed to it
 * Ex: string str('a'); 
 */
String::String(const char ch)
{
	s = new char[default_size];
	capacity = default_size;
	strLength = 1;
	s[0] = ch;
	s[1] = '\0';
}

/*
 * Initalizes string to a character array passed to it
 * Ex: string str("It's over 9000!"); 
 */
String::String(const char ch[])
{
	capacity = default_size;
	s = new char[capacity];
	
	do {
		s = new char[capacity];

		int i = 0;

		while (ch[i] != '\0') {
			s[i] = ch[i];
			++i;
		}
		
		strLength = i;
		
		if (capacity < strLength) {
			delete [] s;
			capacity *= 2;
			strLength = capacity;
		}
		
	} while (capacity < strLength);
	
	s[strLength] = '\0';
}

/*
 * Initalizes string to specified size with char array
 * Ex: String str("It's over 9000!", 30); 
 */
String::String(const char ch[], const int size)
{
	capacity = size;
	s = new char[capacity];
	
	do {
		s = new char[capacity];
		
		int i = 0;
		
		while (ch[i] != '\0') {
			s[i] = ch[i];
			++i;
		}
		
		strLength = i;
		
		if (capacity < strLength) {
			delete [] s;
			capacity *= 2;
			strLength = capacity;
		}
		
	} while (capacity < strLength);
	
	s[strLength] = '\0';
}

/*
 * Copies one string to another, with optional capacity
 * Ex: String new_str(old_str);
 * Ex: String new_str(old_str, old_str.length() * 2); 
 */
String::String(const String& str)
{
	capacity = default_size;
	
	do {
		s = new char[capacity];
		int i = 0;
		
		while (str.s[i] != '\0') {
			s[i] = str.s[i];
			++i;
		}
		
		strLength = i;
		
		if (capacity < strLength) {
			delete [] s;
			capacity *= 2;
			strLength = capacity;
		}
	} while (capacity < strLength);
	
	s[strLength] = '\0';
}

String::String(const String& str, const int cap)
{
	capacity = cap;

	do {
		s = new char[capacity];
		int i = 0;
		
		while (str.s[i] != '\0') {
			s[i] = str.s[i];
			++i;
		}
		
		strLength = i;
		
		if (capacity < strLength) {
			delete [] s;
			capacity *= 2;
			strLength = capacity;
		}
	} while (capacity < strLength);
	
	s[strLength] = '\0';
}

/*
 * Destroys the dynamic string object
 * Ex: none; 
 */
String::~String()
{
	strLength = 0;
	delete [] s;
}

/*
 * Assignment operator for strings
 * Ex: string str = 'a'; 
 * Ex: string str = "It's over 9000!"; 
 */
String String::operator=(const char rhs[])
{
	String str(rhs);
	return *this = str;
} 

String String::operator=(const String& rhs)
{
	int i = 0;
	delete [] s;

	capacity = rhs.capacity;
	s = new char[capacity];
	strLength = rhs.length();
	
	while (rhs.s[i] != '\0') {
		s[i] = rhs.s[i];
		++i;
	}
	
	s[i] = '\0';
	
	return *this;
}

/*
 * Compares a string to another string
 * Ex: str == other_str; 
 * Ex: str != other_str; 
 */
bool String::operator==(const String& rhs) const 
{
	if (length() == rhs.length()) {
		int i = 0;
		
		while (s[i] != '\0' && rhs.s[i] != '\0') {
			if (s[i] != rhs.s[i]) {
				return false;
			}
			++i;
		}

		return true;
	}

	return false;
}

bool String::operator==(const char ch[]) const
{
	String str_ch(ch);
	return *this == str_ch;
}

/*
 * Compares the length of the strings and returns bool
 * Ex: str < str2; 
 * Ex: str <= str2; 
 * Ex: str > str2;
 * Ex: str >= str2;
 */
bool String::operator<(const String& rhs) const
{
    bool lessThan = false;
    int i = 0;

    while ( (s[i] != '\0') && (rhs.s[i] != '\0') ) {
		if (s[i] > rhs.s[i]) return false;
        if (s[i] < rhs.s[i]) lessThan = true;
        ++i;
    }

    if (lessThan && (s[i] == '\0') && (rhs.s[i] == '\0')) return true;
    if (lessThan && (rhs.s[i] == '\0')) return true;
    if (!lessThan && (s[i] == '\0') && (rhs.s[i] == '\0')) return false;
    if (s[i] == '\0') return true;
    return false;
}

/*
 * Adds two strings together
 * Ex: str = str1 + str2; 
 */
String String::operator+(const String& rhs)
{
	String result(length() + rhs.length() + 1);
	int i = 0,
		j = 0;
	
	while (s[i] != '\0') {
		result.s[i] = s[i];
		++i;
	}

	while (rhs.s[j] != '\0') {
		result.s[i] = rhs.s[j];
		++i;
		++j;
	}

	result.strLength = i;
	
	result.s[i] = '\0';
	
	return result;
} 

String String::operator+(const char rhs[])
{
	String str_rhs(rhs);
	return *this + str_rhs;
}

/*
 * Subtracts x number of chars from string
 * Ex: str - 5; 
 * Ex: str -= "this";
 */
String String::operator-(const int x)
{
	if (x <= 0) {
		return *this;
	} else if (x >= length()) {
		return "";
	} else {
		String result;

		for (int i = 0; i < (length() - x); ++i) {
			result += s[i];
		}

		return result;
	}
}

/*
 * Subtracts a specified char from string
 * Ex: str - '\n'; 
 */
String String::operator-(const char ch)
{
	String result;

	for (int i = 0; i < length(); ++i) {
		if (s[i] != ch) {
			result += s[i];
		}
	}

	return result;
}

/*
 * Subtracts specified string from string
 * Ex: str - "this"; 
 */
String String::operator-(const String& rhs)
{
	String result;
	int i = 0;

	for (int j = 0; i < length(); ++i, j = 0) {
		while (s[i + j] == rhs.s[j] && j <= rhs.length()) {
			++j;

			if (j == rhs.length()) {
				i = i + j;
			}
		}

		result += s[i];
	}
	
	return result;
}

/*
 * Multiples the contents of a string by integer
 * Ex: str1 = str2 * 5; 
 */
String String::operator*(const int x)
{
	if (x <= 0) {
		return "";
	} else if (x == 1) {
		return *this;
	} else {
		String result;

		for (int i = 1; i <= x; ++i) {
			result += *this;
		}

		return result;
	}
}

/*
 * Outputs string with << operator
 * Ex: std::cout << str1;  
 */
std::ostream& operator<<(std::ostream& out, const String& str)
{
	out << str.s;
	return out;
}

/*
 * Inputs string from keyboard with >> operator
 * Ex: std::cin >> str1; 
 */
std::istream& operator>>(std::istream& in, const String& str)
{
	in >> str.s;
	return in;
}

/*
 * Returns the number of occurrences of a char in a string
 * Ex: str1.findchar('a'); 
 * Ex: str1.findchar('a', 3); 
 */
int String::findchar(const char ch) const
{
	int first_index = -1;

	for (int i = 0; i < length(); ++i) {
		if (s[i] == ch) {
			return first_index = i;
		}
	}

	return first_index;
}

int String::findchar(const char ch, const int start) const
{
	String temp = substr(start);
	return temp.findchar(ch);
}

/*
 * Returns the number of occurances of a string inside of a string
 * Ex: str1.findstr("this"); 
 */
int String::findstr(const String& find) const
{
	int times = 0;

	if (length() >= find.length()) {
		for (int i = 0, j = 0; i < length(); ++i, j = 0) {
			while (s[i + j] == find.s[j] && j <= find.length()) {
				++j;

				if (j == find.length()) {
					++times;
					i = i + j;
				}
			}
		}
	}

	return times;
}

/*
 * Increases the capacity of a string and copies it
 * Ex: str.reallocate(50); 
 */
String String::reallocate(const int size)
{
	String result(*this, size);
	
	delete [] s;
	
	int i = 0;
	capacity = result.capacity;
	s = new char[capacity];
	
	while (result[i] != '\0') {
		s[i] = result[i];
		++i;
	}
	
	strLength = i;
	s[i + 1] = '\0';
	
	return *this;
}

/*
 * Repeats a string a specified number of times with optional seperator
 * Ex: str1.repeat(5);
 * Ex: str1.repeat(5, "\n"); 
 */
String String::repeat(const int x, const String& seperator)
{
	String result;

	for (int i = 0; i < x; ++i) {
		result += *this + seperator;
	}

	return result;
}

/*
 * Reverses the content of a string
 * Ex: str.reverse(); 
 */
String String::reverse() const
{
	String result(length() + 1);
	result.strLength = length();

	for (int i = result.strLength; i >= 0; --i) {
		result += s[i];
	}

	return result;
}

/*
 * Strips newlines from strings
 * Ex: str.strip_nl(); 
 * Ex: str.strip_nl(". ");
 */
String String::strip_nl(const String& replacement)
{
	String result;

	for (int i = 0; i < length(); ++i) {
		if (s[i] != '\n') {
			result += s[i];
		} else {
			result += replacement;
		}
	}

	return result;
}

/*
 * Returns extracted part of a string
 * Ex: str1.substr(1);
 * Ex: str1.substr(1, 3); 
 */
String String::substr(const int start) const
{
	if (start == 0) {
		return *this;
	} else {
		String result(length() + 1);
		result.strLength = 0;

		for (int i = start; i < length(); ++i, ++result.strLength) {
			result += s[i];
		}

		return result;
	}
}

String String::substr(const int start, const int end)
{
	if (start == 0) {
		return *this - (length() - end);
	} else {
		String result(length() + 1);

		for (int i = start; i < end; ++i) {
			result += s[i];
		}

		return result;
	}
}

/*
 * Zips two strings together, like a zipper
 * Ex: str1.zip(str2) 
 */
String String::zip(const String& rhs) const
{
	String result(length() + rhs.length() + 1);
	int i = 0;

	do {
		if (i <= length())
			result += s[i]; 

		if (i <= rhs.length())
			result += rhs[i];

		++i;
	} while (i <= result.capacity - 1);

	return result;
}
