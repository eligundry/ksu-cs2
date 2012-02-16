/*
 * Author      : Eli Gundry
 * Date        : 02/15/2012
 * Name        : string
 * Description : My own implementation of the string datatype's header file
 *
 */

#ifndef CS33001_STRING_H
#define CS33001_STRING_H

#include <iostream>

const int MAX_SIZE = 1000;

class string 
{
public:
	/*
	 * Initalizes string to '\0'
	 * Ex: string str; 
	 */
	string();

	/*
	 * Initalizes string to a single char passed to it
	 * Ex: string str('a'); 
	 */
	string(const char ch);

	/*
	 * Initalizes string to a character array passed to it
	 * Ex: string str("It's over 9000!"); 
	 */
	string(const char[]);

	/*
	 * Assignment operator for strings
	 * Ex: string str = "It's over 9000!"; 
	 */
	string operator=(const char[]);

	/*
	 * Tests equality between two strings
	 * Ex: str == str2; 
	 * Ex: str != str2; 
	 */
	bool operator==(const string&) const;
    bool operator!=(const string&) const;

	/*
	 * Returns the character from the specified spot in the string
	 * Ex: str[3]; 
	 */
	char operator[](const int) const;
	char& operator[](const int);

	/*
	 * Returns the length of the string
	 * Ex: str.length(); 
	 */
	int length() const;

	/*
	 * Reverses the content of a string
	 * Ex: str.reverse(); 
	 */
	string reverse();

	/*
	 * Compares the length of the strings and returns bool
	 * Ex: str < str2; 
	 * Ex: str <= str2; 
	 * Ex: str > str2;
	 * Ex: str >= str2;
	 */
	bool operator<(const string&) const; 
	bool operator<=(const string&) const; 
	bool operator>(const string&) const; 
	bool operator>=(const string&) const; 

	/*
	 * Adds two strings together
	 * Ex: str = str1 + str2; 
	 */
	string operator+(const string&);
	string operator+(const char[]);

	/*
	 * Adds string to current string
	 * Ex: str1 += str2; 
	 */
	string operator+=(const string&);
	string operator+=(const char[]);

	/*
	 * Multiples the contents of a string by integer
	 * Ex: str1 = str2 * 5; 
	 */
	string operator*(const int);

private:
	char s[MAX_SIZE];
};

#endif 
