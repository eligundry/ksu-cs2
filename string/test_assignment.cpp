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
		string str1;

		// Test
		str1 = 'a';

		// Verify
		assert(str1 == "a");
	}

	{
		// Setup
		string str1;

		// Test
		str1 = "This is a test.";

		// Verify
		assert(str1 == "This is a test.");
	}

	{
		// Setup & Test
		string str1 = 'a';
		
		// Verify
		assert(str1 == "a");
	}

	{
		// Setup & Test
		string str1 = "This is a test.";

		// Verify
		assert(str1 == "This is a test.");
	}
}
