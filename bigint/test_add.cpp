// bigint Test Program
//
// Tests:  int constructor, uses ==
//

#include "bigint.h"

#include <cassert>

//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        // Setup fixture
        bigint left(0);
        bigint right(0);
        bigint result;

        // Test 
        result = left + right;

        // Verify
        assert(left   == 0);
        assert(right  == 0);
        assert(result == 0);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint left(1);
        bigint right(0);
        bigint result;

        // Test 
        result = left + right;

        // Verify
        assert(left   == 1);
        assert(right  == 0);
        assert(result == 1);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint left(0);
        bigint right(1);
        bigint result;

        // Test 
        result = left + right;

        // Verify
        assert(left   == 0);
        assert(right  == 1);
        assert(result == 1);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint left(123);
        bigint right(56);
        bigint result;

        // Test 
        result = left + right;

        // Verify
        assert(left   == 123);
        assert(right  ==  56);
        assert(result == 179);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint left(65);
        bigint right(321);
        bigint result;

        // Test 
        result = left + right;

        // Verify
        assert(left   ==  65);
        assert(right  == 321);
        assert(result == 386);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint left(9999);
        bigint right(1);
        bigint result;

        // Test 
        result = left + right;

        // Verify
        assert(left   ==  9999);
        assert(right  ==     1);
        assert(result == 10000);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint left(1);
        bigint right(999999);
        bigint result;

        // Test 
        result = left + right;

        // Verify
        assert(left   ==       1);
        assert(right  ==  999999);
        assert(result == 1000000);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint left("2222");
        bigint right("888888888888888888888888888888888888");
        bigint result;

        // Test 
        result = left + right;

        // Verify
        assert(left   == "2222");
        assert(right  == "888888888888888888888888888888888888");
        assert(result == "888888888888888888888888888888891110");
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint left("777777777777777777777777777777777777777777777");
        bigint right("333333");
        bigint result;

        // Test 
        result = left + right;

        // Verify
        assert(left   == "777777777777777777777777777777777777777777777");
        assert(right  == "333333");
        assert(result == "777777777777777777777777777777777777778111110");
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint left("111111111111111111111111111111111111111111");
        bigint right("999999999999999999999999999999999999999999");
        bigint result;

        // Test 
        result = left + right;

        // Verify
        assert(left   == "111111111111111111111111111111111111111111");
        assert(right  == "999999999999999999999999999999999999999999");
        assert(result == "1111111111111111111111111111111111111111110");
    }

}

