#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int readPositiveNum(string message)
{
	int num = 0;

	do {

		cout << message;
		cin >> num;

	} while (num <= 0);

	return num;
}

bool isPerfectNumber(int j)
{
	int sum = 0;
	for (int i = 1; i <= j / 2; i++)
	{
		if (j % i == 0)
			sum += i;
	}
	return sum == j;
}

void printResult(int num)
{
	cout << "\n\n-----------------------\n";
	cout << "All Perfect Numbera Form 1 To " << num << " Is : (";

	for (int j = 1; j <= num; j++)
	{
		if (isPerfectNumber(j))
			cout << j << " ,";

		if (j == num)
			cout << "\b\b).\n\n";
	}
}

int main()
{
	int num = readPositiveNum("Please Enter a Positive Number : ");

	printResult(num);


	return 0;
}