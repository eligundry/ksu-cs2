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
	}
}
