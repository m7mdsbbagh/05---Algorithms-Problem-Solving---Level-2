#include <iostream>
#include <cmath>
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

int reverseNumber(int num)
{
	int remainder = 0, num2 = 0;

	while (num > 0)
	{
		remainder = num % 10;
		num /= 10;

		num2 = 10 * num2 + remainder;
	}

	return num2;
}

void printDigits(int num)
{
	int remainder = 0;

	while (num > 0)
	{
		remainder = num % 10;
		cout << remainder << endl;

		num /= 10;
	}
}

int main()
{
	int num = readPosNum("Enter a positive number");

	cout << "\n=====\n";

	printDigits(reverseNumber(num));

	return 0;
}