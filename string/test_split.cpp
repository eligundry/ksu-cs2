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
		String str = "Eli is the best!";
		vector<String> result;
		
		// Test
		result = str.split(' ');
		
		// Test
		assert(str == "Eli is the best!");
		assert(result[0] == "Eli");
		assert(result[1] == "is");
		assert(result[2] == "the");
		assert(result[3] == "best!");
	}
}
