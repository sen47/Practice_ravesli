#include"Practice7.h"


////////////////////////////////////////

void isInteger()
{
	std::cout << "Enter integer: ";
	int input;
	std::cin >> input;

	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		std::cerr << "Error, not integer!\n";
	}
	else
	{
		std::cin.ignore(32767, '\n');
		if (std::cin.gcount() > 1)
		{
			std::cerr << "Error, gcount error!\n";
		}
		else
			std::cout << "Integer = " << input << '\n';
	}
}