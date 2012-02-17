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
			   result1,
			   result2;

		// Test
		result1 = str1 - 13; 
		result2 = str1 - (-13);

		// Verify
		assert(str1 == "Visable. Not visable.");
		assert(result1 == "Visable.");
		assert(result2 == "Visable. Not visable.");
	}

	{
		// Setup
		char remove = 'd';
		string str1 = "defense! defense! defense!",
			   result;

		// Test
		result = str1 - remove;

		// Verify
		assert(remove == 'd');
		assert(str1 == "defense! defense! defense!");
		assert(result == "efense! efense! efense!");
	}

	{
		// Setup
		string remove = "de",
			   str1 = "defense! defense! defense!",
			   result;

		// Test
		result = str1 - remove;

		// Verify
		assert(remove == "de");
		assert(str1 == "defense! defense! defense!");
		assert(result == "fense! fense! fense!");
	}
}
