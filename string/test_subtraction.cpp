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
		string str1 = "Visable. Not visable.",
			   result;

		// Test
		result = str1 - 13; 

		// Verify
		assert(str1 == "Visable. Not visable.");
		assert(result == "Visable.");
	}
}
