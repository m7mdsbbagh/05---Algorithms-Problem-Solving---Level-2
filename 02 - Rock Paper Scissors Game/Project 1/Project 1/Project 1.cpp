#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <windows.h>
using namespace std;

enum enRockPaperScissors { ROCK = 1, PAPER, SCISSORS };
enum enWinner { PLAYER, COMPUTER, DRAW };

struct stRound
{
	enRockPaperScissors playerMove = enRockPaperScissors::ROCK,
		computerMove = enRockPaperScissors::ROCK;

	enWinner winner = enWinner::DRAW;
};

struct stGame
{
	short playerWonCount = 0,
		computerWonCount = 0,
		drawCount = 0,
		totalRounds = 0;

	enWinner finalWinner = enWinner::DRAW;
};

int randomNum(int from, int to)
{
	return rand() % (to - from + 1) + from;
}

int readNumInRange(int from, int to, string message)
{
	int num = 0;

	do {
		cout << message;
		cin >> num;

	} while (num < from || num > to);

	return num;
}

bool isContinue(string message)
{
	string yOrN = "no";

	cout << message;
	cin >> yOrN;

	return tolower(yOrN[0]) == 'y';
}

enRockPaperScissors getMove(short move)
{
	return static_cast<enRockPaperScissors>(move);
}

void getWinnerRound(stRound &round)
{
	if (round.playerMove == round.computerMove)
	{
		round.winner = enWinner::DRAW;
		return;
	}

	switch (round.playerMove)
	{
		case enRockPaperScissors::ROCK:
			round.winner = round.computerMove == enRockPaperScissors::SCISSORS ? enWinner::PLAYER : enWinner::COMPUTER;
			break;

		case enRockPaperScissors::SCISSORS:
			round.winner = round.computerMove == enRockPaperScissors::PAPER ? enWinner::PLAYER : enWinner::COMPUTER;
			break;

		case enRockPaperScissors::PAPER:
			round.winner = round.computerMove == enRockPaperScissors::ROCK ? enWinner::PLAYER : enWinner::COMPUTER;
	}
}

void processRound(stRound round, stGame& game)
{
	if (round.winner == enWinner::PLAYER)
	{
		system("color 2F");
		game.playerWonCount++;
		Beep(1000, 200);
	}

	else if (round.winner == enWinner::COMPUTER)
	{
		system("color 4F");
		game.computerWonCount++;
		Beep(400, 500);
	}

	else
	{
		system("color 6F");
		game.drawCount++;
	}
}

void getPlayersMoves(stRound &round)
{
	cout << "\t\t\tY o u r   C h o i c e\n";
	cout << "\t\t\t---------------------\n";

	short playerChoice = readNumInRange(1, 3, "\t\t\t'1' : RocK\n\t\t\t'2' : Paper\n\t\t\t'3' : Scissors\n\t\t\t--> ");
	round.playerMove = getMove(playerChoice);

	short computerChoice = randomNum(1, 3);
	round.computerMove = getMove(computerChoice);
}

void roundInfo(stRound round)
{
	string strWinner[] = { "Player", "Computer" , "No Winner" };
	string strMove[] = { "Rock", "Paper", "Scissors" };

	cout << "\t\t\tP l a y e r   C h o i c e     : " << strMove[round.playerMove - 1] << endl;
	cout << "\t\t\tC o m p u t e r   C h o i c e : " << strMove[round.computerMove - 1];
	cout << "\n\t\t\tR o u n d   W i n n e r       : " << strWinner[round.winner] << "\n";
}

void eachRound(stRound &round, stGame &game)
{
	game.totalRounds = readNumInRange(1, 20, "How many rounds do you want to play? (1 to 20): ");

	for (short count = 1; count <= game.totalRounds; count++)
	{
		system("color 0F");
		system("cls");

		cout << "\n\n\t\t\t++ R o u n d  [ " << count << " ]  B e g i n s ++\n\n";

		getPlayersMoves(round);

		cout << "\n\t\t\t++------------R o u n d  [ " << count << " ]------------++\n" << endl;

		getWinnerRound(round);
		processRound(round, game);

		roundInfo(round);

		cout << "\n\t\t\t++----------------------------------------++\n";

		cout << "\n\t\t\t";
		system("pause");
	}
}

void getFinalWinner(stGame &game)
{
	game.finalWinner = game.playerWonCount > game.computerWonCount ? enWinner::PLAYER :
		game.computerWonCount > game.playerWonCount ? enWinner::COMPUTER : enWinner::DRAW;
}

void showGameOver(stGame game)
{
	system("color 0F");

	getFinalWinner(game);

	string strWinner[] = {"Player", "Computer" , "No Winner"};

	system("cls");

	cout << "\n\n\t\t\t=================================================\n";
	cout << "\t\t\t||               +++ GAME OVER +++             ||\n";
	cout << "\t\t\t-------------------------------------------------\n";

	cout << "\t\t\t|| " << setw(25) << left << "Game Rounds" << " : " << setw(15) << left << game.totalRounds << " ||\n";
	cout << "\t\t\t|| " << setw(25) << left << "Player Won Times" << " : " << setw(15) << left << game.playerWonCount << " ||\n";
	cout << "\t\t\t|| " << setw(25) << left << "Computer Won Times" << " : " << setw(15) << left << game.computerWonCount << " ||\n";
	cout << "\t\t\t|| " << setw(25) << left << "Draw Times" << " : " << setw(15) << left << game.drawCount << " ||\n";
	cout << "\t\t\t|| " << setw(25) << left << "Final Winner" << " : " << setw(15) << left << strWinner[game.finalWinner] << " ||\n";

	cout << "\t\t\t=================================================\n\n";
}

void startGame()
{
	bool playAgain;

	do {
		system("cls");
		stRound round;
		stGame game;

		eachRound(round, game);
		showGameOver(game);

		playAgain = isContinue("Do you want to play again?\n");

	} while (playAgain);

}

int main()
{
	srand((unsigned)time(NULL));

	startGame();

	return 0;
}