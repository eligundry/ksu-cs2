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

		// Test & Verify
		assert(str1 == "");
		assert(str1.findchar('a') == -1);
	}

	{
		// Setup
		String str1 = "This is a test";

		// Test & Verify
		assert(str1 == "This is a test");
		assert(str1.findchar('t') == 10);
		assert(str1.findchar('T') == 0);
		assert(str1.findchar('z') == -1);
	}

	{
		// Setup
		String str1 = "It's over 9000!";

		// Test & Verify
		assert(str1 == "It's over 9000!");
		assert(str1.findchar('o', 3) == 5);
		assert(str1.findchar('z', 3) == -1);
	}
}
