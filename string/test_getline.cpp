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
		// setup
		string str;
		
		// test
		str.getline(istream& in);
		
		// Verify
		assert(str == "t");
	}
}
