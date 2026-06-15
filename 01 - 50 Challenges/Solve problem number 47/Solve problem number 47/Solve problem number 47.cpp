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

float calcDecimalPart(float num)
{
	return num - static_cast<int>(num);
}

int roundNum(float num)
{
	float decimalPart = calcDecimalPart(num);

	if (decimalPart >= 0.5)
		return static_cast<int>(num) + 1;

	else if (decimalPart <= -0.5)
		return static_cast<int>(num) - 1;

	else
		return static_cast<int>(num);
}

int main()
{
	float num = readNum("Please enter a number to round : ");

	cout << "\nMy Round Result                : " << roundNum(num);
	cout << "\n\nC++ Round Result               : " << round(num) << endl;


	return 0;
}