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
		cout << message << ": ";
		cin >> num;

	} while (num < from || num > to);

	return num;
}

short random(int from, int to)
{
	return rand() % (to - from + 1) + from;
}

void fullArray(short arr[], short arrLength)
{
	for (short i = 0; i < arrLength; i++)
		arr[i] = random(1, 100);
}

void printArray(short arr[], short arrLength)
{
	for (short i = 0; i < arrLength; i++)
		cout << " " << arr[i];
}

void copyArrInReverse(short arrSource[], short arrDestination[], short arrLength)
{
	for (short i = 0; i < arrLength; i++)
		arrDestination[i] = arrSource[arrLength - 1 - i];
}

int main()
{
	srand((unsigned)time(NULL));

	short arrLength = readNumInRange("\n\n\nEnter number of elements", 1, 100),
		arrSource[100] = { 0 },
		arrDestination[100] = { 0 };

	cout << "\n\n--------------------------\n";

	fullArray(arrSource, arrLength);

	cout << "Array 1 elements: ";
	printArray(arrSource, arrLength);

	cout << "\n--------------------------\n";

	copyArrInReverse(arrSource, arrDestination, arrLength);

	cout << "Array 2 elements after copy: ";
	printArray(arrDestination, arrLength);

	cout << "\n--------------------------\n";
}