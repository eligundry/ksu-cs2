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
		string str;
		assert(str[0] == '\0');
	}

	{
		string str('a');
		assert(str[0] == 'a');
	}

	{
		string str("a");
		assert(str[0] == 'a');
	}

	{
		string str("It's over 9000!");

        assert(str[0] == 'I');
		assert(str[2] == '\'');
	}
}
