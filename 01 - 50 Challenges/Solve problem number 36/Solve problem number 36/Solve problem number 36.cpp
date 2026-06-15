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

void fillArrAndCountArrLength(int arr[], unsigned short &arrLength)
{
	arr[arrLength] = readNum("Enter a number: ");
	arrLength++;
}

void shouldContinue(int arr[], unsigned short &arrLength)
{

	bool ifContinue = 1;

	while (ifContinue == 1)
	{
		fillArrAndCountArrLength(arr, arrLength);

		cout << "\nDo you want to add more numbers?\n";
		cout << "[1] Yes\n[0] No\n";
		cout << "-------------------\n";
		cin >> ifContinue;
	}
}

void printArray(int arr[], unsigned short arrLength)
{
	cout << "Array Elements :";

	for (int i = 0; i < arrLength; i++)
		cout << " " << arr[i];
}

int main()
{
	int arr[100] = { 0 };
	unsigned short arrLength = 0;

	shouldContinue(arr, arrLength);

	cout << "Array Length : " << arrLength << endl;
	printArray(arr, arrLength);

	return 0;
}