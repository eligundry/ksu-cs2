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
		String str1 = "abcdefghijk",
			   result1,
			   result2,
			   result3,
			   result4;

		// Test
		result1 = str1.substr(0);
		result2 = str1.substr(1);
		result3 = str1.substr(0, 3);
		result4 = str1.substr(1, 12);


		// Verfiy
		assert(str1 == "abcdefghijk");
		assert(result1 == "abcdefghijk");
		assert(result2 == "bcdefghijk");
		assert(result3 == "abc");
		assert(result4 == "bcdefghijk");
	}
}
