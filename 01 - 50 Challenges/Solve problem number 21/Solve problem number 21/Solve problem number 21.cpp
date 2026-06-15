#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int randomNum(int from, int to)
{
	return rand() % (to - from + 1) + from;
}

enum enCharType
{
	SamallLetter = 1,
	CapitalLetter = 2, 
	SpecialCharacter = 3,
	Digit = 4
};

char getRandomCharacter(enCharType charType)
{
	switch (charType)
	{
		case enCharType::SamallLetter:
			return static_cast<char>(randomNum(97, 122));

		case enCharType::CapitalLetter:
			return static_cast<char>(randomNum(65, 90));

		case enCharType::SpecialCharacter:
			return static_cast<char>(randomNum(33, 47));

		case enCharType::Digit:
			return static_cast<char>(randomNum(48, 57));
	}
}

int readPosNum(string message)
{
	int num = 0;

	do {

		cout << message << " : ";
		cin >> num;

	} while (num <= 0);

	return num;
}

string generateWord(enCharType charType,short lenght)
{
	string word = "";

	for (int i = 1; i <= lenght; i++)
	{
		word.append(1, getRandomCharacter(charType));
	}

	return word;
}

string generateKey()
{
	string key = "";

	for (int i = 0; i < 3; i++)
	{
		key.append(generateWord(enCharType::CapitalLetter, 4), 0, 4);

		if (i < 2)
			key += '-';
	}

	return key;
}

void generateKeys(short numOfKeys)
{
	for (int i = 1; i <= numOfKeys; i++)
	{
		cout << "Key [" << i << "]: " << generateKey() << "\n";
	}
}


int main()
{
	srand((unsigned)time(NULL));


	short numOfKeys = readPosNum("Enter How Many Keys To Generate");

	cout << "\n\n-------------------------------\n";

	generateKeys(numOfKeys);

	return 0;
}