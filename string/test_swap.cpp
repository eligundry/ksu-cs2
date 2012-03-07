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
		String str1 = "It's over 9000!",
			   str2 = "It's under 9000!";

		// Test
		str1.swap(str2);

		// Verify
		assert(str1 == "It's under 9000!");
		assert(str2 == "It's over 9000!");
	}
}
