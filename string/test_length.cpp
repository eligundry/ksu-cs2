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
        assert(str.length() == 0);
	}

	{
		string str('a');
		assert(str.length() == 1);
	}

	{
		string str("a");
		assert(str.length() == 1);
	}

	{
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
		string str("It's over 9000!");

        // VERIFY
        assert(str.length() == 15);
	}
}
