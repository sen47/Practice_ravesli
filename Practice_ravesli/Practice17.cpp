#include"Practice17.h"

namespace Practice17
{
	static std::random_device rd;
	static std::mt19937 mers(rd());

	int getRand()
	{
		return 1 + mers() % 10;
	}

	void averageInRand()
	{
		std::cout << "Random numbers: ";
		double sum(0);
		int num(0);
		for (int i = 0;i < 10;++i)
		{
			num = getRand();
			std::cout << num << ' ';
			sum += num;
		}

		std::cout << "\nAverage = " << sum / 10 << '\n';
	}

	////////////////

	void swapMinMax()
	{
		const int SIZE(9);
		int arr[9];

		std::cout << "Arr: ";
		int indexMin(0), indexMax(0);
		for (int i = 0;i < SIZE;++i)
		{
			arr[i] = getRand();
			std::cout << arr[i] << ' ';
			if (arr[i] < arr[indexMin])
				indexMin = i;
			else if (arr[i] > arr[indexMax])
				indexMax = i;
		}

		std::swap(arr[indexMin], arr[indexMax]);
		
		std::cout << "\nAfter swap: ";
		for (int i = 0;i < SIZE;++i)
			std::cout << arr[i] << ' ';
	}
}