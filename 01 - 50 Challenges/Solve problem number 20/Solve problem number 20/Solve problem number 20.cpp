#include <iostream>
#include <cstdlib>
using namespace std;

int randomNum(int from, int to)
{
	return rand() % (to - from + 1) + from;
}

enum enCharType {SmallLetter = 1, CapitalLetter, SpecialCharacter, Digit};

char getRandomCharacter(enCharType charType)
{
	switch (charType)
	{
		case enCharType::SmallLetter:
			return static_cast<char>(randomNum(97, 122));

		case enCharType::CapitalLetter:
			return static_cast<char>(randomNum(65, 90));

		case enCharType::SpecialCharacter:
			return static_cast<char>(randomNum(33, 47));

		case enCharType::Digit:
			return static_cast<char>(randomNum(48, 57));
	}
}

int main()
{
	srand((unsigned)time(NULL));

	cout << getRandomCharacter(enCharType::SmallLetter) << "\n";
	cout << getRandomCharacter(enCharType::CapitalLetter) << "\n";
	cout << getRandomCharacter(enCharType::SpecialCharacter) << "\n";
	cout << getRandomCharacter(enCharType::Digit) << "\n";

	return 0;
}