#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

enum enPrimeOrNot { Prime = 1, NotPrime };

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

enPrimeOrNot isPrimeOrNot(int numInArr)
{
	if (numInArr == 1)
		return enPrimeOrNot::NotPrime;

	for (int i = 2; i * i <= numInArr; i++)
	{
		if (numInArr % i == 0)
			return enPrimeOrNot::NotPrime;
	}

	return enPrimeOrNot::Prime;
}

void copyArrays(int arr[], int copyArr[], int arrLength, int &copyArrLength)
{
	int counter = 0;

	for (int i = 0; i < arrLength; i++)
	{
		if (isPrimeOrNot(arr[i]) == enPrimeOrNot::Prime)
		{
			copyArr[counter] = arr[i];
			counter++;
		}
	}

	copyArrLength = counter;
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100] = { 0 },
		copyArr[100] = { 0 },
		arrLength = 0,
		copyArrLength = 0;

	fillArrayWithRandomNumbers(arr, arrLength);

	cout << "\n\n---------------------------------\n";

	cout << "\nArray Elements:";
	printArrays(arr, arrLength);

	cout << "\n\n---------------------------------\n";

	copyArrays(arr, copyArr, arrLength, copyArrLength);

	cout << "Prime Numbers in Arrays 2:";
	printArrays(copyArr, copyArrLength);

	cout << "\n\n---------------------------------\n";

	return 0;
}