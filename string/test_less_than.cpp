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
		assert(str1 <= str2);
	}

	{
		// Setup
		String str1 = "a",
			   str2 = "z";

		// Test & Verify
		assert(str1 < str2);
		assert(str1 <= str2);
	}

	{
		// Setup
		String str1 = "az",
			   str2 = "zz";

		// Test & Verify
		assert(str1 < str2);
		assert(str1 <= str2);
	}

	{
		// Setup
		String str1 = "az",
			   str2 = "z";

		// Test & Verify
		assert(str1 < str2);
		assert(str1 <= str2);
	}
}
