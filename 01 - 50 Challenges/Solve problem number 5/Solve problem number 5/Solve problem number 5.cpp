#include <iostream>
using namespace std;

int readPosNum(string message)
{
	int num = 0;

	do {

		cout << message;
		cin >> num;

	} while (num <= 0);

	return num;
}

void printDigits(int num)
{
	int re = 0;

	while (num > 0)
	{
		re = num % 10;
		cout << re << endl;
		num /= 10;
		
	}
}

int main()
{
	printDigits(readPosNum("Enter a Positive Number : "));

	return 0;
}