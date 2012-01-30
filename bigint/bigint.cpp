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
bigint::bigint(char* x)
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
