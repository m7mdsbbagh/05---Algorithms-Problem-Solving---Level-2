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

void readArr(int arrNum[100], int numOfElements)
{
	for (int i = 0; i < numOfElements; i++)
	{
		cout << "Element [" << i + 1 << "] : ";
		cin >> arrNum[i];
	}
}

void printArr(int arrNum[100], int numOfElements)
{
	for (int i = 0; i < numOfElements; i++)
	{
		cout << arrNum[i] << " ";
	}
}

int countRepeats(int arrNum[100], int repeatedNum, int numOfElements)
{
	int count = 0;

	for (int i = 0; i < numOfElements; i++)
	{
		if (arrNum[i] == repeatedNum)
			count++;
	}

	return count;
}

int main()
{
	int arrNum[100] = { 0 };
	int numOfElements = readPosNum("Enter Number Of Elements");

	cout << "\n--------------------\n";

	cout << "Enter Array Elements:\n";
	readArr(arrNum, numOfElements);

	cout << "\n--------------------\n";

	int repeatedNum = readPosNum("Enter The Number You Want To Check");

	cout << "\n--------------------\n";

	cout << "Original Array: ";
	printArr(arrNum, numOfElements);

	cout << "\n--------------------\n";

	cout << repeatedNum << " is Repeated " << countRepeats(arrNum, repeatedNum, numOfElements) << " Time(s)\n";

	return 0;
}