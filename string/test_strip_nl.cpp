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
		String str1,
			   result;

		// Test
		result = str1.strip_nl();

		// Verify
		assert(str1 == "");
		assert(result == "");
	}

	{
		// Setup
		String str1 = "This string has no new lines",
			   result;

		// Test
		result = str1.strip_nl();

		// Verify
		assert(str1 == "This string has no new lines");
		assert(result == "This string has no new lines");
	}

	{
		// Setup
		String str1 = "\n",
			   result;

		// Test
		result = str1.strip_nl();

		// Verify
		assert(str1 == "\n");
		assert(result == "");
	}

	{
		// Setup
		String str1 = "This is line 1\nThis is line 2",
			   result;

		// Test
		result = str1.strip_nl();

		// Verify
		assert(str1 == "This is line 1\nThis is line 2");
		assert(result == "This is line 1This is line 2");
	}

	{
		// Setup
		String str1 = "This is line 1\nThis is line 2",
			   replacement = ". ",
			   result;

		// Test
		result = str1.strip_nl(replacement);

		// Verify
		assert(str1 == "This is line 1\nThis is line 2");
		assert(result == "This is line 1. This is line 2");
	}
}
