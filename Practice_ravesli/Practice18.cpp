#include"Practice18.h"

namespace Practice18
{
	template<typename T>
	T getValue(const std::string& output)
	{
		while (true)
		{
			std::cout << output;
			T input;
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
					std::cerr << "Error, gcount fail!\n";
				}
				else
					return input;
			}
		}
	}
	
	void applePrice()
	{
		double price(getValue<int>("Enter price of 1kg of apples: "));
		double weight(getValue<int>("Enter weight of apples: "));
		std::cout << "Price of purchase " << std::fixed << std::setprecision(2) << price * weight << '\n';
	}

	/////////////////////

	std::random_device rd;
	std::mt19937 mers(rd());

	int getRandom()
	{
		return mers() % 100;
	}

	std::list<int> getArrRandom()
	{
		std::list<int>arr;
		int size(getValue<int>("Enter size: "));
		for (int i = 0;i < size;++i)
			arr.emplace_back(getRandom());

		return arr;
	}

	std::list<int> getArrUser()
	{
		while (true)
		{
			std::list<int>arr;
			std::cout << "Enter array: ";
			std::string input_str;
			std::getline(std::cin, input_str);
			std::istringstream input_stream{ input_str };

			std::string num_str;
			bool sucssess(true);
			while (input_stream >> num_str)
			{
				try
				{
					size_t index;
					int num(std::stoi(num_str, &index));
					if (index != num_str.length())throw std::runtime_error("stoi fail");

					arr.emplace_back(num);
				}
				catch (const std::exception& ex)
				{
					std::cerr << "Error, " << ex.what() << "!\n";
					sucssess = false;
					break;
				}
				catch (...)
				{
					std::cerr << "Error...!\n";
					sucssess = false;
					break;
				}
			}

			if (!arr.empty() && sucssess)
				return arr;
			else
				std::cerr << "Error, invalid input!\n";
		}
	}

	int getValueInDiapason(const std::string& output,const int min,const int max)
	{
		while (true)
		{
			int input(getValue<int>(output));
			if (input<min || input>max)
				std::cerr << "Error, invalid value!\n";
			else
				return input;
		}
	}

	void printList(const std::list<int>& arr)
	{
		std::cout << "Array: ";
		for (const int el : arr)
			std::cout << el << ' ';
		std::cout << '\n';
	}

	void deleteRepeatElement()
	{
		std::list<int> arr;

		int menuChoise(getValueInDiapason("Chose how fill array(1 - auto, 2 - manual): ", 1, 2));
		switch (menuChoise)
		{
		case 1:
			arr = getArrRandom();
			break;
		case 2:
			arr = getArrUser();
			break;
		}

		printList(arr);

		std::cout << "\n\n";

		for (auto iter_outer(arr.begin());iter_outer != arr.end();)
		{
			auto current_el(iter_outer++);
			int counter(0);

			for (auto iter_inner(iter_outer);iter_inner != arr.end();)
			{
				if (*current_el == *iter_inner)
				{
					if (!counter)
					{
						++counter;
						++iter_inner;
					}
					else
					{
						iter_inner = arr.erase(iter_inner);
					}
				}
				else
					++iter_inner;
			}
		}

		printList(arr);
	}
}