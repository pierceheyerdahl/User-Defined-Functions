/*CS 161 Assignment 6: User Defined Functions
Filename: a06.cpp
Author:   Pierce Heyerdahl
Date:     5/29/2017
Summary:  A menu based program that contains two functions, one to calculate the smallest value from a list of inputs, and another that counts the even and odd digits in a number.

Functions:
int smallest() = takes user inputs until a negative number is inputted and returns the smallest value
void numberCount(int &oddCount, int &evenCount) = calculates the number of even and odd digits in a user inputted number

Input variables:
string userInput = records user's menu choice
char menuInput = user's menu choice after input validation
int userNum = used in both functions to store the user inputted number

Output variables:
bool i = keeps the program looping until the user inputs the exit command
int odd = number of odd digits in the user inputted number
int even = number of even digits in the user inputted number

Equations:
while i != 1, the menu keeps looping until the user enters 'c'
if userInput length != 1 then the switch defaults and program loops
if user enters 'a' the function smallest() is executed
if user enters 'b' the function numberCount(int &oddCount, int &evenCount) is executed
if user enters 'c' i is changed to 1 and the program exits
*/

#include <iostream>
#include <string>
using namespace std;

int smallest();
void numberCount(int &oddCount, int &evenCount);

int main()
{
	string userInput;
	char menuInput;
	bool i = 0;
	int odd = 0;
	int even = 0;

	while (i != 1)
	{
		cout << "Welcome to my program! Please enter a-c to choose one of the following:" << endl;
		cout << "( a ) find the smallest of a list of positive numbers (-1 to quit)." << endl;
		cout << "( b ) Count the odd and even digits in a number." << endl;
		cout << "( c ) Quit this program." << endl;
		cout << "Enter Command: ";
		cin >> userInput;

		if (userInput.length() == 1) // validates user input
		{
			menuInput = userInput[0];

			switch (menuInput)
			{
			case 'a': // runs the function smallest and outputs the returned value
				cout << "Smallest Number = " << smallest() << endl << endl;
				break;
			case 'b': // runs the function numberCount and outputs the even and odd digits of a number
				numberCount(odd, even);
				cout << "Odd Count = " << odd << endl << "Even Count = " << even << endl << endl;
				break;
			case 'c': // exits program
				cout << "Exiting...";
				i = 1;
				break;
			default: 
				cout << "Input command invalid" << endl << endl;
				break;
			}
		}
		else
		{
			cout << "Input command invalid" << endl << endl;
		}
	}
	return 0;
}

int smallest() // takes user inputs until a negative is entered and returns the smallest value
{
	int userNum = 0;
	int smallest = 0;
	cout << "Enter a number: ";
	cin >> userNum;
	smallest = userNum;
	while (userNum > 0)
	{
		if (userNum < smallest)
		{
			smallest = userNum;
		}
		cout << "Enter a number: ";
		cin >> userNum;
	}
	return smallest;
}

void numberCount(int &oddCount, int &evenCount) // takes user input and returns number of even and odd digits
{
	int userNum = 0;
	int lastDigit = 0;
	oddCount = 0;
	evenCount = 0;

	cout << "Enter a number: ";
	cin >> userNum;

	do
	{
		lastDigit = userNum % 10;
		if (lastDigit % 2 == 0)
		{
			evenCount += 1;
		}
		else
		{
			oddCount += 1;
		}
		userNum /= 10;
	} 
	while (userNum != 0);
}


