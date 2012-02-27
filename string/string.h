/*
 * Author      : Eli Gundry
 * Date        : 02/15/2012
 * Name        : string
 * Description : My own implementation of the string datatype's header file
 */

#ifndef CS33001_STRING_H
#define CS33001_STRING_H

#include <iostream>

#define default_size 128

class String 
{
public:
	/*
	 * Initalizes string to '\0'
	 * Ex: string str; 
	 */
	String();

	/*
	 * Initalizes string to a single char passed to it
	 * Ex: string str('a'); 
	 */
	String(const char);

	/*
	 * Initalizes string to a character array passed to it
	 * Ex: string str("It's over 9000!"); 
	 */
	String(const char[]);

	/*
	 * Destroys the dynamic string object
	 * Ex: none; 
	 */
	~String();

	/*
	 * Assignment operator for strings
	 * Ex: string str = "It's over 9000!"; 
	 */
	String operator=(const char);
	String operator=(const char[]);

	/*
	 * Tests equality between two strings
	 * Ex: str == str2; 
	 * Ex: str != str2; 
	 */
	bool operator==(const String&) const;
	bool operator!=(const String&) const;

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
	bool operator<(const String&) const; 
	bool operator<=(const String&) const; 
	bool operator>(const String&) const; 
	bool operator>=(const String&) const; 

	/*
	 * Adds two strings together
	 * Ex: str = str1 + str2; 
	 */
	String operator+(const String&);
	String operator+(const char[]);

	/*
	 * Adds string to current string
	 * Ex: str1 += str2; 
	 */
	String operator+=(const String&);

	/*
	 * Subtracts x number of chars from string
	 * Ex: str - 5; 
	 */
	String operator-(const int);
	String operator-=(const int);

	/*
	 * Subtracts a specified char from string
	 * Ex: str - '\n'; 
	 */
	String operator-(const char);
	String operator-=(const char);

	/*
	 * Subtracts specified string from string
	 * Ex: str - "this"; 
	 */
	String operator-(const String&);
	String operator-=(const String&);

	/*
	 * Multiples the contents of a string by integer
	 * Ex: str1 = str2 * 5; 
	 */
	String operator*(const int);

	/*
	 * Multiples the contents of the string and appends it to that string
	 * Ex: str1 *= 5; 
	 */
	String operator*=(const int);
	
	/*
	 * Outputs string with << operator
	 * Ex: std::cout << str1;  
	 */
	friend std::ostream& operator<<(std::ostream&, const String&);

	/*
	 * Inputs string from keyboard with >> operator
	 * Ex: std::cin >> str1; 
	 */
	friend std::istream& operator>>(std::istream&, const String&);

	/*
	 * Returns the length of the string
	 * Ex: str.length(); 
	 */
	int length() const;

	/*
	 * Returns the number of occurances of a char in a string
	 * Ex: str1.findchar(); 
	 */
	int findchar(const char) const;
	int findchar(const char, const int) const;

	/*
	 * Returns the number of occurances of a string inside of a string
	 * Ex: str1.findstr("this"); 
	 */
	int findstr(const String&) const;

	/*
	 * Reverses the content of a string
	 * Ex: str.reverse(); 
	 */
	String reverse() const;
	
	/*
	 * Zips two strings together, like a zipper
	 * Ex: str1.zip(str2) 
	 */
	String zip(const String&) const;

	/*
	 * Strips newlines from strings with optional replacement string
	 * Ex: str.strip_nl(); 
	 * Ex: str.strip_nl(". ");
	 */
	String strip_nl();
	String strip_nl(const String&);

	/*
	 * Repeats a string a specified number of times with optional seperator
	 * Ex: str1.repeat(5);
	 * Ex: str1.repeat(5, "\n"); 
	 */
	String repeat(const int);
	String repeat(const int, const String&);

	/*
	 * Returns extracted part of a string
	 * Ex: str1.substr(1);
	 * Ex: str1.substr(1, 3); 
	 */
	String substr(const int) const;
	String substr(const int, const int);

private:
	char *s;
	int capacity;
};

#endif 
