/*
Christopher Baker
Homework 2 V1: Tanny Air LinkedList A
Date Due: 3/16/2017
Compiler used: Visual Studio 2015
Description: Tanny's airline is a new kickstarter that only has 1 plane available to fit 10 passengers. Tanny has barked the orders to set up
a program to store and display that passenger information. This cpp file has is a linked list implementation utilizing the class of DataLinkedList 
to house passenger structure nodes. Each node holds the information of essence to Tanny's business operations. Tanny asks, we make it happen!
*/
#include "LinkedList.h" // Pull info and access .h class and structs 




void DataLinkedList::display() // iterates through the passenger index to display passenger info
{
	int i = 0;
	passenger *travel = listStartPtr;
	while (travel != nullptr)
	{
		cout << "Passenger " << i + 1 << endl;
		cout << "FName: " << travel->FName << endl;
		cout << "LName: " << travel->LName << endl;
		cout << "FltNum: " << travel->FltNum << endl;
		cout << "Priority: " << travel->Prior << endl;
		cout << endl;
		travel = travel->next;
		i++;
	}


	system("pause");

}


void DataLinkedList::quit()
{
	return; // as described in the cpp this function will return 0 to the main function which will proceed to return 0 to exit the program.
}


int DataLinkedList::size()
{
	passenger *travel = listStartPtr;
	int listSize = 0;
	while (travel != nullptr)
	{
		++listSize;
		travel = travel->next;
	}
	return listSize;
}


void DataLinkedList::enter() // allows the user to enter information and provides basic error checking
{
	
	passenger *nodeToAdd = new passenger(); // Create the added node that will hold a new passenger's information
	
	passenger *currentNode = listStartPtr; // The current node will point to the first node in the list

	passenger *travel = listStartPtr; // the travel pointer will point at the liststartptr also

	bool cont = true;
	char b = '0'; // character variable b will be used to check which priority status is selected
	int num = 0; // integer variable num is used to check if the user has input an integer for flight number

	if (size() < MAXNUM)
	{

		if (listStartPtr != nullptr)
		{
			while (currentNode->next != nullptr)
			{
				currentNode = currentNode->next;
			}

			currentNode->next = nodeToAdd;
		}

		else
		{
			listStartPtr = nodeToAdd;
		}


		cout << "Valid Entries: \nString for names, integer 0-2147483647 for flight number,\nand enclosed characters for priority status.\n" << endl;
		cout << "FName: ";
		cin >> nodeToAdd->FName; // user inputs a passenger first name

		cout << "LName: ";
		cin >> nodeToAdd->LName; // user inputs a passenger last name

		cout << "FltNum: "; // user inputs a passenger flight number


		cin >> num; // user inputs flight number

		while (cin.fail())
		{
			cout << "Input Error - Please enter an integer" << endl;
			cin.clear();
			cin.ignore(256, '\n');
			cin >> num;
		}
		
		nodeToAdd->FltNum = num;

		cout << "Priority: " << endl; // List the suboptions for priority
		cout << "\t(G)old" << endl;
		cout << "\t(P)latinum" << endl;
		cout << "\t(S)ilver" << endl;
		cout << "\t(L)ead" << endl;


		cin >> b; // user inputs character check
	
		while (cont)
		{
			if (b == 'g' || b == 'G' || b == '2') // This if else statement block will determine which status the passenger has based on letter and integer 1-4
			{
				nodeToAdd->Prior = "Gold";
				cont = false;
			}
			else if (b == 'p' || b == 'P' || b == '1')
			{
				nodeToAdd->Prior = "Platinum";
				cont = false;
			}
			else if (b == 's' || b == 'S' || b == '3')
			{
				nodeToAdd->Prior = "Silver";
				cont = false;
			}
			else if (b == 'l' || b == 'L' || b == '4')
			{
				nodeToAdd->Prior = "Lead";
				cont = false;
			}
			else
			{
				cout << "Input Error- You will be prompted to input this passenger's information again\n"; // give error if they do no follow directions
				cout << "Please enter a character P,G,S,L or number 1-4 to correspond with your choice\n\n";
				cin >> b;
			}
		}

		cout << endl;

		system("CLS");
	}
	else 
	{
		system("CLS");
		cout << "Tanny's airline is full, please see (d)isplayed passengers \nor (e)xit the program. No more entries allowed.\n\n";
		system("pause");
	}
}



int main() // Where it all begins
{
	DataLinkedList obj; // Class Data object created
	
	bool finished = false;
	while (!finished)
	{
		char answer = 0;

		cout << "(E)nter the passenger information" << endl;
		cout << "(D)isplay the passenger information" << endl;
		cout << "(Q)uit the program" << endl;


		cout << endl;
		cout << "Enter character: ";
		cin >> answer;
		cout << endl;

		while (cin.fail())
		{
			cout << "Input Error - Please input character e, d, or q" << endl;
			cin.clear();
			cin.ignore(256, 'n');
			cin >> answer;
		}
		if (answer == 'e' || answer == 'E')
		{
			obj.enter();
		}
		else if (answer == 'd' || answer == 'D')
		{
			obj.display();
		}
		else if (answer == 'q' || answer == 'Q')
		{
			finished = true;
		}
		else
		{
			system("CLS");
			cout << "Input Error- Please enter a character in any of the parenthesis \n" << endl;
			cin.ignore();

		}
		system("CLS");
	}

	return 0;
}
