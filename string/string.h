/*
 * Author      : Eli Gundry
 * Date        : 02/15/2012
 * Name        : String
 * Description : My own implementation of the string datatype's header file
 */

#ifndef CS33001_STRING_H
#define CS33001_STRING_H

#include <iostream>
#include <vector>

using std::istream;
using std::ostream;
using std::vector;

#define default_size 128

class String 
{
public:
	/*
	 * Initalizes string to '\0', with optional capacity
	 * Ex: String str;
	 * Ex: String str(50); 
	 */
	String(int size = default_size);

	/*
	 * Initalizes string to a single char passed to it with an optional capacity
	 * Ex: String str('a'); 
	 */
	String(const char, int size = 2);

	/*
	 * Initalizes string to specified size with char array with optional
	 * capacity
	 * Ex: String str("It's over 9000!", 30); 
	 */
	String(const char[], int size = default_size);
	
	/*
	 * Copies one string to another, with optional capacity
	 * Ex: String new_str(old_str);
	 * Ex: String new_str(old_str, old_str.length() * 2); 
	 */
	String(const String& str, int cap = default_size);
	

	/*
	 * Destroys the dynamic string object
	 * Ex: delete [] s; 
	 */
	~String();

	/*
	 * Assignment operator for strings
	 * Ex: String str = 'a'; 
	 * Ex: String str = "It's over 9000!"; 
	 */
	String operator=(String);

	/*
	 * Tests equality between two strings
	 * Ex: str == str2; 
	 * Ex: str != str2; 
	 */
	bool operator==(const String&) const;
	bool operator!=(const String& rhs) const { return !(*this == rhs); };

	/*
	 * Returns the character from the specified spot in the string
	 * Ex: str[3]; 
	 */
	char operator[](const int spot) const { return s[spot]; };
	char& operator[](const int spot) { return s[spot]; };

	/*
	 * Compares the values of the strings and returns bool
	 * Ex: str < str2; 
	 * Ex: str <= str2; 
	 * Ex: str > str2;
	 * Ex: str >= str2;
	 */
	bool operator<(const String&) const; 
	bool operator<=(const String& rhs) const { return (*this < rhs) || (*this == rhs); }; 
	bool operator>(const String& rhs) const { return rhs < *this; }; 
	bool operator>=(const String& rhs) const { return rhs <= *this; }; 

	/*
	 * Adds two strings together
	 * Ex: str = str1 + str2; 
	 * Ex: str1 += str2; 
	 */
	String operator+(const String&);
	String operator+=(const String& rhs) { return *this = *this + rhs; };

	/*
	 * Subtracts x number of chars from string
	 * Ex: str - 5; 
	 */
	String operator-(const int);
	String operator-=(const int x) { return *this = *this - x; };

	/*
	 * Subtracts a specified char from string
	 * Ex: str - '\n'; 
	 */
	String operator-(const char);
	String operator-=(const char ch) { return *this = *this - ch; };

	/*
	 * Subtracts specified string from string
	 * Ex: str - "this"; 
	 * Ex: str -= "this";
	 */
	String operator-(const String&);
	String operator-=(const String& str) { return *this = *this - str; };

	/*
	 * Multiples the contents of a string by integer
	 * Ex: str1 = str2 * 5; 
	 * Ex: str1 *= 5; 
	 */
	String operator*(const int);
	String operator*=(const int x) { return *this = *this * x; };

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
	 * Ex: str.buffCapacity(); 
	 */
	int buffCapacity() const { return capacity; };

	/*
	 * Returns the number of occurances of a char in a string
	 * Ex: str1.findchar(); 
	 */
	int findchar(const char, const int start = 0) const;

	/*
	 * Returns the number of occurances of a string inside of a string
	 * Ex: str1.findstr("this"); 
	 */
	int findstr(const String&) const;

	/*
	 * Returns the length of the string
	 * Ex: str.length(); 
	 */
	int length() const { return strLength; };

	/*
	 * Get's line of text with optional delimiter
	 * Ex: str.getline(); 
	 */
	istream& getline(istream&, String&, char delimiter = '\n');
	
	/*
	 * Increases the capacity of a string and copies it
	 * Ex: str.reallocate(50); 
	 */
	void reallocate(const int size = default_size);

	/*
	 * Repeats a string a specified number of times with optional seperator
	 * Ex: str1.repeat(5);
	 * Ex: str1.repeat(5, "\n"); 
	 */
	String repeat(const int x) { return *this * x; };
	String repeat(const int, const String&);

	/*
	 * Reverses the content of a string
	 * Ex: str.reverse(); 
	 */
	String reverse() const;
	
	/*
	 * Splits a string on a char and returns it as a vector
	 * Ex: str.split(); 
	 * Ex: str.split(' '); 
	 */
	vector<String> split();
	vector<String> split(const char);
	
	/*
	 * Strips newlines from strings with optional replacement string
	 * Ex: str.strip_nl(); 
	 * Ex: str.strip_nl(". ");
	 */
	String strip_nl() { return *this - '\n'; };
	String strip_nl(const String&);
	
	/*
	 * Returns extracted part of a string
	 * Ex: str1.substr(1);
	 * Ex: str1.substr(1, 3); 
	 */
	String substr(const int left = 0, int right = -1) const;
	
	/*
	 * Swaps two strings pointers
	 * Ex: str1.swap(str2); 
	 */
	void swap(String&);

	/*
	 * Zips two strings together, like a zipper
	 * Ex: str1.zip(str2) 
	 */
	String zip(const String&) const;

private:
	char *s;
	int capacity,
		strLength;
};

#endif 
