#include <iostream>
#include <windows.h>

using namespace std;

enum enGameElements { Stone = 1, Paper = 2, Scissors = 3 };

struct stGameResults
{
	short GameRounds,
		Player1Won,
		CouputerWon,
		DrawTimes;
	string FinalWinner;
};

short RandomNumber(short From, short To)
{
	short randomNumber = rand() % (To - From + 1) + From;

	return randomNumber;
}

short ReadNumberInRange(string message, short From, short To)
{
	short Number;
	do
	{
		cout << message;
		cin >> Number;

	} while (Number < From || Number > To);

	return Number;
}

short ReadHowManyRounds()
{
	return ReadNumberInRange("How many round from 1 to 10 ? : ", 1, 10);
}

string GetGameElementName(enGameElements GameElements)
{
	switch (GameElements)
	{
	case enGameElements::Stone:
		return " Stone";
	case enGameElements::Paper:
		return " Paper";
	case enGameElements::Scissors:
		return " Scissors";
	}
}

short GetComputerChoice()
{
	return (enGameElements)RandomNumber(1, 3);
}

short GetPlayer1Choice()
{
	return (enGameElements)ReadNumberInRange(
		"Your choice : [1]:Stone, [2]:Paper [3]Scissors ? : ",
	1,3);
}

string DetermineRoundWinner(enGameElements player, enGameElements computer)
{
	if (player == computer)
	{
		system("color 6F");
		return " Draw [No Winner]";	
	}

	if ((player == Scissors && computer == Paper) ||
		(player == Stone && computer == Scissors) ||
		(player == Paper && computer == Stone))
	{
		system("color 2F");
		return " Player";
		
	}
	else
	{
		MessageBeep(MB_ICONASTERISK);
		system("color 4F");
		return " Computer";
		
	}
}

string DetermineFinallWinner(stGameResults &Results)
{
	if (Results.Player1Won > Results.CouputerWon)
	{
		system("color 2F");
		return " Player";
	}
	else if (Results.CouputerWon > Results.Player1Won)
	{
		MessageBeep(MB_ICONASTERISK);
		system("color 4F");
		return " Computer";
	}
	else
	{
		system("color 6F");
		return " Draw [No Winner]";
	}
}

void GameOverOnScreen()
{
	cout << "\n--------------------------------------------------\n";
	cout << "\n         +++ G  A  M  E   O  V  E  R +++          \n";
	cout << "\n--------------------------------------------------\n";
}

stGameResults ShowGameResults(stGameResults &GameResults)
{
	cout << "\n-------------------[ Game Results ]----------------------\n";
	cout << "\nGame Rounds : " << GameResults.GameRounds << endl;
	cout << "\nPlayer1 Won Times : " << GameResults.Player1Won << endl;
	cout << "\nComputer Won Times : " << GameResults.CouputerWon << endl;
	cout << "\nDraw Times : " << GameResults.DrawTimes << endl;
	cout << "\nFinall Winner : " << GameResults.FinalWinner << endl;

	return GameResults;
}

char RestartRequest()
{
	char RestartRequest;

	do
	{
		cout << "\n\nDo you want to restart the game? Y/N : ";
		cin >> RestartRequest;
		RestartRequest = toupper(RestartRequest);

	} while (RestartRequest != 'Y' && RestartRequest != 'N');

	return RestartRequest;
}

void ResetConsoleColor()
{
	system("Cls");
	system("Color 07");
}

void PlayGame()
{
	stGameResults GameResult = { 0, 0, 0, 0, ""};


	GameResult.GameRounds = ReadHowManyRounds();
	short RoundCounter = 1;

	for (short i = 1; i <= GameResult.GameRounds; i++)
	{
		cout << "\n\nRound [" << i << "] begins : \n";

		cout << "\n---------------Round [" << i << "]-----------------\n";
		
		enGameElements PlayerChoice = (enGameElements)GetPlayer1Choice();
		enGameElements ComputerChoice = (enGameElements)GetComputerChoice();
		string RoundWinner = DetermineRoundWinner(PlayerChoice, ComputerChoice);

		cout << "\nPlayer1 Choice : " << GetGameElementName(PlayerChoice) << endl;
		cout << "\nComputer Choice : " << GetGameElementName(ComputerChoice) << endl;
		cout << "\nRound Winner : " << RoundWinner << endl;

		if (RoundWinner == " Player")
			GameResult.Player1Won++;
		else if (RoundWinner == " Computer")
			GameResult.CouputerWon++;
		else
			GameResult.DrawTimes++;

		RoundCounter++;

	}

	GameResult.FinalWinner = DetermineFinallWinner(GameResult);

	GameOverOnScreen();
	ShowGameResults(GameResult);
	

}

void StartGame()
{
	char playagain;
	do
	{
		ResetConsoleColor();
		PlayGame();
		playagain = RestartRequest();

	} while (playagain == 'Y');
}


int main()
{
	srand((unsigned)time(NULL));
	StartGame();

	return 0;
}