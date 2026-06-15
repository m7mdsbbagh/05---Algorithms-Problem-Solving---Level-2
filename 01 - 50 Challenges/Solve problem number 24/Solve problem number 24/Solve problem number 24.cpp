#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int randomNum(int from, int to)
{
	return rand() % (to - from + 1) + from;
}

void fillArrayWithRandomNumbers(int arr[100], int& length)
{
	cout << "Enter Number Of Elements : ";
	cin >> length;

	for (int i = 0; i < length; i++)
		arr[i] = randomNum(1, 100);
}

void printArrays(int arr[100], int length)
{
	cout << "Array Elements :";

	for (int i = 0; i < length; i++)
		cout << " " << arr[i];
}

int maxNum(int arr[100], int length)
{
	int max = arr[0];

	for (int i = 1; i < length; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}

	return max;
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100], length;

	fillArrayWithRandomNumbers(arr, length);

	cout << "\n\n----------------------------\n";

	printArrays(arr, length);

	cout << "\nMax Number is : " << maxNum(arr, length) << endl;

	return 0;
}