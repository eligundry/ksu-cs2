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
	s[0] = '\0';
}

/*
 * Initalizes string to a specified size
 * Ex: String str(50); 
 */
String::String(const int size)
{
	s = new char[size];
	s[0] = '\0';
}

/*
 * Initalizes string to a single char passed to it
 * Ex: string str('a'); 
 */
String::String(const char ch)
{
	s = new char[2];
	s[0] = ch;
	s[1] = '\0';
}

/*
 * Initalizes string to a character array passed to it
 * Ex: string str("It's over 9000!"); 
 */
String::String(const char ch[])
{
	s = new char[default_size];

	int i = 0;

	while (ch[i] != '\0') {
		s[i] = ch[i];
		++i;
	}

	s[i] = '\0';
}

/*
 * Assignment operator for strings
 * Ex: string str = 'a'; 
 * Ex: string str = "It's over 9000!"; 
 */
String String::operator=(const char ch)
{
	String str(ch);
	return *this = str;
} 

String String::operator=(const char ch[])
{
	String str(ch);
	return *this = str;
} 

/*
 * Compares a string to another string
 * Ex: str == other_str; 
 * Ex: str != other_str; 
 */
bool String::operator==(const String& rhs) const 
{
	int i = 0;

	while (s[i] != '\0') {
		if (s[i] != rhs.s[i]) {
			return false;
		}
		++i;
	}

	if (rhs.s[i] == '\0') {
		return true;
	}

	return false;
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
	String result;
	int i,
		lhs_length = length(),
		rhs_length = rhs.length();

	for (i = 0; i < lhs_length; ++i) {
		result.s[i] = s[i];
	}

	for (int j = 0; i < lhs_length + rhs_length; ++j, ++i) {
		result.s[i] = rhs.s[j];
	}

	return result;
} 

String String::operator+(const char rhs[])
{
	String str_rhs = rhs;
	return *this + str_rhs;

}

/*
 * Subtracts x number of chars from string
 * Ex: str - 5; 
 * Ex: str -= "this";
 */
String String::operator-(const int x)
{
	int this_length = length();

	if (x <= 0) {
		return *this;
	} else if (x >= this_length) {
		return "";
	} else {
		String result;

		for (int i = 0; i < (this_length - x); ++i) {
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
	int this_length = length();

	for (int i = 0; i < this_length; ++i) {
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
String String::operator-(const String& str)
{
	String result;
	int lhs_length = length(),
		rhs_length = str.length();

	for (int i = 0, j = 0; i < lhs_length; ++i, j = 0) {
		while (s[i + j] == str.s[j] && j <= rhs_length) {
			++j;

			if (j == rhs_length) {
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
 * Returns the length of the string
 * Ex: str.length(); 
 */
int String::length() const
{
	int i = 0;

	while (s[i] != '\0') {
		++i;
	}

	return i;
}

/*
 * Returns the number of occurrences of a char in a string
 * Ex: str1.findchar('a'); 
 * Ex: str1.findchar('a', 3); 
 */
int String::findchar(const char ch) const
{
	int first_index = -1,
		this_length = length();

	for (int i = 0; i < this_length; ++i) {
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
	int times = 0,
		this_length = length(),
		find_length = find.length();

	if (!(this_length < find_length)) {
		for (int i = 0, j = 0; i < this_length; ++i, j = 0) {
			while (s[i + j] == find.s[j] && j <= find_length) {
				++j;

				if (j == find_length) {
					++times;
					i = i + j;
				}
			}
		}
	}

	return times;
}

/*
 * Reverses the content of a string
 * Ex: str.reverse(); 
 */
String String::reverse() const
{
	String result;

	for (int i = length(); i >= 0; --i) {
		result += s[i];
	}

	return result;
}

/*
 * Zips two strings together, like a zipper
 * Ex: str1.zip(str2) 
 */
String String::zip(const String& rhs) const
{
	String result;
	int lhs_count = length() - 1,
		rhs_count = rhs.length() - 1,
		i = 0;

	do {
		if (i <= lhs_count)
			result += s[i]; 

		if (i <= rhs_count)
			result += rhs.s[i];

		++i;
	} while (i <= (lhs_count + rhs_count));

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
	int this_length = length();

	for (int i = 0; i < this_length; ++i) {
		if (s[i] != '\n') {
			result += s[i];
		} else {
			result += replacement;
		}
	}

	return result;
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
 * Returns extracted part of a string
 * Ex: str1.substr(1);
 * Ex: str1.substr(1, 3); 
 */
String String::substr(const int start) const
{
	if (start == 0) {
		return *this;
	} else {
		String result;
		int this_length = length();

		for (int i = start; i < this_length; ++i) {
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
		String result;

		for (int i = start; i < end; ++i) {
			result += s[i];
		}

		return result;
	}
}
