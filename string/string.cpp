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
 * Multiples the contents of a string by integer
 * Ex: str1 = str2 * 5; 
 */
string string::operator*(int x)
{
	switch (x) {
		case 0:
			return "";
			break;
		case 1:
			return *this;
			break;
		default:
			string result;

			for (int i = 1; i <= x; i++) {
				result += *this;
			}

			return result;
	}
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
 * Ex: str.nl_strip(); 
 */
string string::strip_nl()
{
	string result;

	for (int i = 0; i < length(); ++i) {
		if (s[i] != '\n') {
			result += s[i];
		}
	}

	return result;
}

