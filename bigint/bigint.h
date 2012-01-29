#ifndef CS33001_BIGINT_H
#define CS33001_BIGINT_H

#include <iostream>
using std::ostream;

const int MAX_SIZE = 100;

class bigint
{
public:
	// Initialize bigint to 0
	// Example: bigint number();
	bigint(); 
	// Initialize bigint to size x
	// Example: bigint number(30);
	bigint(int);
	// Initialize bigint to size x, where x is a character array
	// Example: bigint number("30");
	bigint(char[]);

	// Compares two bigints
	bool operator==(const bigint&);
	// Compares two bigints
	bool operator==(int);
	// Compares two bigints, where bigint is an array
	bool operator==(const char[]);
private:
	int digits[MAX_SIZE];
	// Creates bigint with value zero
	void zero();
};

#endif