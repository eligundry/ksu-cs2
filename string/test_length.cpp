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
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
		String str;

        // VERIFY
        assert(str.length() == 0);
	}

	{
		// Setup
		String str('a');

		// Verify
		assert(str.length() == 1);
	}

	{
		// Setup
		String str("a");

		// Verify
		assert(str.length() == 1);
	}

	{
		// Test
		String str("It's over 9000!");

        // Verify
        assert(str.length() == 15);
	}
}
