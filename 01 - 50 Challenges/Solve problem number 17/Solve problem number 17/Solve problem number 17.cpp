#include <iostream>
#include <string>
using namespace std;

string readPassword()
{
	string passord = "";

	cout << "Enter Your Password : ";
	cin >> passord;

	return passord;
}

bool guessPassword(string password)
{
	string word = "";
	int counter = 0;

	for (int i = 65; i <= 90; i++)
	{
		for (int j = 65; j <= 90; j++)
		{
			for (int k = 65; k <= 90; k++)
			{
				word.append(1, static_cast<char>(i));
				word.append(1, static_cast<char>(j));
				word.append(1, static_cast<char>(k));

				cout << "Trail [" << ++counter << "] : " << word << "\n";

				if (word == password)
				{ 
					cout << "\n\n------------------------\n";
					cout << "Your Password Is " << password << endl;
					cout << "Found After " << counter << " Trial";
					if (counter < 3)
						cout << 's';
					cout << ".\n";

					return true;
				}

				word.clear();
			}
		}
	}
	return 0;
}

int main()
{
	guessPassword(readPassword());

	return 0;
}