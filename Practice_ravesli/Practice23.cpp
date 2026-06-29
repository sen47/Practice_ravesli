#include"Practice23.h"

namespace Practice23
{
	void reverceString()
	{
		std::cout << "Enter string: ";
		std::string input;
		std::getline(std::cin, input);
		
		std::istringstream is{ input };
		std::string word, input_reverce;
		while (is >> word)
		{
			input_reverce.insert(0, word.c_str());
		}

		std::cout << input_reverce << '\n';
	}

	////////////////

	static std::random_device rd;
	static std::mt19937 mt(rd());

	int getRandomInt()
	{
		int valueMin(1), valueMax(10);
		return valueMin + mt() % (valueMax - valueMin);
	}

	void printArr(const std::string&name, const std::vector<int>& arr)
	{
		std::cout << name;
		for (const auto el : arr)
			std::cout << el << ' ';
		std::cout << '\n';
	}

	void commonWithoutRepeating()
	{
		int size(20);
		std::vector<int>arr1, arr2;
		for (int i = 0;i < size;++i)
		{
			arr1.emplace_back(getRandomInt());
			arr2.emplace_back(getRandomInt());
		}

		printArr("Arr1: ", arr1);
		printArr("Arr2: ", arr2);

		std::vector<int>arr3;
		for (auto elArr1 : arr1)
		{
			for (auto elArr2 : arr2)
			{
				if (elArr1 == elArr2)
				{
					if (std::find(arr3.begin(), arr3.end(), elArr1) == arr3.end())
						arr3.emplace_back(elArr1);

					break;
				}

			}
		}

		printArr("Arr3: ", arr3);
	}
}