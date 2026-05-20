#include"Practice10.h"

namespace Practice10
{
	std::list<double> getList(const std::string& output)
	{
		while (true)
		{
			std::cout << output;
			std::string input;
			std::getline(std::cin, input);
			std::istringstream isInput{ input };
			std::string sNumber;

			std::list<double> numbers;
			bool success{ true };
			while (isInput >> sNumber)
			{
				double number(0);
				size_t index;
				try
				{
					number = std::stod(sNumber, &index);
					if (index < sNumber.length()) throw std::runtime_error("Stod error!");
				}
				catch (const std::exception& ex)
				{
					std::cerr << ex.what() << '\n';
					success = false;
					break;
				}
				catch (...)
				{
					std::cerr << "Error...\n";
					success = false;
					break;
				}

				numbers.emplace_back(number);
			}
			
			if (!numbers.empty() && success)
				return numbers;
			else if (numbers.empty())
			{
				std::cerr << "Numbers is empty!\n";
			}
			else if (!success)
			{
				std::cerr << "Success is false!\n";
			}
			else
			{
				std::cerr << "Error unknown!\n";
			}
		}
	}

	double getAverage(const std::list<double>numbers)
	{
		double sum(0);
		for (const double el : numbers)
			sum += el;
		return sum / numbers.size();
	}

	void averageDouble()
	{
		std::list<double> numbers{ getList("Enter numbers(double): ") };

		std::cout << "Array: ";
		std::cout << std::fixed;
		for (const double el : numbers)
			std::cout<<std::setprecision(1) << el << ' ';
		std::cout << std::endl;

		std::cout << "Average of array = " << getAverage(numbers) << '\n';
	}

	////////////////////////////////////////////////////////////////////

	bool validNumber(const int number)
	{
		std::string str{ std::to_string(number) };
		return str.size() == 6;
	}

	int getNumber(const std::string& output)
	{
		while (true)
		{
			std::cout << output;
			int number;
			std::cin >> number;

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
					std::cerr << "Error, gcount fail!\n";
				}
				else
				{
					if (!validNumber(number))
						std::cerr << "Error, invalid number!\n";
					else
						return number;
				}
			}
		}
	}

	bool checkNumber(const int value)
	{
		int number(value);
		const int SIZE(6);
		int num[SIZE];

		for (int i = 0;i < SIZE;++i)
		{
			num[i] = number % 10;
			number /= 10;
		}

		int sum1(0), sum2(0);
		for (int i = 0;i < SIZE / 2;++i)
		{
			sum1 += num[i];
			sum2 += num[i + 3];
		}

		return sum1 == sum2;
	}

	void isHappyNumber()
	{
		int number{ getNumber("Enter number(6-digits): ") };
		std::cout << "Number: " << number << '\n';

		std::cout << "Number " << (checkNumber(number) ? "is" : "is not") << " happy\n";
	}

	//////////////////////////////////////////////////////////////////

	const int w_name(10), w_year(8), w_rating(10), size(10);

	struct Student
	{
		std::string m_name{"test"};
		int m_year;
		std::array<int, 5>m_rating;

		Student()
			:m_year(0), m_rating{}{ }

		Student(const std::string& name, const int year)
			:m_name{ name }, m_year(year), m_rating{ } {
		}

		Student(const std::string& name, const int year, const std::array<int, 5>& rating)
			:m_name{ name }, m_year(year), m_rating{ rating }{ }

		friend std::ostream& operator<<(std::ostream& out, const Student& st)
		{
			out << std::setw(w_name) << st.m_name << std::setw(w_year) << st.m_year;
			for (int i = 0;i < st.m_rating.size();++i)
				out << st.m_rating[i] << ' ';

			return out;
		}
	};

	void print(std::array<Student, size>& stud)
	{
		std::cout << std::fixed<<std::left;
		std::cout << std::setw(w_name) << "Name" << std::setw(w_year) << "Year" << std::setw(w_rating) << "Rating" << std::endl;
		for (const auto& el : stud)
			std::cout << el << '\n';
	}

	void students()
	{
		std::array<Student, size>stud
		{
			Student("a",1,{1,1,1,1,1}),
			Student("b",1,{1,1,1,1,1}),
			Student("c",1,{1,1,1,1,1}),
			Student("d",1,{1,1,1,1,1}),
			Student("e",1,{1,1,1,1,1}),
			Student("f",1,{1,1,1,1,1}),
			Student("g",1,{1,1,1,1,1}),
			Student("h",1,{1,1,1,1,1}),
			Student("i",1,{1,1,1,1,1}),
			Student("j",1,{1,1,1,1,1}),
		};



		print(stud);
	}
}