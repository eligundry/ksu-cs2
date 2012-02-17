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
		string str1,
			   result;

		// Test
		result = str1 * 5;

		// Verify
		assert(str1 == "");
		assert(result == "");
	}

	{
		// Setup
		string str1('a'),
			   result;

		// Test
		result = str1 * 0;

		// Verify
		assert(str1 == "a");
		assert(result == "");
	}

	{
		// Setup
		string str1('a'),
			   result;

		// Test
		result = str1 * 1;

		// Verify
		assert(str1 == "a");
		assert(result == "a");
	}

	{
		// Setup
		string str1('a'),
			   result;

		// Test
		result = str1 * 5;

		// Verify
		assert(str1 == "a");
		assert(result == "aaaaa");
	}

	{
		// Setup
		string str1("Yep"),
			   result;

		// Test
		result = str1 * 5;

		// Verify 
		assert(str1 == "Yep");
		assert(result == "YepYepYepYepYep");
	}

	{
		// Setup
		string str1 = "Yep",
			   result;

		// Test
		result = str1 * 5;

		// Verify 
		assert(str1 == "Yep");
		assert(result == "YepYepYepYepYep");
	}

	{
		// Setup
		string str1 = "Yep",
			   result = "Nope";

		// Test
		result += str1 * 5;

		// Verify 
		assert(str1 == "Yep");
		assert(result == "NopeYepYepYepYepYep");
	}

	{
		// Setup
		string str1 = "Yep",
			   result1 = str1,
			   result2 = str1,
			   result3 = str1;

		// Test
		result1 *= 0;
		result2 *= 1;
		result3 *= 5;

		// Verify
		assert(str1 == "Yep");
		assert(result1 == "");
		assert(result2 == "Yep");
		assert(result3 == "YepYepYepYepYep");
	}
}
