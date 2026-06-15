#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

int readNumInRange(string message, int from, int to)
{
	int num = 0;

	do {
		cout << message;
		cin >> num;

	} while (num < from || num > to);

	return num;
}

int randomNum(int from, int to)
{
	return rand() % (to - from + 1) + from;
}

void sortArray(int arr[], short arrLength)
{
	sort(arr, arr + arrLength);
}

void fillArrWithRandomNums(int arr[], short arrLength)
{
	for (short i = 0; i < arrLength; i++)
		arr[i] = randomNum(-100, 100);
}

void printArr(int arr[], short arrLength)
{
	for (short i = 0; i < arrLength; i++)
		cout << arr[i] << " ";

	cout << endl;
}

bool isPosNum(int num)
{
	return num > 0;
}

short countByCondition(int arr[], short arrLength, bool (*condition)(int))
{
	short count = 0;

	for (short i = 0; i < arrLength; i++)
		if (condition(arr[i]))
			count++;

	return count;
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100] = { 0 };
	short arrLength = readNumInRange("Enter number of elements (1 - 100): ", 1, 100);

	fillArrWithRandomNums(arr, arrLength);
	sortArray(arr, arrLength);

	short countPosNum = countByCondition(arr, arrLength, isPosNum);

	cout << "\nArray Elements:\n";
	printArr(arr, arrLength);

	cout << "\nThe count of positive numbers is: " << countPosNum << endl;

	return 0;
}