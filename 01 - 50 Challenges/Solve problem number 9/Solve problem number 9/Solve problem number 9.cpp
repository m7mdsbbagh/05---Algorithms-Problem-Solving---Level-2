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

int digitFrequency(int mainNum, int targetDigit)
{
	int frequency = 0, remainder = 0;

	while (mainNum > 0)
	{
		remainder = mainNum % 10;
		mainNum /= 10;

		if (remainder == targetDigit)
			frequency++;
	}

	return frequency;
}

void frequencyEachDigit(int mainNum)
{
	for (int targetDigit = 0; targetDigit < 10; targetDigit++)
	{
		if (digitFrequency(mainNum, targetDigit) == 0) continue;

		cout << "Digit " << targetDigit << " Frequency Is (" <<
			digitFrequency(mainNum, targetDigit) << ") Time";

		if (digitFrequency(mainNum, targetDigit) >= 3)
			cout << "s";

		cout << "." << endl;
	}
}

int main()
{
	int mainNum = readPosNum("Enter a number");

	cout << "\n\n==============================\n";

	frequencyEachDigit(mainNum);

	
	return 0;
}