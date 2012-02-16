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
        string str;

        // VERIFY
        assert(str == '\0');
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        string str;

        // VERIFY
        assert(str == "");
    }
}
