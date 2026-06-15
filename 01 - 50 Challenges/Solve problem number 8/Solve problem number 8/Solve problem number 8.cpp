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

int digitFrequency(int targetDigit, int mainNum)
{
	int frequency = 0, remainder = 0;

	while (targetDigit > 0)
	{
		remainder = targetDigit % 10;
		targetDigit /= 10;

		if (remainder == mainNum)
			frequency++;
	}

	return frequency;
}

int main()
{
	int targetDigit = readPosNum("Enter a number");
	int mainNum = readPosNum("Enter the digit you want to check its frequency");

	cout << "\n\n================================\n";

	cout << "Digit " << mainNum << " Frequency Is (" <<
		digitFrequency(targetDigit, mainNum) << ") Time";

	if (digitFrequency(targetDigit, mainNum) >= 3)
		cout << "s";

	cout << "." << endl;

	return 0;
}