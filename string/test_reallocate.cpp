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
		String str1("This is the new string", 30),
			   dupe_str1("This is the new string");
		
		// Test 
		str1.reallocate(50);
		
		// Verify
		assert(str1 == "This is the new string");
		assert(str1.buffCapacity() == 50);
		assert(str1.length() == 22);
		assert(dupe_str1.length() == str1.length());
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
	
	{
		// Setup
		String str;
		
		// Test & Verify
		str.reallocate(40);
		assert(str.buffCapacity() == 40);
		str.reallocate(20);
		assert(str.buffCapacity() == 20);
		str.reallocate(60);
		assert(str.buffCapacity() == 60);
	}
	
	{
		// Setup
		String str = 'a';
		
		// Test
		str.reallocate(30);
		
		// Verify
		assert(str == "a");
		assert(str.length() == 1);
		assert(str.buffCapacity() == 30);
	}
	
	{
		// Setup
		String str('a');
		
		// Test
		str.reallocate();
		
		// Verify
		assert(str == "a");
		assert(str.buffCapacity() == 128);
	}
}
