#include <iostream>
#include <string>
#include <cstdlib>
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

		cout << message << " : ";
		cin >> num;

	} while (num < from || num > to);

	return num;
}

void fillArrayWithRandomNumbers(int arr[], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
		arr[i] = randomNum(1, 100);
}

void sum2Array(int arr1[], int arr2[], int arrSum[], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
		arrSum[i] = arr1[i] + arr2[i];
}

void printArray(int arr[], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
		cout << " " << arr[i];
}

int main()
{
	srand((unsigned)time(NULL));

	int arrLength = readNumInRange("How Many Elements", 1, 100),
		arr1[100] = { 0 },
		arr2[100] = { 0 },
		arrSum[100] = { 0 };

	fillArrayWithRandomNumbers(arr1, arrLength);
	fillArrayWithRandomNumbers(arr2, arrLength);
	sum2Array(arr1, arr2, arrSum, arrLength);

	cout << "\n---------------------------------\n";

	cout << "Array 1 Elements:";
	printArray(arr1, arrLength);

	cout << "\n---------------------------------\n";

	cout << "Array 2 Elements:";
	printArray(arr2, arrLength);

	cout << "\n---------------------------------\n";

	cout << "Sum of Array 1 and Array2 Elements:";
	printArray(arrSum, arrLength);

	cout << "\n---------------------------------\n";

	return 0;
}