#include"Practice13.h"

namespace Practice13
{
	void evenAndMultiple()
	{
		std::cout << "Even numbers multiple to 5, from 2 to 100:\n";
		for (int i = 2;i <= 100;++i)
		{
			if (!(i % 2 || i % 5))
				std::cout << i << '\n';
		}
	}

	//////////////////////////////////

	bool isHappy(const std::array<int, 6>&arr)
	{
		return arr[0] + arr[1] + arr[2] == arr[3] + arr[4] + arr[5];
	}

	bool isDD(const std::array<int, 6>& arr)
	{
		return arr[0] + arr[1] + arr[2] == 13;
	}

	void printArr(const std::array<int, 6>& arr, const int num)
	{
		std::cout << "Ticket #" << num << ": ";
		for (const int el : arr)
			std::cout << el;
		std::cout << '\n';
	}

	void happyTicket()
	{
		std::array<int, 6>ticket{};
		
		int countHappy(0), countCommon(0), currentDigit(0);
		
		for (ticket[0] = 0;ticket[0] <= 9;++ticket[0])
			for (ticket[1] = 0;ticket[1] <= 9;++ticket[1])
				for (ticket[2] = 0;ticket[2] <= 9;++ticket[2])
					for (ticket[3] = 0;ticket[3] <= 9;++ticket[3])
						for (ticket[4] = 0;ticket[4] <= 9;++ticket[4])
							for (ticket[5] = 0;ticket[5] <= 9;++ticket[5])
							{
								++countCommon;

								if (isHappy(ticket) && isDD(ticket))
								{
									++countHappy;
									printArr(ticket, countHappy);
								}
							}

		std::cout << "Common count = " << countCommon << '\n';
	}
}