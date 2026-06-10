#include"Practice15.h"

namespace Practice15
{
	std::string getString(const std::string& output)
	{
		while (true)
		{
			std::cout << output;
			std::string input;
			std::getline(std::cin, input);

			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(32767, '\n');
				std::cerr << "Error, cin fail!\n";
			}
			else
				return input;
		}
	}

	int getlength(const char* str)
	{
		int count(0);
		while (str[count] != '\0')
			++count;

		return count;
	}

	void stringLength()
	{
		std::string str{ getString("Enter string: ") };
		std::cout << "Strlen = " << strlen(str.c_str()) << ", My strlen = " << getlength(str.c_str()) << '\n';
	}

	//////////////////////

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
				{
					std::cerr << "Error, gcount error!\n";
				}
				else
					return input;
			}
		}
	}

	void manhattanPrice()
	{
		int year(getInt("Enter current year: "));
		double sum(24);
		for (int i = 1826;i < year;++i)
		{
			sum += (sum * 0.06);
		}

		std::cout << std::fixed << std::setprecision(2) << "Sum = " << sum << "$\n";
	}
}