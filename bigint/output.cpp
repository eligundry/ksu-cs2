// bigint output demonstration
//
// Change the name of the output function if necessary.

#include "bigint.h"
#include <cassert>
#include <iostream>

//===========================================================================
int main ()
{
    // Define, output default constructed value
    bigint bi_1;
    std::cout << "number 1: ";
    bi_1.output(std::cout);
    std::cout << "\n";

    // Define, output 1 digit number
    bigint bi_2(1);
    std::cout << "number 2: ";
    bi_2.output(std::cout);
    std::cout << "\n";

    // Define, output 3 digit number
    bigint bi_3(123);
    std::cout << "number 2: ";
    bi_3.output(std::cout);
    std::cout << "\n";

    // Define, output 90 digit number
    bigint bi_4("123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890");
    std::cout << "number 3: ";
    bi_4.output(std::cout);
    std::cout << "\n";

}

