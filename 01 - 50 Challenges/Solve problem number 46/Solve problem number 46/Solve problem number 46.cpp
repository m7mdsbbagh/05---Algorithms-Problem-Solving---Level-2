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

float absNum(float num)
{
	if (num >= 0)
		return num;
	else
		return -num;
}

int main()
{
	float num = readNum("Enter a number : ");

	cout << "\nMy abs result  : " << absNum(num) << endl;
	cout << "\nC++ abs result : " << abs(num) << endl;

	return 0;
}