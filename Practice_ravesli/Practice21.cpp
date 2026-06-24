#include"Practice21.h"

namespace Practice21
{
	void printArray(const std::vector<int>& array)
	{
		for (const auto el : array)
			std::cout << el << ' ';
		std::cout << '\n';
	}

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
				std::cerr << "Error, cin fail\n";
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

	void operationsWithArray()
	{
		std::vector<int>array{ 1, 1, 2, 4, 5, 9, 14, 22, 37, 54, 87, 90, 111, 243, 345 };
		printArray(array);

		std::cout << "Elements of array > 5: ";
		for (const auto el : array)
			if (el > 5)
				std::cout << el << ' ';
		std::cout << '\n';

		int maxEl(getInt("Enter max number: "));

		std::cout << "Elements of array < " << maxEl << ':';
		for (auto el : array)
			if (el < maxEl)
				std::cout << el << ' ';
		std::cout << '\n';		
	}

	/////////////////////////////

	enum Result { Paper, Scissors, Rock, MaxResult };
	enum ResultState { Draw, WinPlayer, WinPc };
	static std::string resultNames[Result::MaxResult]{ "Paper", "Scissors", "Rock" };

	static std::random_device rd;
	static std::mt19937 mers(rd());

	Result getPcResult()
	{
		return static_cast<Result>(mers() % Result::MaxResult);
	}

	/*int getInt(const std::string& output)
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
	}*/

	Result getPlayerResult(const std::string& output)
	{
		while(true)
		{
			int input(getInt(output));
			if (input < Result::Paper || input >= Result::MaxResult)
				std::cerr << "Error, invalid input!\n";
			else
				return static_cast<Result>(input);
		}
	}

	bool isPlayerWin(const Result resultPlayer, const Result resultPc)
	{
		if ((resultPlayer == Result::Rock && resultPc == Result::Paper) ||
			(resultPlayer == Result::Paper && resultPc == Result::Rock))
			return resultPlayer < resultPc;
		else
			return resultPlayer > resultPc;
	}

	ResultState whoWin(const Result resultPlayer, const Result resultPc)
	{
		if (resultPlayer == resultPc)
			return ResultState::Draw;
		else
			if (isPlayerWin(resultPlayer, resultPc))
				return ResultState::WinPlayer;
			else
				return ResultState::WinPc;
	}

	bool endGame(const std::string& output)
	{
		while (true)
		{
			int input(getInt(output));
			if (input < 0 || input>1)
				std::cerr << "Error, invalid input!\n";
			else
				return !input;
		}
	}

	void rockPaperScisors()
	{
		while (true)
		{
			Result resultPlayer(getPlayerResult("Enter your choise(0 - Paper, 1 - Scissors, 2 - Rock): ")),
				resultPc(getPcResult());
			
			std::cout << "Your choise - " << resultNames[resultPlayer] << ", pc choise - " << resultNames[resultPc] << '\n';

			switch (whoWin(resultPlayer,resultPc))
			{
			case ResultState::Draw:
				std::cout << "Draw, nobody wins!\n";
				break;
			case ResultState::WinPlayer:
				std::cout << "Congratulations, you win!\n";
				break;
			case ResultState::WinPc:
				std::cout << "Sorry, you lose!\n";
				break;
			default:
				std::cerr << "Error, default switch!\n";
			}	

			if (endGame("Do you want to play again?(0 - no/1 - yes): "))
				break;
		}
	}
}