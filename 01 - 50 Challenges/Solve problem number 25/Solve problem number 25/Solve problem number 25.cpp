#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int randomNum(int from, int to)
{
	return rand() % (to - from + 1) + from;
}

void fillArrayWithRandomNumbers(int arr[100], int& arrLength)
{
	cout << "\nEnter number of elements: ";
	cin >> arrLength;

	for (int i = 0; i < arrLength; i++)
		arr[i] = randomNum(1, 100);
}

void printArrays(int arr[100], int arrLength)
{
	cout << "\nArray Elements:";

	for (int i = 0; i < arrLength; i++)
		cout << " " << arr[i];
}

int minNum(int arr[100], int arrLength)
{
	int min = arr[0];

	for (int i = 1; i < arrLength; i++)
	{
		if (min > arr[i])
			min = arr[i];
	}

	return min;
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100] = { 0 },
		arrLength = 0;

	fillArrayWithRandomNumbers(arr, arrLength);

	cout << "\n\n---------------------------------\n";

	printArrays(arr, arrLength);

	cout << "\n\n---------------------------------\n";

	cout << "Min Number Is : " << minNum(arr, arrLength) << endl;

	return 0;
}