#include"Practice20.h"

namespace Practice20
{
	bool isLeap(const int year)
	{
		if (!(year % 4))
		{
			if (!(year % 400))
				return true;
			else if (!(year % 100))
				return false;
			else
				return true;
		}

		return false;
	}

	class Date
	{
		enum MounthNum { Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };
		int MaxDays[13]{ 0, 31,28,31,30,31,30,31,31,30,31,30,31 };

		int m_day, m_mounth, m_year;
		
		bool checkMounth()
		{
			return m_mounth > 0 && m_mounth <= 12;
		}

		bool checkDay()
		{
			return m_day > 0 && m_day <= MaxDays[m_mounth];
		}

	public:
		Date(const int day, const int mounth, const int year)
			:m_day(day), m_mounth(mounth), m_year(year) 
		{
			if (isLeap(m_year))
				MaxDays[Feb] = 29;

			if (year < 1)throw std::runtime_error("Invalid year");
			if (!checkMounth())throw std::runtime_error("Invalid mounth");
			if (!checkDay())throw std::runtime_error("Invalid day");
		}

		Date getNextDay()
		{
			int day(m_day), mounth(m_mounth), year(m_year);

			if (day == MaxDays[m_mounth])
			{
				day = 1;
				if (mounth == Dec)
				{
					mounth = Jan;
					++year;
				}
				else
				{
					++mounth;
				}
			}
			else
			{
				++day;
			}

			return Date(day, mounth, year);
		}

		friend std::ostream& operator<<(std::ostream& out, const Date& date)
		{
			out << date.m_day << '/' << date.m_mounth << '/' << date.m_year;
			return out;
		}
	};

	Date getDate(const std::string&output)
	{
		while (true)
		{
			enum date_value { Day, Mounth, Year, MaxValue };
			std::cout << output;
			std::string input_str;
			std::getline(std::cin, input_str);
			std::istringstream input_stream(input_str);
			std::string num_str;

			int value;
			size_t pos;
			bool success(true);
			
			int date[date_value::MaxValue]{};
			for (int i = 0;i < date_value::MaxValue;++i)
			{
				input_stream >> num_str;

				try
				{
					value = std::stoi(num_str, &pos);
					if (pos != num_str.size())throw std::runtime_error("pos fail");
					date[i] = value;
				}
				catch (const std::exception& ex)
				{
					std::cerr << "Error, " << ex.what() << "!\n";
					success = false;
					break;
				}
				catch (...)
				{
					std::cerr << "Error...!\n";
					success = false;
					break;
				}

			}

			try
			{
				Date(date[date_value::Day], date[date_value::Mounth], date[date_value::Year]);
			}
			catch (const std::exception& ex)
			{
				std::cerr << "Error, " << ex.what() << "!\n";
				success = false;
			}

			if (success) return Date(date[date_value::Day], date[date_value::Mounth], date[date_value::Year]);
		}
	}

	void nextDate()
	{
		Date d{ getDate("Enter date: ") };
		std::cout << "Current day: " << d << '\n';
		std::cout << "Next day: " << d.getNextDay() << '\n';
	}

	/////////////////////////

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

	void intToHex()
	{
		int num(getInt("Enter number: "));
		//std::cout << "Hex = " << std::hex << num << '\n';
		std::cout << "Hex = " << std::format("{:x}", num) << '\n';
	}
}