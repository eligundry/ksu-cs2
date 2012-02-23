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
		String str1,
			   result;

		// Test
		result = str1.repeat(5);

		// Verify
		assert(str1 == "");
		assert(result == "");
	}

	{
		// Setup
		String str1,
			   sep = '\n',
			   result;

		// Test
		result = str1.repeat(5, sep);

		// Verify
		assert(str1 == "");
		assert(sep == "\n");
		assert(result == "\n\n\n\n\n");
	}

	{
		// Setup
		String str1 = "Danger",
			   result;

		// Test
		result = str1.repeat(5);

		// Verify
		assert(str1 == "Danger");
		assert(result == "DangerDangerDangerDangerDanger");
	}

	{
		// Setup
		String str1 = "Danger",
			   sep = "! ",
			   result;

		// Test
		result = str1.repeat(5, sep);

		// Verify
		assert(str1 == "Danger");
		assert(sep == "! ");
		assert(result == "Danger! Danger! Danger! Danger! Danger! ");
	}

	{
		// This one is just for me :)
		// Setup
		String str1 = "Danger!",
			   str2 = "Will Robinson",
			   result;

		// Test
		result = str1.repeat(2, '\n') + str2;

		// Verify
		assert(str1 == "Danger!");
		assert(str2 == "Will Robinson");
		assert(result == "Danger!\nDanger!\nWill Robinson");
		assert(result.strip_nl() == "Danger!Danger!Will Robinson");
	}
}
