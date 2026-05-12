#include"Practice1.h"

namespace Practice1
{
	static const std::string errorMSG{ "Error, try again!" };

	bool isSandwitch(const std::string& data)
	{
		char edge{ data[0] }, middle{ data[data.size() / 2] };

		if (edge == middle) return false;

		if (data.size() < 3) return false;

		for (const char& el : data)
			if (el != edge && el != middle)
				return false;

		for (int i = 0; i < data.size() / 2; ++i)
			if (data[i] != data[data.size() - i - 1])
				return false;

		return true;
	}

	void sandwitch()
	{
		std::cout << "Enter strnig: ";
		std::string data;
		std::getline(std::cin, data);
		std::cout << "This " << (isSandwitch(data) ? "is" : "isn\'t") << " sandwihc\n";
	}

	////////////////////////////////////////////////////////////

	int getInt()
	{
		while (true)
		{
			int number;
			std::cin >> number;
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(32767, '\n');
				std::cerr << errorMSG << " getInt cin fail\n";
			}

			return number;
		}
	}

	int getSize()
	{
		while (true)
		{
			std::cout << "Enter size: ";
			int size{ getInt() };

			std::cin.ignore();
			if (std::cin.gcount() > 1)
				std::cout << errorMSG << " getSize gcount error\n";
			else if (size < 1)
				std::cerr << errorMSG << " getSize less than zero\n";
			else
				return size;
		}
	}

	int* getArr(const int size)
	{
		int* arr = new int[size] {};
		while (true)
		{
			std::cout << "Enter array: ";
			int count{ 0 };
			while (count < size)
			{
				arr[count] = getInt();
				if (arr[count] < 0)
					std::cout << errorMSG << " Value less than zero\nEnter array: ";
				else
					++count;
			}

			std::cin.ignore(32767, '\n');
			if (std::cin.gcount() > 1)
				std::cout << errorMSG << " numbers more than size\n";
			else
				return arr;
		}
	}

	int getMin(const int* const arr, const int size)
	{
		int min = arr[0];
		for (int i = 1; i < size; ++i)
			if (arr[i] < min)
				min = arr[i];
		return min;
	}

	void minNumber()
	{
		int size{ getSize() };
		int* arr{ getArr(size) };

		std::cout << "Array: ";
		for (int i = 0; i < size; ++i)
			std::cout << arr[i] << ' ';
		std::cout << '\n';

		std::cout << "Min number in arr is " << getMin(arr, size) << '\n';

		delete[]arr;
	}

	//////////////////////////////////////////////////////////////

	void season()
	{
		int num(0);
		while (true)
		{
			std::cout << "Enter number (1-12): ";
			num = getInt();
			std::cin.ignore(32767, '\n');
			if (num < 1 || num>12)
				std::cout << errorMSG << " invalid mounth value\n";
			else if (std::cin.gcount() > 1)
				std::cout << errorMSG << " season gcount fail\n";
			else
				break;
		}

		switch (num)
		{
		case 12:
		case 1:
		case 2:
			std::cout << "Winter\n";
			break;
		case 3:
		case 4:
		case 5:
			std::cout << "Spring\n";
			break;
		case 6:
		case 7:
		case 8:
			std::cout << "Summer\n";
			break;
		case 9:
		case 10:
		case 11:
			std::cout << "Autumn\n";
			break;
		default:
			std::cout << "X3\n";
			break;
		}
	}
}