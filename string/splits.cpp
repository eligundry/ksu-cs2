/*
 * Author      : Eli Gundry
 * Date        : 03/22/2012
 * Name        : splits
 * Description : Splits text on words in a file
 */

#include "string.h"
#include <fstream>

int main(int argc, char *argv[])
{

	if (argc == 0) {
		std::cerr << "Usage: " << argv[1] << " file_name" << std::endl;
		exit(1);
	}

	std::ifstream in(argv[1]);
	
	if (!in) {
		std::cerr << "Couldn't open " << argv[1] << ", exiting." << std::endl;
		exit(1);
	}
	
	
	String line;
	std::vector<String> vec;

	do {
		line = getline(in);

		vec = line.split(' ');
		std::cerr << "Vector size: " << vec.size() << std::endl;
		std::cerr << "Vector capacity: " << vec.capacity() << std::endl;
		
		for (unsigned int k = 0; k < vec.size(); ++k) {
			std::cout << vec[k] << std::endl; 		
		}
		
	} while (!in.eof());

	return (in.close(), 0);
}


