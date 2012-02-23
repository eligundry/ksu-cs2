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
		String str1('a'),
			   str2;

		// Verify
		assert(str1 > str2);
		assert(str1 >= str2);
	}

	{
		// Setup
		String str1("foo"),
			   str2("bar");

		// Verify
		assert(str1 >= str2);
	}
}
