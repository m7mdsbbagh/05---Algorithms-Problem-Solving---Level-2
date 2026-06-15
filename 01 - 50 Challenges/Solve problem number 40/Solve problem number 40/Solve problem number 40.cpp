#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iterator>
using namespace std;

void fillArrayAndArrLength(int arr[], short &arrLength)
{
	arrLength = 10;

	int temp[] = { 10, 10, 10, 50, 50, 70, 70, 70, 70, 90 };

	copy(begin(temp), end(temp), arr);
}

void addArrayElement(int num, int copiedArr[], short& copiedArrLength)
{
	copiedArr[copiedArrLength] = num;
	copiedArrLength++;
}

bool isNumInArr(int num, int arr[], short arrLength)
{
	for (int i = 0; i < arrLength; i++)
		if (num == arr[i])
			return true;

	return false;
}

void copyArrayWithoutDuplicates(int originalArr[], int copiedArr[], short arrLength, short& copiedArrLength)
{
	for (int i = 0; i < arrLength; i++)
		if (!isNumInArr(originalArr[i], copiedArr, copiedArrLength))
			addArrayElement(originalArr[i], copiedArr, copiedArrLength);
}

void printArr(int arr[], short arrLength)
{
	for (int i = 0; i < arrLength; i++)
		cout << " " << arr[i];

	cout << endl;
}

int main()
{
	short arrLength = 0,
		copiedArrLength = 0;

	int originalArr[100] = { 0 },
		copiedArr[100] = { 0 };

	fillArrayAndArrLength(originalArr, arrLength);
	copyArrayWithoutDuplicates(originalArr, copiedArr, arrLength, copiedArrLength);

	cout << "\nArray 1 elements:\n";
	printArr(originalArr, arrLength);

	cout << "\nArray 2 distinct numbers:\n";
	printArr(copiedArr, copiedArrLength);

	return 0;
}