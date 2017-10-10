#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

int position_maker(int val) //created this method seperate from division method function for better structure and so that I can build a collision handling aspect to the method
{
	int value = val; 
	int position = abs((value % 997)); //large enough prime number 997 so that the number of buckets is unlikely to be divisible by it	
	return position;
}

int absolute_value(int val) //method that creates the position in index by extracting three middle values out of the value to be hashed
{
	int value = val;
	value = abs(value); //takes absolute value to get rid of negative signs
	string middle = to_string(value); //converts the int to a string for char manipulation
	middle = middle.substr(2,3); //extraction of 3 chars out of string starting at index 2 of string
	value = stoi(middle); //conversion of string back to integer
	return value;
}

/*void rotation_method(int val)
{
	int value = val;
	if (value < 0) 
	{
		value = -value;
		int lastNumber = value % 10;
		value /= 10;
		while (lastNumber < value)
			lastNumber *= 10;
		value += lastNumber;
		value = -value;
	}
	else 
	{
		int lastNumber = value % 10;
		value /= 10;
		while (lastNumber < value)
			lastNumber *= 10;
		value += lastNumber;
	}
*/
void middle_method(int mid, int val, int * M)
{
	int position = mid;
	if(M[position]==0) //if empty position in array, hash the value in
	{
		M[position]=val; 
		cout << val << " added to position " << position<<endl;
	}
	else //otherwise display where colision occured and collision handling  
	{
		cout << "You tried to add value: " << val << endl;
		cout << "Value " << M[position] << " already exists in position " << position << ", a collision has occurred." << endl;
		cin.get(); //pause
		
		position+=1; //we're going to try the position one higher than the one already attempted and see if its empty 
		if (position==1000) //necessary condition because we do not want to try access a position in the array that doesn't exist 
		{
			position = 0; //resets position counter to zero 
		}
		cout << "Trying one position up at index " << position <<endl;
		middle_method(position,val,M);
	}
	
}

void division_method(int pos, int val, int* M) //function that hashes in a division manner
{
	int value = val; 
	int position = pos;
	if (M[position] == 0) //If the index in the array is empty then place the value into the array
	{
		M[position] = value;
		cout << value << " added to position " << position << endl;
	}

	else //otherwise display the value you wanted to add, the index you wanted to insert it into, and what value already exists in that index
	{
		cout << "You tried to add value: " << value << endl;
		cout << "Value " << M[position] << " already exists in position " << position << ", a collision has occurred." << endl;
		cin.get(); //pause
		
		position+=1; //we're going to try the position one higher than the one already attempted and see if its empty 
		if (position==1000) //necessary condition because we do not want to try access a position in the array that doesn't exist 
		{
			position = 0; //resets position counter to zero 
		}
		cout << "Trying one position up at index " << position <<endl;
		//cin.get();
		division_method(position, value, M); //recursive function that retries finding an empty index for the value now using a new position thanks to the +=1 counter or resetting the position to zero if position is at index 999 
	
	}

}

int main() {
	ifstream fin; //open an input file stream
	fin.open("integers.txt"); //text file containing the integeres 
	int val;
	char choice;
	int * M = new int[1000](); //dynamically created array of size 1000

	cout << "'a' for division method, 'b' for rotation method." << endl;
	cin >> choice;
	if (choice == 'a') {
		while (fin.peek() != EOF)
		{
			fin.get();
			fin >> val;
			int pos = position_maker(val); //creates the position
			division_method(pos,val, M); //method call for division method using the position makers value
		}
	}
	else if (choice == 'b') {
		while (fin.peek() != EOF)
		{
			fin.get();
			fin >> val;
			int mid_value = absolute_value(val); //method for extracting the middle values from the integer 
			middle_method(mid_value, val, M); //method for hashing using middle method

		}

	}
	delete M; //free up memory to avoid memory leak
	fin.clear(); //clear and close filestream 
	fin.close();


	return 0;
}
