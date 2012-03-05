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
		// Setup
		String str1("This is the new string", 30);
		
		// Test 
		str1.reallocate(50);
		
		// Verify
		assert(str1 == "This is the new string");
		assert(str1.buffCapacity() == 50);
	}

	{
		// Setup
		String str = "String";
		
		// Test
		str.reallocate(2);
		
		// Verify
		// Buffcapacity is not true because reallocate does not make a string
		// smaller. It'll instead double the capacity until the string fits.
		assert(str == "String");
		assert(str.buffCapacity() != 2);
	}
}
