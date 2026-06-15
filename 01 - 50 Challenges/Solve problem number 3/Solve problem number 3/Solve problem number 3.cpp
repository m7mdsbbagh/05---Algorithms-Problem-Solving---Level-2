#include <iostream>
#include <string>
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

bool isPerfectNumber(int positiveNum)
{
	int sum = 0;
	for (int i = 1; i <= positiveNum / 2; i++)
	{
		if (positiveNum % i == 0)
			sum += i;
	}
	return positiveNum == sum;
}

string printResult(int num)
{
	if (isPerfectNumber(num))
		return " is Perfect Num!";

	return " isn't Perfect Num!";
}

int main()
{
	int num = readPositiveNum("Please Enter a Positive Number : ");

	cout << "\n\n---------------\n";
	cout << num << printResult(num);

	return 0;
}