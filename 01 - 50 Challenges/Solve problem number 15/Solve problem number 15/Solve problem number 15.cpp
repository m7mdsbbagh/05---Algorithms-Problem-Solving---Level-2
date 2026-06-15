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

void printLetterPattern(int num)
{
	for (int i = 65; i <= 65 + num - 1; i++)
	{
		for (int j = 0; j < i - (65 - 1); j++)
		{
			cout << static_cast<char>(i);
		}

		cout << endl;
	}
}

int main()
{
	printLetterPattern(readPosNum("Please Enter a Digit"));

	return 0;
}