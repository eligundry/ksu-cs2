//  String class test program
//
//  Tests: XXX
//

#include "string.h"
#include <cassert>

//===========================================================================
int main ()
{
	{
		// Setup
		string str1('a'),
			   result;

		// Test
		result = str1.reverse();

		// Verify
		assert(str1 == "a");
		assert(result == "a");
	}

	{
		// Setup
		string str1("It's over 9000!"),
			   result;

		// Test
		result = str1.reverse();

		// Verify
		assert(str1 == "It's over 9000!");
		assert(result == "!0009 revo s'tI");
	}

	{
		// Setup
		string str1 = "It's over 9000!",
			   result;

		// Test
		result = str1.reverse();

		// Verify
		assert(str1 == "It's over 9000!");
		assert(result == "!0009 revo s'tI");
	}
}