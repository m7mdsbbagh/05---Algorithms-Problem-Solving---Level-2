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

void printInvertedPattern(int digit)
{
	for (int j = digit; j > 0; j--)
	{
		for (int i = 1; i <= j; i++)
		{
			cout << j;
		}

		cout << endl;
	}
}

int main()
{
	printInvertedPattern(readPosNum("Please Enter a Digit"));
}