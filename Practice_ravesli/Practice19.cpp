#include"Practice19.h"

namespace Practice19
{
	void deleteSpasesAndPunct()
	{
		std::cout << "Enter string: ";
		std::string str;
		std::getline(std::cin, str);
		std::cout << "Your string: " << str << '\n';

		for (auto el = str.begin();el != str.end();)
		{
			if (isspace(*el) || ispunct(*el))
				el = str.erase(el);
			else
				++el;
		}

		std::cout << "Without spaces and punct: " << str << '\n';
	}

	////////////////////////////

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
					std::cerr << "Error, gcount fail!\n";
				else if (input < 1)
					std::cerr << "Error, invalid value!\n";				
				else
					return input;
			}
		}
	}

	static std::random_device rd;
	static std::mt19937 mers(rd());

	int getRandom()
	{
		return mers() % 100;
	}

	void genArr()
	{
		int size(getInt("Enter size: "));
		int* arr = new int[size];

		std::cout << "Your array: ";
		for (int i = 0;i < size;++i)
		{
			arr[i] = getRandom();
			std::cout << arr[i] << ' ';
		}
		std::cout << '\n';

		int maxNum(arr[0]);
		for (int i = 0;i < size;++i)
			if (arr[i] > maxNum)
				maxNum = arr[i];

		std::cout << "Max element of array: " << maxNum << '\n';

		delete[]arr;
	}
}