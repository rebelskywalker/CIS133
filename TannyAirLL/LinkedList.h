*
Christopher Baker
Homework 2 V1: Tanny Air LinkedList A
Date Due: 3/16/2017
Compiler used: Visual Studio 2015
Description: Tanny's airline is a new kickstarter that only has 1 plane available to fit 10 passengers. Tanny has barked the orders to set up
a program to store and display that passenger information. This .h file accomplishes that using an array of structures as well as
class implementation.
*/

#pragma once // To avoid def
#include <string>  // include string
#include <iostream>
#include <memory>

using namespace std;


/*
class DataLinkedList will initialize startptr to nullpointer through constructor. 

struct passenger will hold the data members first name, last name, flight number, and priority.
This will provide the node structure to be accessed for storing data values.
*/
class DataLinkedList
{

	struct passenger
	{
		string FName;
		string LName;
		int FltNum;
		string Prior;
		passenger *next; // pointer to next passenger
	};
	passenger *listStartPtr; // the pointer to be set to null
	//unique_ptr<passenger> *listStartPtr;

public:

	static int const MAXNUM = 10; // New limit comparison; will create new nodes if Linked size() < MAXNUM, since we will not index to 10 elements via array

	DataLinkedList()
	{
		listStartPtr = nullptr; // set list head = to nullptr
	}
	

	int DataLinkedList::size(); // returns size

	void DataLinkedList::enter(); // allows data to be entered into node data members

	void DataLinkedList::quit(); // quits program

	void DataLinkedList::display(); // displays up to 10 passenger information via linked list
};
