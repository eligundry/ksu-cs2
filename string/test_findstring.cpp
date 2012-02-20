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
		string str1;

		// Test & Verify
		assert(str1 == "");
		assert(str1.findstr("This") == 0);
		assert(str1.findstr("\0") == 0);
	}

	{
		// Setup
		string str1 = "It's over 9000!";

		// Test & Verify
		assert(str1 == "It's over 9000!");
		assert(str1.findstr("It's") == 1);
		assert(str1.findstr("00") == 1);
	}
}
