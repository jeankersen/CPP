#include "Conversion.hpp"

#include <iostream>

int main(int argc, char *argv[]) 
{
	Scalar scalar;
	if (argc == 1) 
	{
		std::cout <<  "Usage: </convert> <literal>" << std::endl;
		return 1;
	}

	scalar.convert(argv[1]);

	return 0;
}