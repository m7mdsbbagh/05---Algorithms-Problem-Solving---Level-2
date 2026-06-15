#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;

int randomNum(int from, int to)
{
	return rand() % (to - from + 1) + from;
}

int readNumInRange(string message, int from, int to)
{
	int num = 0;

	do {

		cout << message;
		cin >> num;

	} while (num < from || num > to);

	return num;
}

void fillArray(int arr[], unsigned int arrLength)
{
	for (unsigned int i = 0; i < arrLength; i++)
		arr[i] = randomNum(1, 100);
}

void printArray(int arr[], unsigned int arrLength)
{
	cout << "Array elements :";

	for (unsigned int i = 0; i < arrLength; i++)
		cout << " " << arr[i];
}

int findNum(int arr[], unsigned int arrLength, int targetNum)
{
	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] == targetNum)
			return i;
	}

	return -1;
}

bool isNumInArr(int arr[], unsigned int arrLength, int targetNum)
{
	return findNum(arr, arrLength, targetNum) != -1;
}

void printFindResult(int arr[], unsigned int arrLength, unsigned int targetNum)
{
	cout << "Number you are looking for is: " << targetNum << "\n";

	if (isNumInArr(arr, arrLength, targetNum))
		cout << "Yes, the number is found :)\n";
	else
		cout << "No, the number is NOT found :(\n";
}

int main()
{
	srand((unsigned)time(NULL));

	unsigned short arrLength = readNumInRange("Enter number of elements: ", 1, 100);

	int arr[100] = { 0 };

	fillArray(arr, arrLength);

	cout << endl;

	printArray(arr, arrLength);

	cout << "\n\n";

	unsigned short targetNum = readNumInRange("Please enter a number to search for it: ", 1, 100);

	cout << "\n";

	printFindResult(arr, arrLength, targetNum);

	cout << "\n";
}