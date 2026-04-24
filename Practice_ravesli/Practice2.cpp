#include"Practice2.h"

template<typename T>
T getValue(const std::string& output, const std::string& msg_error_locate = "")
{
	while (true)
	{
		T input;
		std::cout << output;
		std::cin >> input;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cerr << "Error locate, GetValue(), cin error, (" << msg_error_locate << ")! Try again!\n";
		}
		else
		{
			std::cin.ignore(32767, '\n');
			if (std::cin.gcount() > 1)
			{
				std::cerr << "Error locate, GetValue(), gcount error, (" << msg_error_locate << ")! Try again!\n";
			}
			else
			{
				return input;
			}
		}
	}
}

void trip()
{
	double distance{ getValue<double>("Enter distance (km): ","get distance()") };
	double fuelConsumption{ getValue<double>("Enter fuel consumption (liters for 100 km): ","get fuel consumption()") };
	double price{ getValue<double>("Enter fuel price (rub): ", "get fuel price()") };

	std::cout << "Trip will cost you " << std::fixed << std::setprecision(2) << fuelConsumption / 100 * distance * price << " rub\n";
}

//////////////////////////////////////////////////////////

void discount()
{
	double sum{ getValue<double>("Enter purchase sum: ", "get purchase sum()") };
	int discountPercent{ (sum >= 500) ? (sum >= 1000 ? 5 : 3) : 0 };
	double discount{ discountPercent ? sum / 100 * discountPercent : 0 };

	std::cout << "You have discount (" << std::fixed << std::setprecision(2) << discountPercent << "%) " << discount << "$\n";
	std::cout << "Sum with discount: " << sum - discount << "$\n";
}

//////////////////////////////////////////////////////////

