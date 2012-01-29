// bigint Test Program
//
// Tests:  default constructor, uses ==
//

#include "bigint.h"
#include <cassert>

//===========================================================================
int main ()
{
    // Setup

    // Test 
    bigint bi;

    // Verify
    assert(bi == 0);
}

