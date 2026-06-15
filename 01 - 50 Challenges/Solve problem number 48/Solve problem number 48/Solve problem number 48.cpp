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

int floorNum(float num) 
{
	int intPart = static_cast<int>(num);

	if (num < 0 && num != intPart)
		return --intPart;

	else
		return static_cast<int>(num);
}

int main()
{
	float num = readNum("Please enter a number to floor : ");

	cout << "\nMy Floor Result                : " << floorNum(num);
	cout << "\n\nC++ Floor Result               : " << floor(num) << endl;


	return 0;
}