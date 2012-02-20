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
string::string()
{
	s[0] = '\0';
}

/*
 * Initalizes string to a single char passed to it
 * Ex: string str('a'); 
 */
string::string(const char ch)
{
	s[0] = ch;
	s[1] = '\0';
}

/*
 * Initalizes string to a character array passed to it
 * Ex: string str("It's over 9000!"); 
 */
string::string(const char ch[])
{
	int i = 0;

	while (ch[i] != '\0') {
		s[i] = ch[i];
		++i;
	}

	s[i] = '\0';
}

/*
 * Assignment operator for strings
 * Ex: string str = "It's over 9000!"; 
 */
string string::operator=(const char ch[])
{
	string str(ch);
	return *this = str;
} 

/*
 * Compares a string to another string
 * Ex: str == other_str; 
 * Ex: str != other_str; 
 */
bool string::operator==(const string& rhs) const 
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
	} else {
		return false;
	}
}

bool string::operator!=(const string& rhs) const
{
	return !(*this == rhs);
}

/*
 * Returns the character from the specified spot in the string
 * Ex: str[3]; 
 */
char string::operator[](const int spot) const
{
	return s[spot];
}

char& string::operator[](const int spot)
{
	return s[spot];
}

/*
 * Compares the length of the strings and returns bool
 * Ex: str < str2; 
 * Ex: str <= str2; 
 * Ex: str > str2;
 * Ex: str >= str2;
 */
bool string::operator<(const string& rhs) const
{
	return length() < rhs.length();
}

bool string::operator<=(const string& rhs) const
{
	return length() <= rhs.length();
}

bool string::operator>(const string& rhs) const
{
	return length() > rhs.length();
}

bool string::operator>=(const string& rhs) const
{
	return length() >= rhs.length();
}

/*
 * Adds two strings together
 * Ex: str = str1 + str2; 
 */
string string::operator+(const string& rhs)
{
	string result = *this;

	for (int i = length(), x = 0, count = length() + rhs.length(); i <= count; ++i, ++x) {
		result.s[i] = rhs.s[x];
	}

	return result;
}

string string::operator+(const char rhs[])
{
	string str_rhs = rhs;
	return *this + str_rhs;
}

/*
 * Adds string to current string
 * Ex: str1 += str2; 
 */
string string::operator+=(const string& rhs)
{
	return *this = *this + rhs;
}

/*
 * Subtracts x number of chars from string
 * Ex: str - 5; 
 */
string string::operator-(const int x)
{
	int this_length = length();

	if (x <= 0) {
		return *this;
	} else if (x >= this_length) {
		return "";
	} else {
		string result;

		for (int i = 0; i < (this_length - x); ++i) {
			result += s[i];
		}

		return result;
	}
}

string string::operator-=(const int x)
{
	return *this = *this - x;
}

/*
 * Subtracts a specified char from string
 * Ex: str - '\n'; 
 */
string string::operator-(const char ch)
{
	string result;
	int this_length = length();

	for (int i = 0; i < this_length; ++i) {
		if (s[i] != ch) {
			result += s[i];
		}
	}

	return result;
}

string string::operator-=(const char ch)
{
	return *this = *this - ch;
}

/*
 * Subtracts specified string from string
 * Ex: str - "this"; 
 */
string string::operator-(const string& str)
{
	string result;
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

string string::operator-=(const string& str)
{
	return *this = *this - str;
}

/*
 * Multiples the contents of a string by integer
 * Ex: str1 = str2 * 5; 
 */
string string::operator*(const int x)
{
	if (x <= 0) {
		return "";
	} else if (x == 1) {
		return *this;
	} else {
		string result;

		for (int i = 1; i <= x; i++) {
			result += *this;
		}

		return result;
	}
}

/*
 * Multiples the contents of the string and appends it to that string
 * Ex: str1 *= 5; 
 */
string string::operator*=(const int x)
{
	return *this = *this * x;
}

/*
 * Outputs string with << operator
 * Ex: std::cout << str1;  
 */
std::ostream& operator<<(std::ostream& out, const string& str)
{
	out << str.s;
	return out;
}

/*
 * Inputs string from keyboard with >> operator
 * Ex: std::cin >> str1; 
 */
std::istream& operator>>(std::istream& in, const string& str)
{
	in >> str.s;
	return in;
}

/*
 * Returns the length of the string
 * Ex: str.length(); 
 */
int string::length() const
{
	int i = 0;

	while (s[i] != '\0') {
		++i;
	}

	return i;
}

/*
 * Returns the number of occurrences of a char in a string
 * Ex: str1.findchar(); 
 */
int string::findchar(const char ch) const
{
	int times = 0,
		this_length = length();

	for (int i = 0; i < this_length; ++i) {
		if (s[i] == ch) {
			++times;
		}
	}

	return times;
}

/*
 * Returns the number of occurances of a string inside of a string
 * Ex: str1.findstr("this"); 
 */
int string::findstr(const string& find) const
{
	int times = 0,
		this_length = length(),
		find_length = find.length();

	for (int i = 0, j = 0; i < this_length; ++i, j = 0) {
		while (s[i + j] == find.s[j] && j <= find_length) {
			++j;

			if (j == find_length) {
				++times;
				i = i + j;
			}
		}
	}

	return times;
}

/*
 * Reverses the content of a string
 * Ex: str.reverse(); 
 */
string string::reverse() const
{
	string result;

	for (int i = length(); i >= 0; --i) {
		result += s[i];
	}

	return result;
}

/*
 * Zips two strings together, like a zipper
 * Ex: str1.zip(str2) 
 */
string string::zip(const string& rhs) const
{
	string result;
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
string string::strip_nl()
{
	return *this - '\n';
}

string string::strip_nl(const string& replacement)
{
	string result;
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
string string::repeat(const int x)
{
	return *this * x;
}

string string::repeat(const int x, const string& seperator)
{
	string result;

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
string string::substr(const int start) const
{
	if (start == 0) {
		return *this;
	} else {
		string result;
		int this_length = length();

		for (int i = start; i < this_length; ++i) {
			result += s[i];
		}

		return result;
	}
}

string string::substr(const int start, const int end)
{
	if (start == 0) {
		return *this - (length() - end);
	} else {
		string result;

		for (int i = start; i < end; ++i) {
			result += s[i];
		}

		return result;
	}
}
