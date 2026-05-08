#include"Practice9.h"

template<typename T>
int getValue(const std::string& output)
{
	while (true)
	{
		std::cout << output;
		T value;
		std::cin >> value;

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
				return value;
		}
	}
}

int getYear()
{
	while (true)
	{
		int year{ getValue<int>("Enter year from 2000 b.c. to 2000 a.d: ") };

		if (year > 2000)
			std::cerr << "Error, invalid value!\n";
		else
			return year;
	}
}

void leapYear()
{
	int year{ getYear() };

	std::cout << "Year" << (!(year % 4) ? " is " : " is not ") << "leap\n";
}

//////////////////////////////////////////////////////

std::list<int> getArray()
{
	while (true)
	{
		std::cout << "Enter array: ";
		std::string input;
		std::getline(std::cin, input);
		std::istringstream iss{ input };

		std::list<int>array;
		std::string sValue;
		int iValue;
		bool success(true);
		while (iss >> sValue)
		{
			try
			{
				size_t index(0);
				iValue = std::stoi(sValue, &index);
				if (index != sValue.length()) throw std::runtime_error("Error, stoi!\n");

				array.emplace_back(iValue);
			}
			catch (const std::exception& ex)
			{
				std::cerr << ex.what() << std::endl;
				success = false;
				break;
			}
			catch (...)
			{
				std::cerr << "Error...\n";
				success = false;
				break;
			}
		}

		if (success && !array.empty())
			return array;
		else if (success && array.empty())
			std::cout << "Emmpty array, try again!\n";
	}
}

bool isValueInArray(const std::list<int>& array, const int value)
{
	return std::find(array.begin(), array.end(), value) != array.end();
}

void isInArray()
{
	std::list<int> array{ getArray() };
	std::cout << "Array: ";
	for (const int el : array)
		std::cout << el << ' ';
	std::cout << '\n';

	int value{ getValue<int>("Enter number: ") };

	std::cout << "Value " << value << (isValueInArray(array, value) ? " is " : " is not ") << "in array\n";
}

////////////////////////////////////////////////////

void printVar(std::array<int, 3>var, const int num)
{
	std::cout << "Variant # " << num << ": ";
	for (const int el : var)
		std::cout << el << ' ';
	std::cout << '\n';
}

int getsum(const std::array<int, 3>var)
{
	int sum(0);
	for (const int el : var)
		sum += el;
	return sum;
}

int getPlayerChoise()
{
	while (true)
	{
		int choise{ getValue<int>("Choise you variant: ") };
		if (choise < 1 || choise > 5)
			std::cerr << "Error, invalid value!\n";
		else
			return --choise;
	}
}

int getPcChoise()
{
	std::random_device rd;
	rd();
	std::mt19937 mers(rd());

	return mers() % 5;
}

void stupidGame()
{
	std::array<std::array<int, 3>, 5> variants
	{
		6,7,8,
		7,8,9,
		6,9,10,
		6,9,8,
		7,6,10
	};

	int count(0);
	for (const auto& el : variants)
		printVar(el, ++count);

	int choisePlayer{ getPlayerChoise() };
	int choisePc{ getPcChoise() };

	std::cout << "Player choise: " << choisePlayer << ", pc choise: " << choisePc << '\n';
	std::cout << "Player sum: " << getsum(variants[choisePlayer]) << ", pc sum: " << getsum(variants[choisePc]) << '\n';
	std::cout << (getsum(variants[choisePlayer]) == getsum(variants[choisePc]) ? "Nobody not" : getsum(variants[choisePlayer]) > getsum(variants[choisePc]) ? "You" : "Pc") << " win!\n";

}