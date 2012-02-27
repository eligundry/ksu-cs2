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
		String str1;

		// Test
		str1 = 'a';

		// Verify
		assert(str1 == "a");
	}

	{
		// Setup
		String str1;

		// Test
		str1 = "This is a test.";

		// Verify
		assert(str1 == "This is a test.");
	}

	{
		// Setup & Test
		String str1 = 'a';
		
		// Verify
		assert(str1 == "a");
	}

	{
		// Setup & Test
		String str1 = "This is a test.";

		// Verify
		assert(str1 == "This is a test.");
	}

	{
		// Setup & Test
		String str1 = "Yay!",
			   str2 = str1;

		// Verify
		assert(str2 == "Yay!");
		assert((str2 += str1) == "Yay!Yay!");
	}
}
