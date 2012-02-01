// bigint Test Program
//
// Tests:  subscript, uses ==
//

#include "bigint.h"
#include <cassert>

//===========================================================================
int main ()
{
    {
        // Setup
        bigint bi(4);

        // Test 
        int digit = bi[0];

        // Verify
        assert(bi    == 4);
        assert(digit == 4);
    }

    {
        // Setup
        bigint bi(234);

        // Test 
        int digit = bi[0];

        // Verify
        assert(bi    == 234);
        assert(digit == 4);
    }

    {
        // Setup
        bigint bi(789);

        // Test 
        int digit = bi[1];

        // Verify
        assert(bi    == 789);
        assert(digit == 8);
    }

    {
        // Setup
        bigint bi(4567);

        // Test 
        int digit = bi[2];

        // Verify
        assert(bi    == 4567);
        assert(digit == 5);
    }

    {
        // Setup
        bigint bi(6789);

        // Test 
        int digit = bi[3];

        // Verify
        assert(bi    == 6789);
        assert(digit == 6);
    }

    {
        // Setup
        bigint bi("98765432109876543210");

        // Test 
        int digit = bi[19];

        // Verify
        assert(bi    == "98765432109876543210");
        assert(digit == 9);
    }

}

