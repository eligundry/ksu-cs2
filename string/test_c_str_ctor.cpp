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
        String str('a');

        // VERIFY
        assert(str == "a");
		assert(str.buffCapacity() == 2);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str("a");

        // VERIFY
        assert(str == "a");
        assert(str.buffCapacity() == default_size);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str("foobar");

        // VERIFY
        assert(str == "foobar");
		assert(str.buffCapacity() == default_size);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str("It's over 9000!");

        // VERIFY
        assert(str == "It's over 9000!");
		assert(str.buffCapacity() == default_size);
    }
	
	{
		// Setup
		String str("It's over 9000", 50);
		
		// Verify
		assert(str == "It's over 9000");
		assert(str.buffCapacity() == 50);
	}
}
