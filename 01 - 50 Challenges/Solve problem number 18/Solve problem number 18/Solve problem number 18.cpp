#include <iostream>
#include <string>
using namespace std;

string readStrName(string message)
{
	string name = "";

	cout << message << " : ";
	getline(cin, name);

	return name;
}

string encryptionName(string name, short encryptionKey)
{
	for (int i = 0; i < name.length(); i++)
	{
		name[i] = static_cast<char>(static_cast<int>(name[i]) + encryptionKey);
	}

	return name;
}

string decryptionName(string name, short encryptionKey)
{
	for (int i = 0; i < name.length(); i++)
	{
		name[i] = static_cast<char>(static_cast<int>(name[i]) - encryptionKey);
	}

	return name;
}

void printEncryptAndDecryptName(string name, short encryptionKey)
{ 
	string encryptName = encryptionName(name, encryptionKey),
		decryptName = decryptionName(encryptName, encryptionKey);
		
	cout << "\n\n--------------------------------\n";
	cout << "Text Before Encryption : " << name << "\n";
	cout << "Text After Encryption  : " << encryptName << "\n";
	cout << "Text After Decryption  : " <<  decryptName << "\n";
}

int main()
{
	string name = readStrName("Enter Your Name");
	const short encryptionKey = 2;

	printEncryptAndDecryptName(name, encryptionKey);

	return 0;
}