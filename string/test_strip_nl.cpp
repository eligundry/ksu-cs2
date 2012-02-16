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
		string str1 = "This string has no new lines",
			   result;

		// Test
		result = str1.strip_nl();

		// Verify
		assert(str1 == "This string has no new lines");
		assert(result == "This string has no new lines");
	}

	{
		// Setup
		string str1 = "\n",
			   result;

		// Test
		result = str1.strip_nl();

		// Verify
		assert(str1 == "\n");
		assert(result == "");
	}

	{
		// Setup
		string str1 = "This is line 1\nThis is line 2",
			   result;

		// Test
		result = str1.strip_nl();

		// Verify
		assert(str1 == "This is line 1\nThis is line 2");
		assert(result == "This is line 1This is line 2");
	}
}
