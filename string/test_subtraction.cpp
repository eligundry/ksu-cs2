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
		String str1 = "Visable. Not visable.",
			   result1,
			   result2,
			   result3;

		// Test
		result1 = str1 - 13; 
		result2 = str1 - (-13);
		result3 = str1 - 1000;

		// Verify
		assert(str1 == "Visable. Not visable.");
		assert(result1 == "Visable.");
		assert(result2 == "Visable. Not visable.");
		assert(result3 == "");
		str1 -= 13;
		assert(str1 == "Visable.");
	}

	{
		// Setup
		char remove = 'd';
		String str1 = "defense! defense! defense!",
			   result;

		// Test
		result = str1 - remove;

		// Verify
		assert(remove == 'd');
		assert(str1 == "defense! defense! defense!");
		str1 -= remove;
		assert(str1 == "efense! efense! efense!");
		assert(result == "efense! efense! efense!");
	}

	{
		// Setup
		String remove = "de",
			   str1 = "defense! defense! defense!",
			   result;

		// Test
		result = str1 - remove;

		// Verify
		assert(remove == "de");
		assert(str1 == "defense! defense! defense!");
		str1 -= remove;
		assert(str1 == "fense! fense! fense!");
		assert(result == "fense! fense! fense!");
	}

	{
		// Setup
		String str1 = "thisthat",
			   result;

		// Test
		result = str1 - "this";

		// Verify
		assert(str1 == "thisthat");
		str1 -= "that";
		assert(str1 == "this");
		assert(result == "that");
	}
}
