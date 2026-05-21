#include"Practice11.h"

namespace Practice11
{
	double getDouble(const std::string& output)
	{
		while (true)
		{
			std::cout << output;
			double input;
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

	void convert()
	{
		double weight(getDouble("Enter weight in pounds: "));
		std::cout << "Weight in kg = " << std::fixed << std::setprecision(3) << weight * 0.453 << '\n';
	}

	////////////////////////////////////////////////////

	void yearCost()
	{
		double mounthScholarship(getDouble("Enter scholarship value: "));
		double mounthExpenses(getDouble("Enter mounth expenses: "));

		double yearScholarship(mounthScholarship * 10);
		double yearExpenses(0);
		for (int i = 0;i < 10;++i)
		{
			yearExpenses += mounthExpenses;
			mounthExpenses *= 1.03;
		}

		std::cout << std::fixed << std::setprecision(2)
			<< "Year scholarship = " << yearScholarship
			<< "\nYear expenses = " << yearExpenses
			<< "\nMissing amount = " << yearExpenses - yearScholarship << '\n';
	}

	///////////////////////////////////////////////////


}