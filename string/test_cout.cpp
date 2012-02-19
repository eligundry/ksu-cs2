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
		string str1 = "It's over 9000";

		// Test & Verify
		std::cout << str1 << std::endl;
	}

	{
		// Setup
		string str1 = "It's over 9000!\n";
		str1 *= 5;

		// Test & Verify
		std::cout << str1 << std::endl;
	}

	{
		// Setup
		string str1 = "a";

		// Test & Verify
		std::cout << str1 << std::endl;
	}

	{
		// Setup
		string str1 = "This is line 1.\nThis is line 2.";

		// Test & Verify
		std::cout << str1 << std::endl;
	}

	{
		// Setup
		string str1;

		// Test & Verify
		std::cout << str1 << std::endl;
	}
}
