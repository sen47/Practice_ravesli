#include"Practice6.h"

namespace Practice6
{
	void getTwoNumbers(int& first, int& second)
	{
		while (true)
		{
			std::cout << "Enter two integer: ";
			std::string input;
			std::getline(std::cin, input);
			std::istringstream is{ input };
			std::string number;

			is >> number;
			size_t index;

			int temp(0);
			try
			{
				temp = std::stoi(number, &index);
				if (index != number.length()) throw std::runtime_error("Error, first extraction!");
			}
			catch (const std::exception& ex)
			{
				std::cerr << ex.what() << '\n';
				continue;
			}
			catch (...)
			{
				std::cerr << "Error..." << '\n';
				continue;
			}

			first = temp;

			is >> number;
			try
			{
				temp = std::stoi(number, &index);
				if (index != number.length()) throw std::runtime_error("Error, second extraction!");
			}
			catch (const std::exception& ex)
			{
				std::cerr << ex.what() << '\n';
				continue;
			}
			catch (...)
			{
				std::cerr << "Error..." << '\n';
				continue;
			}

			second = temp;

			if (!is.eof())
			{
				std::cerr << "Error, not eof()\n";
				continue;
			}
			else
				break;
		}
	}

	void lessNumber()
	{
		int first(0), second(0);
		getTwoNumbers(first, second);

		std::cout << first << ((first < second) ? " less than " : " more than ") << second << '\n';
	}

	/////////////////////////////////////////////////////



	/////////////////////////////////////////////////////

	class Ticket
	{
		struct Passenger
		{
			friend std::ostream& operator<<(std::ostream& out, const Passenger& passenger)
			{
				out << passenger.m_secondName + " " + passenger.m_firstName.at(0) + ". " + passenger.m_fatherName.at(0) + ".";
				return out;
			}

			std::string m_firstName, m_fatherName, m_secondName;

			Passenger(const std::string& firstName, const std::string& fatherName, const std::string& secondName)
				:m_firstName{ firstName }, m_fatherName{ fatherName }, m_secondName{ secondName } {
			}
		};

		struct Date
		{
			friend std::ostream& operator<<(std::ostream& out, const Date& date)
			{
				out << std::to_string(date.m_day) + "/" + std::to_string(date.m_mounth) + "/" + std::to_string(date.m_year);
				return out;
			}

			int m_day, m_mounth, m_year;

			Date(const int day, const int mounth, const int year)
				:m_day(day), m_mounth(mounth), m_year(year) {
			}
		};

		Passenger m_passenger;
		Date m_date;
		int m_flightNumber;
		std::string m_destiny;

	public:
		Ticket(const std::string& firstName, const std::string& fatherName, const std::string& secondName, const int day, const int mounth, const int year, const int flightNumber, const std::string destiny)
			:m_passenger{ firstName,fatherName,secondName }, m_date{ day,mounth,year }, m_flightNumber(flightNumber), m_destiny{ destiny } {
		}

		const Passenger& getPassenger()const { return m_passenger; }
		const int getFlightNumber()const { return m_flightNumber; }
		int getFlightNumber() { return m_flightNumber; }
		const Date& getDate()const { return m_date; }
		const std::string& getDestiny()const { return m_destiny; }
	};

	class Flight_base
	{
		std::list<Ticket> m_flight;

	public:
		void addTicket(const Ticket& ticket) { m_flight.emplace_back(ticket); }

		void deleteTicket(const int flightNumber)
		{
			m_flight.remove_if([flightNumber](Ticket& ticket) {
				return ticket.getFlightNumber() == flightNumber;
				});
		}

		void printFlight()
		{
			const int fn(5), da(10), de(10), pa(20);
			std::cout << std::setw(fn) << std::left << "F.N" << std::setw(da) << "Date" << std::setw(de) << "Destiny" << std::setw(pa) << "Passenger" << std::endl;
			for (const auto& el : m_flight)
				std::cout << std::setw(fn) << std::left << el.getFlightNumber() << std::setw(da) << el.getDate() << std::setw(de) << el.getDestiny() << std::setw(pa) << el.getPassenger() << std::endl;
		}

	};

	void flight()
	{
		Flight_base flight;
		flight.addTicket(Ticket{ "Aleksandr","Vladimirovich","Vorontsov",1,1,2026,123,"Moscow" });
		flight.addTicket(Ticket{ "James","A","Johnes",1,1,2026,234,"Tokio" });
		flight.addTicket(Ticket{ "Richard","B","Bush",1,1,2026,345,"New York" });
		flight.addTicket(Ticket{ "Andy","C","Prime",1,1,2026,456,"Paris" });
		flight.addTicket(Ticket{ "Amy","D","Black",1,1,2026,567,"London" });

		flight.printFlight();
		std::cout << "\n-------------------------\n";

		flight.deleteTicket(345);

		flight.printFlight();
		std::cout << "\n-------------------------\n";

		flight.addTicket(Ticket{ "Carol","E","Widik",1,1,2026,678,"Brasilia" });

		flight.printFlight();
		std::cout << "\n-------------------------\n";
	}
}