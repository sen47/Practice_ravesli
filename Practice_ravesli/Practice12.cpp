#include"Practice12.h"

namespace Practice12
{
	void stringReverce()
	{
		std::cout << "Enter string: ";
		std::string input;
		std::getline(std::cin, input);
		std::reverse(input.begin(), input.end());
		std::cout << "Result: " << input << '\n';
	}

	///////////////////////////////////////////

	bool checkInt(const int num)
	{
		return num >= 1 && num <= 365;
	}

	int getInt(const std::string& output)
	{
		while (true)
		{
			std::cout << output;
			int input;
			std::cin >> input;

			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(32767, '\n');
				std::cerr << "Error, cin fail!\n";
			}
			else
			{
				std::cin.ignore(32767, '\n');
				if (std::cin.gcount() > 1)
					std::cerr << "Error,gcount fail!\n";
				else if (!checkInt(input))
					std::cerr << "Error, invalid value!\n";
				else
					return input;
			}
		}
	}

	void getWeekDay()
	{
		int day(getInt("Enter day(1-365): "));
		std::cout << "It will be ";
		switch (day % 7)
		{
		case 0:
		{
			std::cout << "sunday\n";
			break;
		}
		case 1:
		{
			std::cout << "monday\n";
			break;
		}
		case 2:
		{
			std::cout << "tuesday\n";
			break;
		}
		case 3:
		{
			std::cout << "wednesday\n";
			break;
		}
		case 4:
		{
			std::cout << "thursday\n";
			break;
		}
		case 5:
		{
			std::cout << "friday\n";
			break;
		}
		case 6:
		{
			std::cout << "saturday\n";
			break;
		}
		}
	}
}