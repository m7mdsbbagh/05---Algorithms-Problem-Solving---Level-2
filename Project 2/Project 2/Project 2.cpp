#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <windows.h>
#include <cmath>
using namespace std;

enum enLvlQuestion { EASY = 1, MED, HARD, MIX_LVL };
enum enOpType { ADD = 1, SUB, MUL, DIV, MIX_OP };

struct stQuestionInfo
{
	int num1 = 0,
		num2 = 0,
		correctAns = 0,
		playerAns = 0;
	enOpType operationType;
	bool isCorrect = false;
	enLvlQuestion questionLvl;
};

struct stQuizInfo
{
	stQuestionInfo q[100];
	enOpType opType;
	enLvlQuestion questionsLvl;
	short numOfQuestions = 0,
		rightAnsCount = 0,
		wrongAnsCount = 0;
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

int readNum(string message)
{
	int num = 0;

	cout << message;
	cin >> num;

	return num;
}

bool isContinue(string message)
{
	string yOrN = "no";

	cout << message;
	cin >> yOrN;

	return tolower(yOrN[0]) == 'y';
}

void swap(int& num1, int& num2)
{
	int temp = 0;

	temp = num1;
	num1 = num2;
	num2 = temp;
}

short readNumOfQuestions()
{
	return readNumInRange(1, 100, "Enter Number of Questions (1 to 100) : ");
}

enLvlQuestion toEnLvlQuestion(short lvl)
{
	return static_cast<enLvlQuestion>(lvl);
}

enLvlQuestion readLvlQuestion()
{
	short lvl = readNumInRange(1, 4, "\nEnter Questions Level:\n[1] Easy\n[2] Med\n[3] Hard\n[4] Mix\n--> ");
	return toEnLvlQuestion(lvl);
}

enOpType toEnOpType(short opType)
{
	return static_cast<enOpType>(opType);
}

enOpType readOpType()
{
	short op = readNumInRange(1, 5, "\nEnter Operation Type:\n[1] Add\n[2] Sub\n[3] Mul\n[4] Div\n[5] Mix\n--> ");
	return toEnOpType(op);
}

char getOpChar(enOpType opType)
{
	switch (opType)
	{
	case enOpType::ADD: return '+';
	case enOpType::SUB: return '-';
	case enOpType::MUL: return '*';
	case enOpType::DIV: return '/';
	default: return '?';
	}
}

int calculate(int num1, int num2, char opChar)
{
	switch (opChar)
	{
	case '+': return num1 + num2;

	case '-': return num1 - num2;

	case '*': return num1 * num2;

	case '/': return num1 / num2;
	}
	return 0;
}

bool isCorrectAnswer(short& rightAnsCount, short& wrongAnsCount, int playerAns, int correctAns)
{
	if (playerAns == correctAns)
	{
		system("color 2F");
		rightAnsCount++;
		Beep(1000, 200);
		return true;
	}

	system("color 4F");
	wrongAnsCount++;
	Beep(400, 500);
	return false;
}

void generateAddOperands(enLvlQuestion lvl, int& num1, int& num2)
{
	switch (lvl)
	{
		case enLvlQuestion::EASY:
		{
			short choice = randomNum(1, 3);

			switch (choice)
			{
				case 1:
					num1 = randomNum(0, 10);
					num2 = randomNum(0, 10);
					break;

				case 2:
					num1 = randomNum(11, 100);
					num2 = randomNum(0, 5);
					if (randomNum(1, 2) == 1)
						swap(num1, num2);
					break;

				case 3:
					num1 = randomNum(1, 10) * 10;
					num2 = randomNum(1, 10) * 10;
					break;
			}
			break;
		}

		case enLvlQuestion::MED:
			do
			{
				num1 = randomNum(11, 49);
				num2 = randomNum(11, 50);

			} while (num1 % 10 == 0 || num2 % 10 == 0);
			break;

		case enLvlQuestion::HARD:
			do
			{
				num1 = randomNum(51, 99);
				num2 = randomNum(51, 99);

			} while (num1 % 10 == 0 || num2 % 10 == 0 || num1 == num2);
			break;
	}
}

void generateSubOperands(enLvlQuestion lvl, int& num1, int& num2)
{
	switch (lvl)
	{
		case enLvlQuestion::EASY:
		{
			short choice = randomNum(1, 3);

			switch (choice)
			{
				case 1:
					num1 = randomNum(0, 10);
					num2 = randomNum(0, 10);
					if (num1 < num2)
						swap(num1, num2);
					break;

				case 2:
					num1 = randomNum(11, 100);
					num2 = randomNum(0, 3);
					break;

				case 3:
					if (randomNum(1, 2) == 1)
					{
						num1 = randomNum(0, 9) * 10;
						num2 = randomNum(0, 9) * 10;
						if (num1 < num2)
							swap(num1, num2);
					}
					else
					{
						num1 = randomNum(0, 100);
						num2 = num1;
					}
					break;
			}
			break;
		}
		default:
			do
			{
				num1 = lvl == enLvlQuestion::MED ? randomNum(11, 49) : randomNum(51, 99);
				num2 = lvl == enLvlQuestion::MED ? randomNum(11, 49) : randomNum(51, 99);

			} while (num1 % 10 == 0 || num2 % 10 == 0 || num1 == num2 ||
				(lvl == enLvlQuestion::HARD && abs(num1 - num2) <= 3));
			break;
	}
}

void generateMulOperands(enLvlQuestion lvl, int& num1, int& num2)
{
	short choice = randomNum(1, 2);

	switch (lvl)
	{
		case enLvlQuestion::EASY:
		{
			switch (choice)
			{
				case 1:
					num1 = randomNum(0, 10);
					num2 = randomNum(0, 10);
					break;

				case 2:
					if (randomNum(1, 2) == 1)
					{
						num1 = randomNum(0, 100);
						num2 = randomNum(0, 1);
					}
					else
					{
						num1 = randomNum(0, 10) * 10;
						num2 = randomNum(0, 10);
					}
					break;
			}
			break;
		}
		case enLvlQuestion::MED:
		{
			switch (choice)
			{
				case 1:
					do
					{
						num1 = randomNum(11, 49);
						num2 = randomNum(3, 9);

					} while (num1 % 10 == 0);
					break;

				case 2:
					num1 = randomNum(2, 10) * 10;
					num2 = randomNum(2, 10) * 10;
					break;
			}
			break;
		}
		case enLvlQuestion::HARD:
		{
			do
			{
				num1 = randomNum(11, 49);
				num2 = randomNum(11, 29);

			} while (num1 % 10 == 0 || num2 % 10 == 0);
			break;
		}
	}
}

void generateDivOperands(enLvlQuestion lvl, int& num1, int& num2)
{
	int expectedAns = 0;

	switch (lvl)
	{
		case enLvlQuestion::EASY:
		{
			short choice = randomNum(1, 3);

			switch (choice)
			{
				case 1:
					num2 = randomNum(1, 10);
					expectedAns = randomNum(0, 10);
					num1 = num2 * expectedAns;
					break;

				case 2:
					num1 = randomNum(0, 1000);
					num2 = (randomNum(1, 2) == 1) ? 1 : num1;
					break;

				case 3:
					num2 = randomNum(1, 10) * pow(10, randomNum(0, 3));
					expectedAns = randomNum(0, 10);
					num1 = num2 * expectedAns;
					break;
			}
			break;
		}
		case enLvlQuestion::MED:
		{
			num2 = randomNum(2, 9);
			do { expectedAns = randomNum(11, 29); } while (expectedAns % 10 == 0);
			num1 = num2 * expectedAns;
			break;
		}
		case enLvlQuestion::HARD:
		{
			do { num2 = randomNum(11, 25); } while (num2 % 10 == 0);
			do { expectedAns = randomNum(5, 15); } while (expectedAns % 10 == 0);
			num1 = num2 * expectedAns;
			break;
		}
	}
}

void generateOperands(enLvlQuestion lvl, enOpType opType, int& num1, int& num2)
{
	switch (opType)
	{
	case enOpType::ADD:
		generateAddOperands(lvl, num1, num2); break;
	case enOpType::SUB:
		generateSubOperands(lvl, num1, num2); break;
	case enOpType::MUL:
		generateMulOperands(lvl, num1, num2); break;
	case enOpType::DIV:
		generateDivOperands(lvl, num1, num2); break;
	}
}

void generateSingleQuestion(stQuestionInfo& q, enLvlQuestion lvl, enOpType quizOpType)
{
	if (quizOpType == enOpType::MIX_OP)
		q.operationType = toEnOpType(randomNum(1, 4));
	else
		q.operationType = quizOpType;


	if (lvl == enLvlQuestion::MIX_LVL)
		q.questionLvl = toEnLvlQuestion(randomNum(1, 3));
	else
		q.questionLvl = lvl;

	generateOperands(q.questionLvl, q.operationType, q.num1, q.num2);


	char opChar = getOpChar(q.operationType);
	q.correctAns = calculate(q.num1, q.num2, opChar);
}

void question(stQuestionInfo& q)
{
	string message = "   " + to_string(q.num1) + "\n " + getOpChar(q.operationType) +
		" " + to_string(q.num2) + "\n------\n   ";
	
	q.playerAns = readNum(message);
}

void generateQuizQuestions(stQuizInfo& quiz)
{
	for (short index = 0; index < quiz.numOfQuestions; index++)
		generateSingleQuestion(quiz.q[index], quiz.questionsLvl, quiz.opType);
}

string getStatusText(bool condition, string message1, string message2)
{
	return condition ? message1 : message2;
}

void pressEnterToContinue(string message)
{
	cout << message;
	cin.ignore();
	cin.get();
}

string getLvlName(enLvlQuestion lvl)
{
	switch (lvl)
	{
	case enLvlQuestion::EASY: return "Easy";
	case enLvlQuestion::MED: return "Medium";
	case enLvlQuestion::HARD: return "Hard";
	case enLvlQuestion::MIX_LVL: return "Mix";
	default: return "Unknown";
	}
}

string getOpTypeName(enOpType opType)
{
	switch (opType)
	{
	case enOpType::ADD: return "Add";
	case enOpType::SUB: return "Sub";
	case enOpType::MUL: return "Mul";
	case enOpType::DIV: return "Div";
	case enOpType::MIX_OP: return "Mix";
	default: return "Unknown";
	}
}

string displayQuestionLvl(enLvlQuestion quizLvl, enLvlQuestion currentQuestionLvl)
{
	return (quizLvl == enLvlQuestion::MIX_LVL) ? "[ Question Level: " 
		+ getLvlName(currentQuestionLvl) + " ]\n\n" : "";
}

void printQuizQuestions(stQuizInfo& quiz)
{
	for (short index = 0; index < quiz.numOfQuestions; index++)
	{
		short questionNum = index + 1;

		system("cls");
		system("color 0F");

		cout << "Question [" << questionNum << "/" << quiz.numOfQuestions << "]\n\n";

		cout << displayQuestionLvl(quiz.questionsLvl, quiz.q[index].questionLvl);

		question(quiz.q[index]);

		quiz.q[index].isCorrect = isCorrectAnswer(quiz.rightAnsCount, quiz.wrongAnsCount,
			quiz.q[index].playerAns, quiz.q[index].correctAns);

		cout << getStatusText(quiz.q[index].isCorrect,
			"\nRight Answer, Good Job! :)\n",
			"\nWrong Answer :(\nThe Right Answer is: " + to_string(quiz.q[index].correctAns) + "\n");

		if (questionNum < quiz.numOfQuestions)
			pressEnterToContinue("\nPress [Enter] to move to question " + to_string(questionNum + 1));
	}
}

void printQuizDetails(stQuizInfo quiz)
{
	cout << "\n============= QUESTIONS REPORT =============" << endl;

	for (short index = 0; index < quiz.numOfQuestions; index++)
	{
		cout << "\n" << quiz.q[index].num1 << " " << getOpChar(quiz.q[index].operationType)
			<< " " << quiz.q[index].num2 << " = " << quiz.q[index].correctAns;

		cout << "\nYour Answer: " << quiz.q[index].playerAns;

		cout << getStatusText(quiz.q[index].isCorrect, "   [ Correct ]\n", "   [ Wrong ]\n");

		cout << "--------------------------------------------\n";
	}
}

void printQuizResults(stQuizInfo quiz)
{
	cout << "\n=============================================\n";
	cout << "||              QUIZ RESULTS               ||\n";
	cout << "---------------------------------------------\n";

	cout << "|| " << left << setw(22) << "Number of Questions" << " : "
		<< setw(15) << quiz.numOfQuestions << "||\n";
	cout << "|| " << left << setw(22) << "Questions Level" << " : " 
		<< setw(15) << getLvlName(quiz.questionsLvl) << "||\n";
	cout << "|| " << left << setw(22) << "Operation Type" << " : " 
		<< setw(15) << getOpTypeName(quiz.opType) << "||\n";
	cout << "|| " << left << setw(22) << "Right Answers" << " : " 
		<< setw(15) << quiz.rightAnsCount << "||\n";
	cout << "|| " << left << setw(22) << "Wrong Answers" << " : "
		<< setw(15) << quiz.wrongAnsCount << "||\n";

	cout << "=============================================\n";
}

void setScreenColorAndSound(short rightAnswers, short wrongAnswers)
{
	if (rightAnswers > wrongAnswers)
	{
		system("color 2F");

		Beep(523, 100);
		Beep(659, 100);
		Beep(784, 100);
		Beep(1046, 300);
	}
	else if (rightAnswers < wrongAnswers)
	{
		system("color 4F");

		Beep(400, 250);
		Beep(300, 250);
		Beep(200, 250);
		Beep(100, 600);
	}
	else
		system("color 6F");
}

void startQuiz()
{
	stQuizInfo quiz;

	quiz.numOfQuestions = readNumOfQuestions();
	quiz.questionsLvl = readLvlQuestion();
	quiz.opType = readOpType();

	pressEnterToContinue("\nAll set! Press [Enter] to start the quiz...");
	system("cls");

	generateQuizQuestions(quiz);

	printQuizQuestions(quiz);
	pressEnterToContinue("\nQuiz completed! Press [Enter] to view your final results...");
	system("cls");

	setScreenColorAndSound(quiz.rightAnsCount, quiz.wrongAnsCount);
	printQuizResults(quiz);
	pressEnterToContinue("\nPress [Enter] to view the detailed questions report...");
	system("cls");
	system("color 0F");

	printQuizDetails(quiz);
}

int main()
{
	srand((unsigned)time(NULL));

	bool playAgain = false;

	do
	{
		system("cls");

		startQuiz();

		playAgain = isContinue("\nDo you want to start a new quiz ? \n");

	} while (playAgain);

	return 0;
}