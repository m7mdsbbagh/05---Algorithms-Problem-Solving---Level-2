#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int readNumInRange(string message, int from, int to)
{
	int num = 0;

	do
	{
		cout << message;
		cin >> num;

	} while (num < from || num > to);

	return num;
}

int randomNum(int from, int to)
{
	return rand() % (to - from + 1) + from;
}

void fillArr(int arr[], unsigned short arrLength)
{
	for (int i = 0; i < arrLength; i++)
		arr[i] = randomNum(1, 100);
}

void addArrayElement(int num, int copiedArr[], unsigned short& copyArrLength)
{
	copiedArr[copyArrLength] = num;
	copyArrLength++;
}

void copyArr(int arr[], int copiedArr[], unsigned short arrLength, unsigned short& copyArrLength)
{
	for (int i = 0; i < arrLength; i++)
		addArrayElement(arr[i], copiedArr, copyArrLength);
}

void printArr(int arr[], unsigned short arrLength)
{
	for (int i = 0; i < arrLength; i++)
		cout << " " << arr[i];

	cout << "\n";
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100] = { 0 },
		copiedArr[100] = { 0 };

	unsigned short copyArrLength = 0,
		arrLength = readNumInRange("Enter number of elements     : ", 0, 100);

	fillArr(arr, arrLength);

	cout << "Array 1 elements             :";
	printArr(arr, arrLength);               
		                                    
	copyArr(arr, copiedArr, arrLength, copyArrLength);
	                                        
	cout << "Array 2 elements after copy  :";
	printArr(copiedArr, copyArrLength);


	return 0;
}