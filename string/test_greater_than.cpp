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
			   str2;

		// Test & Verify
		assert(str1 >= str2);
	}

	{
		// Setup
		String str2 = "a",
			   str1 = "z";

		// Test & Verify
		assert(str1 > str2);
		assert(str1 >= str2);
	}

	{
		// Setup
		String str2 = "az",
			   str1 = "zz";

		// Test & Verify
		assert(str1 > str2);
		assert(str1 >= str2);
	}

	{
		// Setup
		String str2 = "az",
			   str1 = "z";

		// Test & Verify
		assert(str1 > str2);
		assert(str1 >= str2);
	}
}
