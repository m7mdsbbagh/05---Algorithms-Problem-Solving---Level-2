#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int randomNum(int from, int to)
{
	return rand() % (to - from + 1) + from;
}

void fillArrayWithRandomNumbers(int arr[], int& arrLength)
{
	cout << "\nEnter number of elements: ";
	cin >> arrLength;

	for (int i = 0; i < arrLength; i++)
		arr[i] = randomNum(1, 100);
}

void printArrays(int arr[], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
		cout << " " << arr[i];
}

void copyArrays(int arr[], int copyArr[], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
		copyArr[i] = arr[i];
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100] = { 0 },
		copyArr[100] = { 0 },
		arrLength = 0;

	fillArrayWithRandomNumbers(arr, arrLength);

	cout << "\n\n---------------------------------\n";

	cout << "\nArray 1 Elements:";
	printArrays(arr, arrLength);

	cout << "\n\n---------------------------------\n";

	copyArrays(arr, copyArr, arrLength);
	cout << "\nArray 2 Elements:";
	printArrays(copyArr, arrLength);

	cout << "\n\n---------------------------------\n";
	
	return 0;
}