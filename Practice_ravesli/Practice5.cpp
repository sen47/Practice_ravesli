#include"Practice5.h"

namespace Practice5
{
	namespace TASK_5_1
	{
		template<typename T>
		T getInput(const std::string& output, const std::string& applicationPlace = "")
		{
			T input{};
			while (true)
			{
				std::cout << output;
				std::cin >> input;

				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					std::cerr << "Error, cin fail, " << applicationPlace << " !\n";
				}
				else
				{
					std::cin.ignore(32767, '\n');
					if (std::cin.gcount() > 1)
					{
						std::cerr << "Error, gcount error, " << applicationPlace << " !\n";
					}
					else
					{
						return input;
					}
				}
			}
		}
	}

	void timeConvertor()
	{
		int time{ TASK_5_1::getInput<int>("Enter time (m): ") };
		std::cout << time << " = " << time / 60 << " h. " << time % 60 << " m.\n";
	}

	///////////////////////////////////////////////////////////////

	void costTable()
	{
		std::string productName;
		std::cout << "Enter pruduct name: ";
		std::getline(std::cin, productName);

		double productPrice{ TASK_5_1::getInput<double>("Enter product price: ") };

		std::cout << "Weight\tPrice\n"
			<< "(g)\t($)\n";
		for (int i = 1;i <= 10;++i)
		{
			std::cout << 100 * i << '\t' << std::fixed << std::setprecision(2) << productPrice * 0.1 * i << '\n';
		}
	}

	/////////////////////////////////////////////////////////
}