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
		assert(str1.findchar('a') == 0);
		assert(str1.findchar('\0') == 0);
	}

	{
		// Setup
		String str1 = "This is a test";

		// Test & Verify
		assert(str1 == "This is a test");
		assert(str1.findchar('t') == 2);
		assert(str1.findchar('T') == 1);
		assert(str1.findchar('z') == 0);
	}
}
