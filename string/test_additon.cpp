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
			   str2,
			   result;

		// Test
		result = str1 + str2;

		// Verify
		assert(str1 == '\0');
		assert(str2 == '\0');
		assert(result == '\0');
	}

	{
		// Setup
		string str1,
			   str2('b'),
			   result;

		// Test
		result = str1 + str2;

		// Verify
		assert(str1 == '\0');
		assert(str2 == "b");
		assert(result == "b");
	}

	{
		// Setup
		string str1('a'),
			   str2('b'),
			   result;

		// Test
		result = str1 + str2;

		// Verify
		assert(str1 == "a");
		assert(str2 == "b");
		assert(result == "ab");
	}

	{
		// Setup
		string str1("a"),
			   str2("b"),
			   result;

		// Test
		result = str1 + str2;

		// Verify
		assert(str1 == "a");
		assert(str2 == "b");
		assert(result == "ab");
	}

	{
		// Setup
		string str1('a'),
			   str2("b"),
			   result;

		// Test
		result = str1 + str2;

		// Verify
		assert(str1 == "a");
		assert(str2 == "b");
		assert(result == "ab");
	}

	{
		// Setup
		string str1("a"),
			   str2('b'),
			   result;

		// Test
		result = str1 + str2;

		// Verify
		assert(str1 == "a");
		assert(str2 == "b");
		assert(result == "ab");
	}

	{
		// Setup
		string str1("This is a test. "),
			   str2("It should pass."),
			   result;

		// Test
		result = str1 + str2;

		// Verify
		assert(str1 == "This is a test. ");
		assert(str2 == "It should pass.");
		assert(result == "This is a test. It should pass.");
	}

	{
		// Setup
		string str1("This is a test. "),
			   result;

		// Test
		result = str1 + "It should pass.";

		// Verify
		assert(str1 == "This is a test. ");
		assert(result == "This is a test. It should pass.");
	}

	{
		// Setup
		string str1("It's over 9000"),
			   result;

		// Test
		result = str1 + '!';

		// Verify
		assert(str1 == "It's over 9000");
		assert(result == "It's over 9000!");
	}

	{
		// Setup
		string str1("It's over 9000! "),
			   str2("And that's really high!");

		// Test
		str1 += str2;

		// Verify
		assert(str1 == "It's over 9000! And that's really high!");
	}

	{
		// Setup
		string str1("It's over 9000! ");

		// Test
		str1 += "And that's really high!";

		// Verify
		assert(str1 == "It's over 9000! And that's really high!");
	}
}
