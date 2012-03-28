/*
 * Author      : Eli Gundry
 * Date        : 02/15/2012
 * Name        : string
 * Description : My own implementation of the string datatype
 */

#include "string.h"

/*
 * Initalizes string to '\0', with optional capacity
 * Ex: String str(); 
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
 * Initializes string to a single char passed to it, with an optional capacity
 * Ex: String str('a'); 
 * Ex: String str('a', 30); 
 */
String::String(const char ch, const int size)
{
	capacity = size;
	s = new char[capacity];
	strLength = 1;
	s[0] = ch;
	s[1] = '\0';
}

/*
 * Initializes string to specified size with char array
 * Ex: String str("It's over 9000!"); 
 * Ex: String str("It's over 9000!", 30); 
 */
String::String(const char ch[], const int size)
{
	capacity = size;
	s = new char[capacity];
	
	do {
		int i = 0;
		
		for (; ch[i] != '\0'; ++i) {
			s[i] = ch[i];
		}
		
		strLength = i;
		
		if (capacity < strLength) {
			delete [] s;
			capacity *= 2;
			s = new char[capacity];
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
String::String(const String& str, const int cap)
{
	if (cap <= str.strLength)
		capacity = str.strLength + 1;
	else
		capacity = cap;
	
	s = new char[capacity];

	do {
		int i = 0;
		
		for (; str[i] != '\0'; ++i) {
			s[i] = str[i];
		}
		
		strLength = i;

	} while (capacity < strLength);
	
	s[strLength] = '\0';
}

/*
 * Destroys the dynamic string object
 * Ex: delete [] s; 
 */
String::~String()
{
	strLength = 0;
	delete [] s;
}

/*
 * Assignment operator for strings
 * Ex: String str = 'a'; 
 * Ex: String str = "It's over 9000!"; 
 */
String String::operator=(String rhs)
{
	swap(rhs);
	return *this;
}

/*
 * Compares a string to another string
 * Ex: str1 == str2; 
 * Ex: str1 != str2; 
 */
bool String::operator==(const String& rhs) const 
{
	if (strLength == rhs.strLength) {
		
		for (int i = 0; s[i] != '\0' && rhs[i] != '\0'; ++i) {
			if (s[i] != rhs[i]) {
				return false;
			}
		}

		return true;
	}

	return false;
}

/*
 * Compares the length of the strings and returns bool
 * Ex: str1 < str2; 
 * Ex: str1 <= str2; 
 * Ex: str1 > str2;
 * Ex: str1 >= str2;
 */
bool String::operator<(const String& rhs) const
{
    bool lessThan = false;
    int i = 0;
	
	for (; (s[i] != '\0') && (rhs[i] != '\0'); ++i) {
		if (s[i] > rhs[i]) return false;
        if (s[i] < rhs[i]) lessThan = true;
	}

    if (lessThan && (s[i] == '\0') && (rhs[i] == '\0')) return true;
    if (lessThan && (rhs[i] == '\0')) return true;
    if (!lessThan && (s[i] == '\0') && (rhs[i] == '\0')) return false;
    if (s[i] == '\0') return true;
    return false;
}

/*
 * Adds two strings together
 * Ex: str = str1 + str2; 
 */
String String::operator+(const String& rhs)
{
	int i = strLength;
	String result(*this, i + rhs.strLength + 1);

	for (int j = 0; rhs[j] != '\0'; ++i, ++j) {
		result[i] = rhs[j];
	}

	return (result.strLength = i, result[i] = '\0', result);
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
	} else if (x >= strLength) {
		String result;
		return result;
	} else {
		String result(strLength - (x + 1));

		for (int i = 0; i < (strLength - x); ++i) {
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
	String result(strLength + 1);

	for (int i = 0; i < strLength; ++i) {
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
	String result(strLength + 1);
	int i = 0;

	for (int j = 0; i < strLength; ++i, j = 0) {
		while (s[i + j] == rhs.s[j] && j <= rhs.strLength) {
			++j;

			if (j == rhs.strLength) {
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
		String result;
		return result;
	} else if (x == 1) {
		return *this;
	} else {
		String result(*this, (strLength * x) + 1);

		for (int i = 1; i < x; ++i) {
			result += *this;
		}

		return result;
	}
}

/*
 * Outputs string with << operator
 * Ex: std::cout << str1;  
 */
ostream& operator<<(ostream& out, const String& str)
{
	out << str.s;
	return out;
}

/*
 * Inputs string from keyboard with >> operator
 * Ex: std::cin >> str1; 
 */
istream& operator>>(istream& in, const String& str)
{
	in >> str.s;
	return in;
}

/*
 * Returns the number of occurrences of a char in a string
 * Ex: str1.findchar('a'); 
 * Ex: str1.findchar('a', 3); 
 */
int String::findchar(const char ch, const int start) const
{
	String temp = substr(start);
	int first_index = -1;

	for (int i = 0; i < strLength; ++i) {
		if (temp[i] == ch) {
			return first_index = i + start;
		}
	}

	return first_index;
}

/*
 * Returns the number of occurances of a string inside of a string
 * Ex: str1.findstr("this"); 
 */
int String::findstr(const String& find) const
{
	int times = 0;

	if (strLength >= find.strLength) {
		for (int i = 0, j = 0; i < strLength; ++i, j = 0) {
			while (s[i + j] == find.s[j] && j <= find.strLength) {
				++j;

				if (j == find.strLength) {
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
void String::reallocate(const int size)
{
	String temp(*this, size);
	swap(temp);
}

/*
 * Repeats a string a specified number of times with optional seperator
 * Ex: str1.repeat(5);
 * Ex: str1.repeat(5, "\n"); 
 */
String String::repeat(const int x, const String& seperator)
{
	String result(((strLength + seperator.strLength) * x) + 1);

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
	int i = strLength;
	String result(i + 1);

	for (; i >= 0; --i) {
		result += s[i];
	}

	return result;
}

/*
 * Splits a string on a char and returns it as a vector
 * Ex: str.split(); 
 * Ex: str.split(' '); 
 */
vector<String> String::split()
{
	vector<String> result;
	
	for (int i = 0; s[i] != '\0'; ++i) {
		result.push_back(s[i]);
	}
	
	return result;
}

vector<String> String::split(const char ch)
{
	vector<String> result;
	String temp;
	
	for (int i = 0; s[i] != '\0'; ++i) {
		if (s[i] != ch) {
			temp += s[i];
		} else {
			result.push_back(temp);
			temp = s[++i];
		}
	}
	
	return (result.push_back(temp), result);
} 

/*
 * Strips newlines from strings
 * Ex: str.strip_nl(); 
 * Ex: str.strip_nl(". ");
 */
String String::strip_nl(const String& replacement)
{
	String result;

	for (int i = 0; i < strLength; ++i) {
		if (s[i] != '\n')
			result += s[i];
		else
			result += replacement;
	}

	return result;
}

/*
 * Returns extracted part of a string
 * Ex: str1.substr(1);
 * Ex: str1.substr(1, 3); 
 */
String String::substr(const int left, int right) const
{
	if (right < 0 || right > strLength) {
		right = strLength;
	}

	if (left == 0) {
		String result = *this;
		return result - (strLength - right);
	} else {
		String result(strLength + 1);

		for (int i = left; i < right + 1; ++i) {
			result += s[i];
		}

		return result;
	}
}

/*
 * Swaps two strings pointers
 * Ex: str1.swap(str2); 
 */
void String::swap(String& str)
{
	char *temp = s;
	s = str.s;
	str.s = temp;
	
	capacity = (capacity + str.capacity) - (str.capacity = capacity);
	strLength = (strLength + str.strLength) - (str.strLength = strLength);
}

/*
 * Converts string to integer
 * Ex: str1.to_i(); 
 */
int String::to_i()
{
	int startindex = strLength - 1;

	if (s[startindex] == '-') {
		return 0;
	}
	
	int value = 0,
		tenspot = 1;
	
	for (int i = startindex; i >= 0; --i) {
		value += (int(s[i] - int('0')) * tenspot);
		tenspot *= 10;
	}	
	
	return value;
}

/*
 * Zips two strings together, like a zipper
 * Ex: str1.zip(str2) 
 */
String String::zip(const String& rhs) const
{
	String result(strLength + rhs.strLength + 1);
	int i = 0;

	do {
		if (i <= strLength)
			result += s[i]; 

		if (i <= rhs.strLength)
			result += rhs[i];

		++i;
	} while (i <= result.capacity - 1);

	return result;
}

/*
 * Get's line of text with optional delimiter
 * Ex: str.getline(); 
 */
String getline(istream& in)
{
	String line;
	char ch;
	
	for (int i = (in.get(ch), 0); (ch != '\n' && !in.fail()); ++i) {
		if (i == line.length()) {
			line.reallocate(line.length() * 2);
		}
		
		line += ch;
	}
	
	return line;
}
