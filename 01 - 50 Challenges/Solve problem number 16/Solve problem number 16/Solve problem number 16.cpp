#include <iostream>
using namespace std;

void printAllFromAAAtoZZZ()
{
	string word = "";

	for (int i = 65; i <= 90; i++)
	{
		for (int j = 65; j <= 90; j++)
		{
			for (int k = 65; k <= 90; k++)
			{
				word.append(1, static_cast<char>(i));
				word.append(1, static_cast<char>(j));
				word.append(1, static_cast<char>(k));

				cout << word << "\n";

				word = "";
			}
		}
	}
}

int main()
{
	printAllFromAAAtoZZZ();

	return 0;
}