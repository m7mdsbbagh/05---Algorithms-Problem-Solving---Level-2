#include <iostream>
#include <cstdlib>
using namespace std;

int randomNum(int from, int to)
{
	int randNum = rand() % (to - from + 1) + from;

	return randNum;
}

int main()
{
	srand((unsigned)time(NULL));


	cout << randomNum(80, 100) << endl;
	cout << randomNum(80, 100) << endl;
	cout << randomNum(80, 100) << endl;

	return 0;
}