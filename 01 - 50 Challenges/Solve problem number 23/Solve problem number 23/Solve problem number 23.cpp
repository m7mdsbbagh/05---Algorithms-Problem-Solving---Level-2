#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int randomNum(int from, int to)
{
	return rand() % (to - from + 1) + from;
}

void fillArrayWithRandomNumbers(int arr[100], int& arrLength)
{
	cout << "Enter Number Of Elements : ";
	cin >> arrLength;

	for (int i = 0; i < arrLength; i++)
		arr[i] = randomNum(1, 100);
}

void printArray(int arr[100], int arrLength)
{ 
	for (int i = 0; i < arrLength; i++)
		cout << " " << arr[i];

	cout << endl;
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100] = { 0 },
		arrLength = 0;

	fillArrayWithRandomNumbers(arr, arrLength); 

	cout << "Arry Element :";
	printArray(arr, arrLength);

	return 0;
}