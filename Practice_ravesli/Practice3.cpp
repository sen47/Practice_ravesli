#include"Practice3.h"

template<typename T>
T getValue(const std::string& output)
{
	while (true)
	{
		std::cout << output;
		T input;
		std::cin >> input;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cerr << "Error get value, cin fail, try again!\n";
		}
		else
		{
			std::cin.ignore(32767, '\n');
			if (std::cin.gcount() > 1)
			{
				std::cerr << "Error get value, gcount fail, try again!\n";
			}
			else
				return input;
		}
	}
}

bool approxymatelyEqualsAbsRel(double a, double b, double absEpsilon = 1e-12, double relEpsilon = 1e-8)
{
	double diff(fabs(a - b));
	if (diff <= absEpsilon)
		return true;

	return diff <= ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * relEpsilon);
}

bool checkTime(double time)
{
	time -= static_cast<int>(time);
	//std::cout << "time -= static_cast<int>(time) = " << time << '\n';
	time *= 100;
	//std::cout << "time *= 100 = " << time << '\n';

	return (time < 60) || approxymatelyEqualsAbsRel(time, 60);
}

double toSecond(double time)
{
	return (time - static_cast<int>(time)) * 100 + static_cast<int>(time) * 60;
}

void speed()
{
	double distance{ getValue<double>("Enter distance (m): ") };
	double time(0);
	while (true)
	{
		time = getValue<double>("Enter time (m.s): ");
		if (checkTime(time))
			break;
		else
			std::cout << "Error, invalid time, try again!\n";
	}

	std::cout << "Your speed is " << std::fixed << std::setprecision(2) << distance / toSecond(time) * 3.6 << " km/h\n";
}

//////////////////////////////////////////////////////////////////////

void sumOfFirstN()
{
	int num{ getValue<int>("Enter summing numbers count: ") };

	int sum(0);
	for (int i(2), count(0); count < num; i += 2, ++count)
		sum += i;

	std::cout << "Sum of first " << num << " even positive integers = " << sum << '\n';
}

/////////////////////////////////////////////////////////////////////