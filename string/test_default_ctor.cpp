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
}
