#include <iostream>
#include <string>
using namespace std;

int readNum(string message)
{
	int num = 0;

	cout << message;
	cin >> num;

	return num;
}

int readNumInRange(string message, int from, int to)
{
	int num = 0;

	do {

		cout << message;
		cin >> num;

	} while (num < from || num > to);

	return num;
}

void fillArrayFromUser(int arr[], short arrLength)
{
	for (int i = 0; i < arrLength; i++)
		arr[i] = readNum("Enter number [" + to_string(i + 1) + "]: ");
}

bool isPalindromeArray(int arr[], short arrLength)
{
	for (int i = 0; i < arrLength / 2; i++)
		if (arr[i] != arr[arrLength - 1 - i])
			return false;

	return true;
}

void printArr(int arr[], short arrLength)
{
	for (int i = 0; i < arrLength; i++)
		cout << arr[i] << " ";

	cout << endl;
}

int main()
{
	short arrLength = readNumInRange("Enter Number Of Elements (1 - 100): ", 1, 100);
	int arr[100] = { 0 };

	cout << "\n";

	fillArrayFromUser(arr, arrLength);

	cout << endl;

	cout << "Array Elements:\n";
	printArr(arr, arrLength);

	if (isPalindromeArray(arr, arrLength))
		cout << "\nYes, the array is Palindrome!\n";
	else
		cout << "\nNo, the array is NOT Palindrome!\n";

	return 0;
}