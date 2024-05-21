/*
Christopher Baker
Homework 1: Tanny Air 1
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

	void Data::display() // iterates through the passenger index to display passenger info
	{
		for (i = 0; i < x; i++) 
		{
			std::cout << "Passenger " << i+1 << std::endl;
			std::cout << "FName: " <<  passengerArray[i].FName << std::endl;
			std::cout << "LName: " << passengerArray[i].LName << std::endl;
			std::cout << "FltNum: " << passengerArray[i].FltNum << std::endl;
			std::cout << "Priority: " << passengerArray[i].Prior << std::endl;
			std::cout << std::endl;
		}


		system("pause");
		menu();
	}
	
	void Data::enter() // allows the user to enter information and provides basic error checking
	{
		if (i == 10)
		{
			system("CLS");
			std::cout << "Tanny's airline is full, please see (d)isplayed passengers \nor (e)xit the program. No more entries allowed.\n";
			menu();
		}

		char b = '0'; // character variable b will be used to check which priority status is selected
		int num = 0; // integer variable num is used to check if the user has input an integer for flight number

		std::cout << "Valid Entries: \nString for names, integer 0-2147483647 for flight number,\nand encloed characters for priority status.\n" << std::endl;
		std::cout << "FName: ";
		std::cin >> passengerArray[i].FName; // user inputs a passenger first name
		
		std::cout << "LName: "; 
		std::cin >> passengerArray[i].LName; // user inputs a passenger last name
		
		std::cout << "FltNum: "; // user inputs a passenger flight number
		
		
		std::cin >> num; // user inputs flight number

		while (std::cin.fail())
		{
			std::cout << "Input Error - Please enter an integer" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cin >> num;
		}
		passengerArray[i].FltNum = num;


		std::cout << "Priority: " << std::endl; // List the suboptions for priority
		std::cout << "\t(G)old" << std::endl;
		std::cout << "\t(P)latinum" << std::endl;
		std::cout << "\t(S)ilver" << std::endl;
		std::cout << "\t(L)ead" << std::endl;

		
		std::cin >> b; // user inputs character check

		
			if (b == 'g' || b == 'G' || b == '2') // This if else statement block will determine which status the passenger has based on letter and integer 1-4
			{
				passengerArray[i].Prior = "Gold";
			}
			else if (b == 'p' || b == 'P' || b == '1')
			{
				passengerArray[i].Prior = "Platinum";
			}
			else if (b == 's' || b == 'S' || b == '3')
			{
				passengerArray[i].Prior = "Silver";
			}
			else if (b == 'l' || b == 'L' || b == '4')
			{
				passengerArray[i].Prior = "Lead";
			}
			else
			{
				std::cout << "Input Error- You will be prompted to input this passenger's information again\n"; // give error if they do no follow directions
				std::cout << "Please enter a character P,G,S,L or number 1-4 to correspond with your choice\n\n";
				enter(); // back to enter function
			}
		
		


		std::cout << std::endl;

		i++; // If entered info correctly, level up index
		x++; // Index limiter Levels Up as well
		system("CLS");
		menu(); // head back to the menu to give more options
	}

	int Data::quit()
	{
		return 0; // as described in the cpp this function will return 0 to the main function which will proceed to return 0 to exit the program.
	}

	Data() 
	{
		passengerArray = new passenger[MAXNUM]; // passenger struct array of 10
	}

private:
	passenger *passengerArray; // pointer
};

Data dataobj; // Class Data object created


void menu() // Simple menu to test entered characters to call the functions to enter info, display info, or quit the program
{
	char answer = 0;

	std::cout << "(E)nter the passenger information" << std::endl;
	std::cout << "(D)isplay the passenger information" << std::endl;
	std::cout << "(Q)uit the program" << std::endl;

	
	std::cout << std::endl;
	std::cout << "Enter character: ";
	std::cin >> answer;
	std::cout << std::endl;

	while (std::cin.fail())
	{
		std::cout << "Input Error - Please input character e, d, or q" << std::endl;
		std::cin.clear();
		std::cin.ignore(256, 'n');
		std::cin >> answer;
	}
		if (answer == 'e' || answer == 'E')
		{
			dataobj.enter();
		}
		else if (answer == 'd' || answer == 'D')
		{
			dataobj.display();
		}
		else if (answer == 'q' || answer == 'Q')
		{
			dataobj.quit();
		}
		else
		{
			system("CLS");
			std::cout << "Input Error- Please enter a character in any of the parenthesis \n" << std::endl;
			std::cin.ignore();
			menu();
		

	}
}
