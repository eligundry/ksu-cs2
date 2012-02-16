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
        string str('a');

        // VERIFY
        assert(str == "a");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        string str("a");

        // VERIFY
        assert(str == "a");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        string str("foobar");

        // VERIFY
        assert(str == "foobar");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        string str("It's over 9000!");

        // VERIFY
        assert(str == "It's over 9000!");
    }
}
