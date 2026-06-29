#include"Practice22.h"

namespace Practice22
{
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
				else
					return input;
			}
		}
	}

	void allDeviders()
	{
		int num(getInt("Enter number: "));
		std::cout << "Number - " << num << ", deviders: ";
		for (int i = 1;i <= num / 2;++i)
		{
			if (!(num % i))
				std::cout << i << ' ';
		}
		std::cout << '\n';
	}

	//////////////////

	int getQuant(const std::string& output)
	{
		while (true)
		{
			int input(getInt(output));
			if (input <= 0)
				std::cerr << "Error, invalid value, value <= 0!\n";
			else
				return input;
		}
	}

	void fibbo()
	{
		int quant(getQuant("Enter quantity of fibonachi numbers to show: "));
		int previous(1),current(1);
		
		std::cout << "First " << quant << " numbers of fibonachi subsiquence: ";
		
		switch(quant)
		{
		case 1:
			std::cout << previous << '\n';
			break;
		case 2:
			std::cout << previous << ' ' << current << '\n';
			break;
		default:
			std::cout << previous << ' ' << current << ' ';

			for (int i = 2;i < quant;++i)
			{
				int temp(previous + current);
				std::cout << temp << ' ';
				previous = current;
				current = temp;
			}
		}
	}
}