#include <fstream>
#include <string>
#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

void rotation_method(int val)
{
	int value = val;
	if (value < 0) {
		value = -value;
		int lastNumber = value % 10;
		value /= 10;
		while (lastNumber < value)
			lastNumber *= 10;
		value += lastNumber;
		value = -value;

	}
	else {
		int lastNumber = value % 10;
		value /= 10;
		while (lastNumber < value)
			lastNumber *= 10;
		value += lastNumber;

	}

}


void division_method(int val, int *M)
{
	int value = val;
	int position = abs((value % 1009));

	if (M[position] == 0)
	{
		M[position] = value;
		cout << value << " added to position " << position << endl;
	}

	else {
		cout << "You tried to add value: " << value << endl;
		cout << "Value " << M[position] << " already exists in position " << position << ", a collision has occurred." << endl;
		system("PAUSE");
	}

}




int main() {
	ifstream fin;
	fin.open("integers.txt");
	int val;
	char choice;
	int N = 1000;
	int * M = new int[N]();

	cout << "'a' for Division method, 'b' for division method." << endl;
	cin >> choice;
	if (choice == 'a') {
		while (fin.peek() != EOF)
		{
			fin.get();
			fin >> val;
			division_method(val, M);
		}
	}
	else if (choice == 'b') {
		while (fin.peek() != EOF)
		{


		}

	}
	delete M;
	fin.clear();
	fin.close();


	return 0;
}
