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
		string str1 = "vim",
			   str2 = "vim",
			   result;

		// Test
		result = str1.zip(str2);

		// Verify
		assert(str1 == "vim");
		assert(str2 == "vim");
		assert(result == "vviimm");
	}

	{
		// Setup
		string str1 = "vim",
			   result;

		// Test
		result = str1.zip(str1);

		// Verify
		assert(str1 == "vim");
		assert(result == "vviimm");
	}

	{
		// Setup
		string str1 = "vim",
			   str2 = "emacs",
			   result;

		// Test
		result = str1.zip(str2);

		// Verify
		assert(str1 == "vim");
		assert(str2 == "emacs");
		assert(result == "veimmacs");
	}

	{
		// Setup
		string str1 = "vim",
			   result;

		// Test
		result = str1.zip("emacs");

		// Verify
		assert(str1 == "vim");
		assert(result == "veimmacs");
	}

	{
		// Setup
		string str1 = "vim",
			   result;

		// Test
		result = str1.zip('a');

		// Verify
		assert(str1 == "vim");
		assert(result == "vaim");
	}
}
