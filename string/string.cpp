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
string::string(const char str[])
{
	int i = 0;

	while (str[i] != '\0') {
		s[i] = str[i];
		++i;
	}

	s[i] = '\0';
}

string string::operator=(const char str[])
{
	int i = 0;

	while (str[i] != '\0') {
		s[i] = str[i];
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
	string str_rhs = rhs,
		   result = *this;

    for (int i = length(), x = 0, count = length() + str_rhs.length(); i <= count; ++i, ++x) {
		result.s[i] = str_rhs.s[x];
    }

	return result;
}

/*
 * Adds string to current string
 * Ex: str1 += str2; 
 */
string string::operator+=(const string& rhs)
{
    for (int i = length(), x = 0, count = length() + rhs.length(); i <= count; ++i, ++x) {
		s[i] = rhs.s[x];
    }

	return *this;
}

/*
 * Subtracts x number of chars from string
 * Ex: str - 5; 
 */
string string::operator-(const int x)
{
	if (x <= 0) {
		return *this;
	} else if (x >= length()) {
		return "";
	} else {
		string result;

		for (int i = 0; i < (length() - x); ++i) {
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

    for (int i = 0; i < length(); ++i) {
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

	for (int i = 0, j = 0; i < length(); ++i, j = 0) {
		while (s[i + j] == str.s[j] && j <= str.length()) {
			++j;

			if (j == str.length()) {
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
ostream& operator<<(ostream& out, string& str)
{
	for (int i = 0; i < str.length(); ++i) {
		out << str.s[i];
	}

	return out;
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
 * Reverses the content of a string
 * Ex: str.reverse(); 
 */
string string::reverse()
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
string string::zip(const string& rhs)
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
string string::substr(const int start)
{
	if (start == 0) {
		return *this;
	} else {
		string result;

		for (int i = start; i < length(); ++i) {
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
