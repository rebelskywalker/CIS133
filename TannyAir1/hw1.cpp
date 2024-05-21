/*
Christopher Baker
Homework 1: Tanney Airline
Date Due: 02/21/2017
visual stidio 2015
This program will handle passenger reservation on Tanney Airlines.
*/

#include "Header.h"
int answerinput;
int max;


int main() {
	char A;
	
	std::cout << "Your top level menu is to read as " << std::endl;
	std::cout << "(E)nter the passenger information" << std::endl;
	std::cout << "(D)isplay the passenger information" << std::endl;
	std::cout << "(Q)uit the program" << std::endl;
	std::cin >> A;
	A = toupper(A);
	switch (A)
	{
	case 'E':
		interedInformation();
		break;

	case 'D':
		display();
		break;
	case 'Q':
		exit(0);
		break;
	default:
		std::cout << "invalid input" << std::endl;
		system("CLS");
		main();
		break;
	}
	
}




void interedInformation()

{
	

		char answer ;
		std::cout << "FName: ";
		std::cin >> obj.information[answerinput].FName;
		std::cout << "LName: ";
		std::cin >> obj.information[answerinput].LName;
		std::cout << "FltNum: ";
		std::cin >> obj.information[answerinput].FltNum;


		std::cout << "Priority: " << std::endl;
		std::cout << std::endl;
		std::cout<< "(P)latinium " << std::endl;
		std::cout << "(G)old" << std::endl;
		std::cout << "(S)ilver" << std::endl;
		std::cout << "(L)ead" << std::endl;
		std::cin >> answer;
		answer = toupper(answer);

		switch (answer)
		{
		case 'P':
		obj.information[answerinput].Priority = "Platinium";
		std::cout << std::endl;
		break;
		case 'G':
		obj.information[answerinput].Priority = "Gold";
		std::cout << std::endl;
		break;
		case 'S':
		obj.information[answerinput].Priority = "Silver";
		std::cout << std::endl;
		break;
		case 'L':
		obj.information[answerinput].Priority = "Lead";
		std::cout << std::endl;
		break;
		default:
		std::cout << "invalid input" << std::endl;
		interedInformation();
		break;
		}
		
	
		answerinput++;
		max++;
		
		if (max < 10) {
			system("pause");
			system("CLS");
			main();
		}
		else {
			maxReached();
		}
}
void maxReached()
{
	char answer2;
	std::cout << " Sorry you have reached your limit please choose from the following " << std::endl;
	std::cout << "(D)isplay the passenger information" << std::endl;
	std::cout << "(Q)uit the program" << std::endl;
	std::cin >> answer2;
	answer2 = toupper(answer2);

	switch (answer2)
	{
	case 'D':
		display();
		break;
	case 'Q':
		exit(0);
		break;
	default:
		std::cout << "invalid input" << std::endl;
		system("CLS");
		maxReached();
		break;
	}

}

void display()
{

	for (answerinput = 0; answerinput < max; answerinput++)
	{
		
		std::cout << "First Name: " << obj.information[answerinput].FName << std::endl;
		std::cout << "Last Name: " << obj.information[answerinput].LName << std::endl;
		std::cout << "Flight Number: " << obj.information[answerinput].FltNum << std::endl;
		std::cout << "Boarding Priority: " << obj.information[answerinput].Priority << std::endl << std::endl;
	}
	if (max < 10) {
		system("pause");
		system("CLS");
		main();
	}
	else {
		maxReached();
	}
	system("pause");
	

}
