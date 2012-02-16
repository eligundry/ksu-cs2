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
		string str1;
		string str2('a');
		assert(str1 < str2);
		assert(str1 <= str2);
	}

	{
		string str1("foo");
		string str2("bar");
		assert(str1 <= str2);
	}
}
