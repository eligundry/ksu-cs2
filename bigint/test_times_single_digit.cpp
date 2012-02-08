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
        bi.times_single_digit(1);

        // Verify
        assert(bi == 3);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test 
        bi.times_single_digit(5);

        // Verify
        assert(bi == 15);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(99999);

        // Test 
        bi.times_single_digit(2);

        // Verify
        assert(bi == 199998);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(99999999);

        // Test 
        bi.times_single_digit(9);

        // Verify
        assert(bi == 899999991);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(1);

        // Test 
        bi.times_single_digit(1);

        // Verify
        assert(bi == 1);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(5555);

        // Test 
        bi.times_single_digit(0);

        // Verify
        assert(bi == 0);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(1);

        // Test 
        bi.times_single_digit(0);

        // Verify
        assert(bi == 0);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(0);

        // Test 
        bi.times_single_digit(1);

        // Verify
        assert(bi == 0);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(0);

        // Test 
        bi.times_single_digit(0);

        // Verify
        assert(bi == 0);
    }

}
