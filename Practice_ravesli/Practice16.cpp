#include"Practice16.h"

namespace Practice16
{
	std::list<int> getArr(const std::string& output)
	{
		while (true)
		{
			std::cout << output;
			std::string input_str;
			std::getline(std::cin, input_str);
			std::istringstream input_stream{ input_str };
			std::string number_str;
			std::list<int>arr;

			bool sucsess(true);
			while (input_stream >> number_str)
			{
				size_t index(0);
				try
				{
					int number_int(std::stoi(number_str, &index));
					if (index < number_str.size()) throw std::runtime_error("Index error!");

					arr.emplace_back(number_int);
				}
				catch (const std::exception& ex)
				{
					std::cerr << "Error! " << ex.what() << " Try again!" << '\n';
					sucsess = false;
					break;
				}
				catch (...)
				{
					std::cerr << "Error...! Try again!\n";
					sucsess = false;
					break;
				}
			}

			if (sucsess && !arr.empty())
				return arr;
			else if (sucsess && arr.empty())
				std::cerr << "Error, empty arr!\n";
		}
	}

	void getMin()
	{
		std::list<int>arr{ getArr("Enter numbers: ") };

		int* array = new int[arr.size()];
		int index(0);
		for (std::list<int>::iterator iter(arr.begin());iter != arr.end();++iter, ++index)
		{
			array[index] = *iter;
		}

		std::cout << "Your array: ";
		for (int i = 0;i < arr.size();++i)
			std::cout << array[i] << ' ';
		std::cout << '\n';

		int* pMin(array);
		for (int i = 0;i < arr.size();++i)
			if (array[i] < *pMin)
				pMin = &array[i];

		std::cout << "Min = " << *pMin << '\n';

		delete[]array;
	}
}