#include"Practice14.h"

namespace Practice14
{
	int getInt(const std::string& output)
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
			{
				std::cerr << "Error, gcount error!\n";
			}
			else
				return input;
		}
	}

	void bacteryCount()
	{
		int minutes(getInt("Enter time (m): "));
		int bactery(1);

		std::cout << "At start bactery count = " << bactery << '\n';

		for (int i = 1;i <= minutes;++i)
		{
			bactery = bactery * 2;
			std::cout << "After " << i << " minute bactery count = " << bactery << '\n';
		}		
	}

	////////////////////////////////////////////

	int countSeconds(const int h, const int m, const int s)
	{
		return s + (m * 60) + (h * 60 * 60);
	}

	void getSeconds()
	{
		int h(getInt("Enter hours (h): "));
		int m(getInt("Enter minutes (m): "));
		int s(getInt("Enter seconds (s): "));

		std::cout << h << "h:" << m << "m:" << s << "s = " << countSeconds(h, m, s) << " seconds\n";
	}

	///////////////////////////////////////////


}