#include <iostream>
using namespace std;

int readPosNum(string message)
{
	int num = 0;

	do {

		cout << message << " : ";
		cin >> num;

	} while (num <= 0);

	return num;
}

int reverseNum(int num_)
{
	int remainder = 0,
		num = 0;

	while (num_ > 0)
	{
		remainder = num_ % 10;
		num_ /= 10;

		num = num * 10 + remainder;
	}

	return num;
}

bool isPalindrome(int num_)
{
	return num_ == reverseNum(num_);
}

int main()
{
	int num_ = readPosNum("Enter a positive num");

	cout << "\n\n-------------------------------\n";

	if (isPalindrome(num_))
		cout << "Yes, it is  a Palindrome number!\n";

	else
		cout << "No, it is NOT a Palindrome number!\n";

	return 0;
}