#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

enum enCharType
{
	smallLetter = 1,
	capitalLetter,
	specialChar,
	digit
};

int random(int from, int to)
{
	return rand() % (to - from + 1) + from;
}

char getRandomChar(enCharType charType)
{
	switch (charType)
	{
		case enCharType::smallLetter:
			return static_cast<char>(random(97, 122));

		case enCharType::capitalLetter:
			return static_cast<char>(random(65, 90));

		case enCharType::specialChar:
			return static_cast<char>(random(33, 47));

		case enCharType::digit:
			return static_cast<char>(random(48, 57));
	}
}

void printStringArray(string arr[], int arrLength)
{
	cout << "\nArray elements:\n";

	for (int i = 0; i < arrLength; i++)
	{
		cout << "Array[" << i << "] : " << arr[i] << "\n";
	}
}

string generateWord(enCharType charType, int charLength)
{
	string word = "";

	for (int i = 0; i < charLength; i++)
	{
		word.append(1, getRandomChar(charType));
	}

	return word;
}

string generateKey(int keyLength)
{
	string key = "";

	for (int i = 0; i < keyLength; i++)
	{
		key.append(generateWord(enCharType::capitalLetter, 4));

		if (i != keyLength - 1)
			key.append("-");
	}

	return key;
}

void fillStrArrayWithKeys(string arr[], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		arr[i] = generateKey(4);
	}
}

int readPosNum(string message)
{
	int num = 0;

	do
	{
		cout << message;
		cin >> num;

	} while (num <= 0);

	return num;
}

int main()
{
	srand((unsigned)time(NULL));

	int numOfElements = readPosNum("How many keys do you want to generate? ");
	string strArr[100] = { "" };

	cout << "\n\n------------------------\n";

	fillStrArrayWithKeys(strArr, numOfElements);
	printStringArray(strArr, numOfElements);

	return 0;
}