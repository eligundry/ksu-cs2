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
		result = str1 * 5;

		// Verify
		assert(str1 == "");
		assert(result == "");
	}

	{
		// Setup
		String str1('a'),
			   result;

		// Test
		result = str1 * -1;

		// Verify
		assert(str1 == "a");
		assert(result == "");
	}

	{
		// Setup
		String str1('a'),
			   result;

		// Test
		result = str1 * 0;

		// Verify
		assert(str1 == "a");
		assert(result == "");
	}

	{
		// Setup
		String str1('a'),
			   result;

		// Test
		result = str1 * 1;

		// Verify
		assert(str1 == "a");
		assert(result == "a");
	}

	{
		// Setup
		String str1('a'),
			   result;

		// Test
		result = str1 * 5;

		// Verify
		assert(str1 == "a");
		assert(result == "aaaaa");
	}

	{
		// Setup
		String str1("Yep"),
			   result;

		// Test
		result = str1 * 5;

		// Verify 
		assert(str1 == "Yep");
		assert(result == "YepYepYepYepYep");
	}

	{
		// Setup
		String str1 = "Yep",
			   result;

		// Test
		result = str1 * 5;

		// Verify 
		assert(str1 == "Yep");
		assert(result == "YepYepYepYepYep");
	}

	{
		// Setup
		String str1 = "Yep",
			   result = "Nope";

		// Test
		result += str1 * 5;

		// Verify 
		assert(str1 == "Yep");
		assert(result == "NopeYepYepYepYepYep");
	}

	{
		// Setup
		String str1 = "Yep",
			   result1 = str1,
			   result2 = str1,
			   result3 = str1,
			   result4 = str1;

		// Test
		result1 *= 0;
		result2 *= 1;
		result3 *= 5;
		result4 *= -3;

		// Verify
		assert(str1 == "Yep");
		assert(result1 == "");
		assert(result2 == "Yep");
		assert(result3 == "YepYepYepYepYep");
		assert(result4 == "");
	}
}
