/*
 * Author      : Eli Gundry
 * Date        : 01/25/2021 
 * Name        : bigint
 * Description : Creates bigger integer datatype, bigint
 * Link        : http://classes.cs.kent.edu/courses/cs33001_lab/svn/Labs/Lab_02/index.html
 *
 */

#include "bigint.h"

// Creates bigint with value 0
void bigint::zero()
{
	for (int i = 0; i < MAX_SIZE; ++i) {
		digits[i] = 0;
	}
}

// Initializes bigint to 0
bigint::bigint()
{
	zero();
}

// Initializes bigint to whatever number you pass to it
bigint::bigint(int x)
{
	zero();

	for (int i = 0; x != 0; ++i) {
		digits[i] = x % 10;
		x /= 10;
	}
}

// Initalizes bigint to x, where x is a string
bigint::bigint(const char x[])
{
	zero();

	for (int i = 0, y = (strlen(x) - 1); x[i] != '\0'; ++i, --y) {
		digits[y] = (int(x[i]) - int('0'));
	}
}

bool bigint::operator==(const bigint& x)
{
	for (int i = 0; i < MAX_SIZE; i++) {
		if (x.digits[i] != digits[i]) return false;
	}

	return true;
}

bool bigint::operator==(int x)
{
	for (int i = 0; x != 0; ++i) {
		if (digits[i] != x % 10) return false;
		x /= 10;
	}

	return true;
}

bool bigint::operator==(const char x[])
{
	for (int i = 0, y = (strlen(x) - 1); x[i] != '\0'; ++i, --y) {
		if (digits[y] != int(x[i]) - int('0')) return false;
	}

	return true;
}

void bigint::output(ostream& out) const
{
	int i = MAX_SIZE,
		j = 0;

	do {
		--i;
	} while(digits[i] == 0);

	do {
		if (j % 80 != 0)
			out << digits[i]; 
		else
			out << std::endl << digits[i];

		--i;
		++j;
	} while(i >= 0);
}

ostream& operator<<(ostream& out, bigint& num)
{
	int i = MAX_SIZE,
		j = 0;

	do {
		--i;
	} while(num.digits[i] == 0);

	do {
		if (j % 80 != 0)
			out << num.digits[i]; 
		else
			out << std::endl << num.digits[i];

		--i;
		++j;
	} while(i >= 0);

	return out;
}

// Adds two bigints together with the add operator
bigint bigint::operator+(bigint right)
{
	int i = 0,
		temp = 0,
		temp2 = 0;

	while (i < MAX_SIZE) {
		temp = right.digits[i] + digits[i] + temp;
		temp2 = temp % 10;
		temp /= 10;
		right.digits[i] = temp2;
		++i;
	}

	return right;
}

// Multiples bigint by other bigitns
bigint bigint::operator*(const bigint& rhs)
{
	bigint partial,
		   result;

	for (int i = 0; i < MAX_SIZE; ++i) {
		partial = *this;
		partial.times_single_digit(rhs.digits[i]);
		partial.times_10(i);
		result = result + partial;
	}

	return result;
}

// Multiples bigint by powers of 10
void bigint::times_10(int x)
{
	for (int i = (MAX_SIZE - 1); i >= 0 ; --i) {
		digits[i] = digits[i - x];
	}

	for (int i = (x - 1); i >= 0; --i) {
		digits[i] = 0;
	}
}

// Multiples bigint by a single number 
void bigint::times_single_digit(const int x)
{
	int spot_value = 0,
		carry = 0;

	for (int i = 0; i < MAX_SIZE; ++i) {
		spot_value = ((x * digits[i]) + carry) % 10;
		carry = ((x * digits[i]) + carry) / 10;
		digits[i] = spot_value;
	}
}

// Get's digit from bigint specified spot
int bigint::operator[](const int spot)
{
	return digits[spot];
}

istream& operator>>(istream& in, bigint& num)
{
	int i = 0;
	char next,
		 temp[MAX_SIZE];

	in >> next;

	while (next != ';' && !in.eof()) {
		temp[i] = next;
		in >> next;
		++i;
	}

	temp[i] = 0;
	num = bigint(temp);

	return in;
}
