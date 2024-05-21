/*
Christopher Baker
Homework 1 V2: Tanny Air 1 V2
Date Due: 2/21/2017
Compiler used: Visual Studio 2015
Description: Tanny's airline is a new kickstarter that only has 1 plane available to fit 10 passengers. Tanny has barked the orders to set up
			 a program to store and display that passenger information. This .h file accomplishes that using an array of structures as well as
			 class implementation.
*/

#pragma once // To avoid def
#include <string>  // include string

void menu(); // Prototype the menu function which will be the initial function in the program

/*
struct passenger will hold the data members first name, last name, flight number, and priority. 
They will later be accessed by class Data functions to retreive and mutate values. 
*/
struct passenger 
{
	std::string FName;
	std::string LName;
	int FltNum;
	std::string Prior;
};


/*
class Data will contain most of the functions such as enter, display, and quit. This will allow
the menu function to branch off to these seperate functions to carry out their purpose.
class Data  will iterate through the passenger array to retrieve and mutate the correct 
passenger index. A constant of 10 has been declared for the correct array of structures.
dataobj is the name of the class Data object to access the functions outside of the class.
*/
class Data
{
public:

	static int const MAXNUM = 10; // for struct array of 10
	int i; // indexer
	int x; // index limiter

	Data() 
	{
		passengerArray = new passenger[MAXNUM]; // passenger struct array of 10
	}
	
	void Data::enter();

	void Data::quit();

	void Data::display();

private:
	passenger *passengerArray; // pointer
};

Data dataobj; // Class Data object created







