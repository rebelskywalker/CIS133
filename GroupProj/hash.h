
/*
Christopher Baker
Homework 3 : Hash Problem
Date Due: 4/17/2017
Compiler used: Visual Studio 2015
Description: This header file sets up the framework for the buckets contents and the size 
of the HashTable to be made to contain words from a dictionary.txt file. Also the functions
that will be utilized to display and search values. 
*/

#pragma once
#include <iostream>
#include <string>
#include <fstream>


using namespace std;

class hashClass
{
private:
	static const int tableSize = 13;

	struct item
	{
		string name;

		item *next;
	};
	item *HashTable[tableSize];

public:
	hashClass();
	int HashFunc(string key);
	void AddItem(string name);
	int NumberOfItemsInIndex(int index);
	void PrintTable();
	void PrintItemsInIndex(int index);
	void Search();
};
