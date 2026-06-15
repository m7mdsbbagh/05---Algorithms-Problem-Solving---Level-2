#include <iostream>
#include <string>
#include <cmath>
using namespace std;

enum enPrimeOrNot {prime = 1, notPrime};

int readNumber()
{
	int num = 0;

	cout << "Please Enter a Number : ";
	cin >> num;

	while (num <= 0)
	{
		cout << "The Number Must Be Positive! Try Again : ";
		cin >> num;
	}

	return num;
}

enPrimeOrNot connectBetweenNumAndEnPrimeOrNot(int nOfNum)
{
	if (nOfNum == 1)
		return enPrimeOrNot::notPrime;

	for (int i = 2; i <= sqrt(nOfNum); i++)
	{
		if (nOfNum % i == 0)
			return enPrimeOrNot::notPrime;
	}
	return enPrimeOrNot::prime;
}

void printAllPrimeNumber1ToNum(int Num)
{
	cout << "\n\n----------------\n";
	cout << "All Prime Number : ";

	for (int i = 2; i <= Num; i++)
	{
		if (connectBetweenNumAndEnPrimeOrNot(i) == enPrimeOrNot::prime)
			cout << i << " ";
	}

	cout << endl;
}

int main()
{
	printAllPrimeNumber1ToNum(readNumber());

	return 0;
}