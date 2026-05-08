#include"Practice8.h"

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
			{
				std::cerr << "Error, gcount error!\n";
			}
			else
			{
				return input;
			}
		}
	}
}

void copEnding()
{
	int number(0);

	for (int i = 1;i < 100;++i)
	{
		number = i;

		/*while (true)
		{
			number = getInt("Enter number from 1 to 99: ");

			if (number > 0 && number < 100)
				break;

			std::cerr << "Error, invalid value, try again!\n";
		}*/

		SetConsoleOutputCP(65001);
		std::cout << std::setw(2) << std::left << number << ' ';

		std::string str;
		if (number >= 11 && number <= 14)
			str = "копеек";
		else
		{
			switch (number % 10)
			{
			case 1:
			{
				str = "копейка";
				break;
			}
			case 2:
			case 3:
			case 4:
			{
				str = "копейки";
				break;
			}
			case 5:
			case 6:
			case 7:
			case 8:
			case 9:
			case 0:
			{
				str = "копеек";
				break;
			}
			default:
				str = "error!";
			}
		}

		std::cout << str << '\n';
	}

}

////////////////////////////////////////////

bool isPalindrom(const int number)
{
	int digits(0), num(number);
	do
	{
		++digits;
	} while (num /= 10);

	if (digits < 2)
		return false;

	bool isPalindrom(true);
	std::string str(std::to_string(number));
	for (int i = 0;i < str.length();++i)
	{
		if (str[i] != str[str.length() - 1 - i])
		{
			isPalindrom = false;
			break;
		}
	}

	return isPalindrom;
}

void palindrom()
{
	int number{ getInt("Enter number: ") };
	std::cout << number << (isPalindrom(number) ? " is " : " isn\'t ") << "palindrom\n";
}

////////////////////////////////////////////

int getScoreWithExp(const int examPoints, const int expirience)
{
	int coef = ((expirience >= 2) ? 16 : (expirience == 1) ? 13 : 1);
	return examPoints * coef;
}

bool isValidPoints(int examPoints)
{
	if (examPoints >= 3 && examPoints <= 5)
		return true;

	return false;
}

void bacalavrCoef()
{
	std::string notPass{ "Sorry, you don\'t pass!" };
	
	int point(getInt("Enter exam points: "));
	if (!isValidPoints(point))
	{
		std::cout << notPass << '\n';
		return;
	}
	
	int exp(getInt("Enter experience: "));

	std::cout << "Your rating is " << getScoreWithExp(point, exp) << '\n';

	if (getScoreWithExp(point, exp) >= 45)
	{
		std::cout << "Congrat, you pass!\n";
	}
	else
	{
		std::cout << notPass << '\n';
	}
}