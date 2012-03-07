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
		
		// Verify
		assert(str == "Eli is the best!");
		assert(result[0] == "Eli");
		assert(result[1] == "is");
		assert(result[2] == "the");
		assert(result[3] == "best!");

	}
	
	{
		// Setup
		String str = "String";
		vector<String> result;
		
		// Test
		result = str.split();
		
		// Verify
		assert(str == "String");
		assert(result[0] == "S");
		assert(result[1] == "t");
		assert(result[2] == "r");
		assert(result[3] == "i");
		assert(result[4] == "n");
		assert(result[5] == "g");
	}
}
