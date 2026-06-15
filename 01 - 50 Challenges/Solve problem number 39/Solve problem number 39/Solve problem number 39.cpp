#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

enum enPrimeOrNot { NotPrime, Prime };

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

void fillArray(int arr[], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
		arr[i] = randomNum(1, 100);
}

void sortArray(int arr[], short arrLength)
{
	sort(arr, arr + arrLength);
}

void addArrayElement(int num, int copiedArr[], short& copiedArrLength)
{
	copiedArr[copiedArrLength] = num;
	copiedArrLength++;
}

enPrimeOrNot checkPrime(int num)
{
	if (num <= 1)
		return enPrimeOrNot::NotPrime;

	for (int i = 2; i * i <= num; i++)
		if (num % i == 0)
			return enPrimeOrNot::NotPrime;

	return enPrimeOrNot::Prime;
}

void copyPrimeNums(int arr[], short arrLength, int copiedArr[], short& copiedArrLength)
{
	for (int i = 0; i < arrLength; i++)
		if (checkPrime(arr[i]) == enPrimeOrNot::Prime)
			addArrayElement(arr[i], copiedArr, copiedArrLength);
}

void printArr(int arr[], short arrLength)
{
	for (int i = 0; i < arrLength; i++)
		cout << " " << arr[i];

	cout << endl;
}

int main()
{
	srand((unsigned)time(NULL));

	short arrLength = readNumInRange("Enter number of elements (1-100): ", 0, 100),
		copiedArrLength = 0;

	int arr[100] = { 0 },
		copiedArr[100] = { 0 };

	fillArray(arr, arrLength);
	sortArray(arr, arrLength);
	copyPrimeNums(arr, arrLength, copiedArr, copiedArrLength);

	cout << "\nArray 1 elements:\n";
	printArr(arr, arrLength);

	cout << "\nArray 2 prime numbers:\n";
	printArr(copiedArr, copiedArrLength);

	return 0;
}