#include <iostream>
#include "stack.h"

int main()
{
	{
		// Empty Stack Test
		Stack<int> empty_stack;

		std::cout << "Empty Stack Test" << std::endl
				  << "Expected:" << std::endl
				  << "Result: ";

		empty_stack.printAll();
	}

	{
		// Single Item Push Test
		Stack<int> stack_single;

		stack_single.push(1);

		std::cout << "Single Item Stack Test" << std::endl
				  << "Expected: 1" << std::endl
				  << "Result: ";

		stack_single.printAll();
	}

	{
		// Multiple Item Push Test
		Stack<int> stack_multiple;

		stack_multiple.push(1);
		stack_multiple.push(2);
		stack_multiple.push(3);

		std::cout << "Multiple Item Stack Test" << std::endl
				  << "Expected: 3 2 1" << std::endl 
				  << "Result: ";

		stack_multiple.printAll();
	}
}
