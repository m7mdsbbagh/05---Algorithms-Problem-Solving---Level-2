#include <iostream>
using namespace std;

int readPosNum(string message)
{
	int num = 0;

	do {

		cout << message << " : ";
		cin >> num;

	} while (num <= 0);

	return num;
}

void printInvertedLetterPattern(int num)
{
	for (int i = 65 + num - 1; i > 64; i--)
	{
		for (int j = 0; j < num - (65 + num - 1 - i); j++)
		{
			cout << static_cast<char>(i);
		}

		cout << endl;
	}
}

int main()
{
	printInvertedLetterPattern(readPosNum("Please Enter a Digit"));

	return 0;
}