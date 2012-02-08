// bigint Test Program
//
// Tests:  times_10, uses ==
//

#include "bigint.h"

#include <cassert>

//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test 
        bi.times_10(0);

        // Verify
        assert(bi == 3);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(4);

        // Test 
        bi.times_10(1);

        // Verify
        assert(bi == 40);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(5);

        // Test 
        bi.times_10(2);

        // Verify
        assert(bi == 500);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(6);

        // Test 
        bi.times_10(5);

        // Verify
        assert(bi == 600000);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(7);

        // Test 
        bi.times_10(10);

        // Verify
        assert(bi == "70000000000");
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(8);

        // Test 
        bi.times_10(50);

        // Verify
        assert(bi == "800000000000000000000000000000000000000000000000000");
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(0);

        // Test 
        bi.times_10(0);

        // Verify
        assert(bi == 0);
    }

}

