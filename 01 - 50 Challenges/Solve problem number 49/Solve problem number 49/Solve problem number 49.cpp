#include <iostream>
#include <cmath>
using namespace std;

float readNum(string message)
{
	float num = 0;

	cout << message;
	cin >> num;

	return num;
}

int ceilNum(float num)
{
	int intPart = static_cast<int>(num);

	if (num > 0 && num != intPart)
		return ++intPart;

	else
		return intPart;
}

int main()
{
	float num = readNum("Please enter a number to ceil : ");

	cout << "\nMy Ceil Result                : " << ceilNum(num);
	cout << "\n\nC++ Ceil Result               : " << ceil(num) << endl;


	return 0;
}