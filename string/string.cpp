/*
 * Author      : Eli Gundry
 * Date        : 02/15/2012
 * Name        : string
 * Description : My own implementation of the string datatype
 *
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

/*
 * Compares a string to another string
 * Ex: str == other_str; 
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
