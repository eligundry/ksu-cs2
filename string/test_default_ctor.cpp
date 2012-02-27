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
        assert(str == '\0');
    }

	{
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str;

        // VERIFY
        assert(str == "");
    }

	{
		// Setup
		String str(50);

		// Verify
		assert(str == "");
		assert(str == '\0');
	}
}
