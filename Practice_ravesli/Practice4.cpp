#include"Practice4.h"

namespace Practice4
{
	template<typename T>
	T getValue(const std::string& output = "")
	{
		while (true)
		{
			if (!output.empty())
				std::cout << output;
			T input;
			std::cin >> input;

			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(32767, '\n');
				std::cout << "Error, get value(), cin fail, try again!\n";
			}
			else
			{
				std::cin.ignore(32767, '\n');
				if (std::cin.gcount() > 1)
					std::cout << "Error, get value(), gcount fail, try again!\n";
				else
					return input;
			}
		}
	}

	void fromVerstToKM()
	{
		double distance{ getValue<double>("Enter distance (v): ") };
		std::cout << std::fixed << std::setprecision(2) << distance << " verst = " << distance * 1.0668 << " km\n";
	}

	//////////////////////////////////////////////////////////

	double getAverage(const std::vector<double>& numbers)
	{
		double sum(0);
		for (const auto el : numbers)
			sum += el;

		return sum / numbers.size();
	}

	void fillArray(std::vector<double>& numbers, const int size)
	{
		while (true)
		{
			std::cout << "Enter array: ";
			for (int i = 0; i < size; ++i)
			{
				double input;
				std::cin >> input;
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					std::cout << "Error, invalid value, try again!\n";
					numbers.clear();
					break;
				}
				else
				{
					numbers.emplace_back(input);
				}
			}

			std::cin.ignore(32767, '\n');
			if (std::cin.gcount() > 1)
			{
				std::cout << "Error, invalid count, try again!\n";
				numbers.clear();
			}
			else
				return;
		}
	}

	void averageOfArray()
	{
		int size{ getValue<int>("Enter array size: ") };
		std::vector<double> numbers;

		fillArray(numbers, size);

		std::cout << "Average = " << getAverage(numbers) << '\n'
			<< "Min = " << *std::min_element(numbers.begin(), numbers.end()) << '\n'
			<< "Max = " << *std::max_element(numbers.begin(), numbers.end()) << '\n';
	}

	/////////////////////////////////////////////////////////

	void fillArray(std::vector<double>& numbers)
	{
		while (true)
		{
			std::cout << "Enrer array: ";
			std::string str;
			if (!std::getline(std::cin, str))
			{
				std::cout << "Error, try again!\n";
				continue;
			}

			std::istringstream is{ str };
			std::string input;
			numbers.clear();
			bool success(true);


			while (is >> input)
			{
				try
				{
					size_t index(0);
					double num{ std::stod(input,&index) };

					if (index != input.length()) throw std::runtime_error("Stod error!");

					numbers.emplace_back(num);
				}
				catch (const std::exception& ex)
				{
					std::cerr << ex.what() << '\n';
					success = false;
					break;
				}
			}

			if (success && !numbers.empty())
			{
				break;
			}
			else if (success && numbers.empty())
			{
				std::cerr << "Empty array, try again!\n";
			}
		}
	}

	void mergeArrays()
	{
		std::vector<double>first;
		fillArray(first);
		std::vector<double>second;
		fillArray(second);

		std::vector<double>third;

		std::sort(first.begin(), first.end());
		std::sort(second.begin(), second.end());
		std::merge(first.begin(), first.end(), second.begin(), second.end(), std::back_inserter(third));

		std::cout << "Merge array: ";
		for (const auto el : third)
			std::cout << el << ' ';
		std::cout << '\n';
	}
}