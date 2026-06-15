#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int randomNum(int from, int to)
{
	return rand() % (to - from + 1) + from;
}

int readPosNum(string message)
{
	int num = 0;

	do {

		cout << message << " : ";
		cin >> num;

	} while (num < 1);

	return num;
}

void swap(int& a, int& b)
{
	int temp = b;

	b = a;

	a = temp;
}

void array1ToNum(int arr[], int num)
{
	for (int i = 0; i < num; i++)
		arr[i] = i + 1;
}

void printArray(int arr[], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
		cout << " " << arr[i];
}

void shuffleArray(int arr[], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		int index1 = randomNum(1, arrLength) - 1;
		int index2 = randomNum(1, arrLength) - 1;

		swap(arr[index1], arr[index2]);
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int arrLength = readPosNum("Enter Number Of Elements"),
		arr[100] = { 0 };

	cout << "\n\n------------------------\n";

	array1ToNum(arr, arrLength);

	cout << "Array Elements Before Shuffle : ";
	printArray(arr, arrLength);

	cout << "\n\n------------------------\n";

	shuffleArray(arr, arrLength);

	cout << "Array Elements After Shuffle  : ";
	printArray(arr, arrLength);

	return 0;
}