#include <iostream>
using namespace	std;

int readPosNum(string message)
{
	int num = 0;

	do {

		cout << message << " : ";
		cin >> num;

	} while (num <= 0);

	return num;
}

int reverseNumber(int num)
{
	int re = 0, temp = 0;

	while (num > 0)
	{
		re = num % 10;
		num /= 10;

		temp = temp * 10 + re;
	}
	
	return temp;
}

int main()
{
	int posNum = readPosNum("Enter a Positive Number");

	cout << "\n\n------------\n";
	cout << "Revers Number Is : " << reverseNumber(posNum) << endl;


	return 0;
}