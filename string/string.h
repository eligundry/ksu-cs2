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

	/*
	 * Subtracts x number of chars from string
	 * Ex: str - 5; 
	 */
	string operator-(const int);

	/*
	 * Subtracts a specified char from string
	 * Ex: str - '\n'; 
	 */
	string operator-(const char);

	/*
	 * Subtracts specified string from string
	 * Ex: str - "this"; 
	 */
	string operator-(const string&);

	/*
	 * Multiples the contents of a string by integer
	 * Ex: str1 = str2 * 5; 
	 */
	string operator*(const int);

	/*
	 * Multiples the contents of the string and appends it to that string
	 * Ex: str1 *= 5; 
	 */
	string operator*=(const int);

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
	 * Zips two strings together, like a zipper
	 * Ex: str1.zip(str2) 
	 */
	string zip(const string&);

	/*
	 * Strips newlines from strings with optional replacement string
	 * Ex: str.strip_nl(); 
	 * Ex: str.strip_nl(". ");
	 */
	string strip_nl();
	string strip_nl(const string&);

	/*
	 * Repeats a string a specified number of times with optional seperator
	 * Ex: str1.repeat(5);
	 * Ex: str1.repeat(5, "\n"); 
	 */
	string repeat(const int);
	string repeat(const int, const string&);

private:
	char s[MAX_SIZE];
};

#endif 
