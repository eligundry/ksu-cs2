#ifndef CS33001_BIGINT_H
#define CS33001_BIGINT_H

#include <iostream>
#include <cstring>
#include <cmath>
using std::ostream;
using std::istream;

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
	bigint(const char[]);

	// Compares two bigints
	bool operator==(const bigint&);
	// Compares bigint to integer
	bool operator==(int);
	// Compares two bigints, where bigint is an array
	bool operator==(const char[]);

	// Adds two bigints together
	bigint operator+(bigint);
	// Multiplies bigint by powers of 10
	bigint times_10(const int);
	// Multiples bigint by another bigint
	bigint operator*(const bigint&);

	// Overloads the [] operator to return the digit at that index
	// Example: int digit = number[0];
	int operator[](const int);

	// Outputs bigint with 80 digits per line
	void output(ostream&) const;

	// Outputs bigint with out operator
	friend ostream& operator<<(ostream&, bigint&);

	// Inputs bigint operator with the input operator
	friend istream& operator>>(istream&, bigint&);
private:
	int digits[MAX_SIZE];
	// Creates bigint with value zero
	void zero();
};

#endif
