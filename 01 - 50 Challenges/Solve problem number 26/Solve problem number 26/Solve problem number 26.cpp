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

int sumArrays(int arr[100], int arrLength)
{
	int sum = 0;

	for (int i = 0; i < arrLength; i++)
	{
		sum += arr[i];
	}

	return sum;
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

	cout << "Sum : " << sumArrays(arr, arrLength) << endl;

	return 0;
}