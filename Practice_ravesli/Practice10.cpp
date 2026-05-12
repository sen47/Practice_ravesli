#include"Practice10.h"

namespace Practice10
{
	std::list<double> getList(const std::string& output)
	{
		while (true)
		{
			std::cout << output;
			std::string input;
			std::getline(std::cin, input);
			std::istringstream isInput{ input };
			std::string sNumber;

			std::list<double> numbers;
			bool success{ true };
			while (isInput >> sNumber)
			{
				double number(0);
				size_t index;
				try
				{
					number = std::stod(sNumber, &index);
					if (index < sNumber.length()) throw std::runtime_error("Stod error!");
				}
				catch (const std::exception& ex)
				{
					std::cerr << ex.what() << '\n';
					success = false;
					break;
				}
				catch (...)
				{
					std::cerr << "Error...\n";
					success = false;
					break;
				}

				numbers.emplace_back(number);
			}
			
			if (!numbers.empty() && success)
				return numbers;
			else if (numbers.empty())
			{
				std::cerr << "Numbers is empty!\n";
			}
			else if (!success)
			{
				std::cerr << "Success is false!\n";
			}
			else
			{
				std::cerr << "Error unknown!\n";
			}
		}
	}

	double getAverage(const std::list<double>numbers)
	{
		double sum(0);
		for (const double el : numbers)
			sum += el;
		return sum / numbers.size();
	}

	void averageDouble()
	{
		std::list<double> numbers{ getList("Enter numbers(double): ") };

		std::cout << "Array: ";
		std::cout << std::fixed;
		for (const double el : numbers)
			std::cout<<std::setprecision(1) << el << ' ';
		std::cout << std::endl;

		std::cout << "Average of array = " << getAverage(numbers) << '\n';
	}

	////////////////////////////////////////////////////////////////////

	void isHappyNumber()
	{

	}
}