
/*
Christopher Baker
Homework 3 : Hash Problem
Date Due: 4/17/2017
Compiler used: Visual Studio 2015
Description: This cpp file contains the function definitions that will run the dictionary program to display the 
dictionary list, index of each item, and number of collisions at each position. Further, these functions allow for searching
and displaying more detailed information about the contents of the dictionary.txt file. 
*/



#include "hash.h"



/*
The main function will load the dictionary and print an error if the dictionary file was unable to be opened. 
Then main will call the PrintTable and Enter function before closing the file and exiting the program after a keypress. 
*/
int main()
{
	hashClass hashy;
	string line_;
	ifstream file_("dictionary.txt");
	if (file_.is_open())
	{
		while (getline(file_, line_)) { 
			// read through the file

			hashy.AddItem(line_);
		}

		cout << "\nFor extra credit consideration: " << endl;
		cout << "I have attained a max collsion value of 3 for any bucket list" << endl;
		cout << "I used advanced concepts like a simple linear probing and my" << endl;
		cout << "own variation of Donald Knuth letter-integer theory for this scenario \n\n";

		system("pause");

		hashy.PrintTable();
		
		hashy.Search();
		
		system("pause");

		file_.close();

	}
	else {
		cerr << "file is not open" << endl;
		cin.get();
	}
	return 0;
}




hashClass::hashClass()
{
	for (int i = 0; i < tableSize; i++)
	{
		HashTable[i] = new item;
		HashTable[i]->name = "empty";

		HashTable[i]->next = NULL;

	}
}
/*
The AddItem function will store entries into the buckets and create a linked list if a collsion occurs at a 
HashTable index. The col thing about this function is the simple linear probe that checks for empty buckets
one to two elements away to ensure that all buckets are utilized with this particular function, while not 
exhausting the program memory or efficiency as much as a full probe. 
*/
void hashClass::AddItem(string name)
{
	int index = HashFunc(name);
	// index = the integer returned by HashFunc(name)

	if (HashTable[index]->name == "empty")
		// if the HashTable index is empty then we will create the information at that bucket
	{
		HashTable[index]->name = name;
	}

	else
	{


		if (HashTable[index] != HashTable[tableSize - 1] && HashTable[index + 1]->name == "empty")
		{

			HashTable[index + 1]->name = name;
		}


		else if (HashTable[index] != HashTable[tableSize - 1] && HashTable[index] != HashTable[tableSize - 2] && HashTable[index + 2]->name == "empty")
		{

			HashTable[index + 2]->name = name;
		}

		else
			//if not empty we will create a linked list out of that bucket index
		{
			item *Ptr = HashTable[index];
			item *n = new item;
			n->name = name;
			n->next = NULL;

			while (Ptr->next != NULL)
			{
				Ptr = Ptr->next;
			}
			Ptr->next = n;
		}
	}
}

/*
This function is its namesake, it shall iterate through a hashtable linked list to gather 
the amount of items stored at that array location. 
*/
int hashClass::NumberOfItemsInIndex(int index)
{
	int count = 0;

	if (HashTable[index]->name == "empty")
	{
		return count;
	}
	else
	{
		count++;
		item *Ptr = HashTable[index];
		while (Ptr->next != NULL)
		{
			count++;
			Ptr = Ptr->next;
		}
	}
	return count;
}

/*
This function prints the whole table of the words stored in the main bucket of each hash index
and then calls the number of items function to display the items in held at that index. 
*/
void hashClass::PrintTable()
{
	int number;
	for (int i = 0; i < tableSize; i++)
	{
		number = NumberOfItemsInIndex(i);
		cout << "~~~~~~~~~~~~~~~~~~~~~~\n";
		cout << "Index: " << i << endl;
		cout << HashTable[i]->name << endl;

		cout << "Number of Items: " << number << endl;
		cout << "Number of Collsions: " << (number - 1) << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~\n";
	}
}
/*
max collision 3 with 13 tablesize - Which is a near perfect hash function for this set!
odds of finding a hash function with 2 collisions for tablesize 13 and dictionary size 39, would be less then winning the lottery. 

I studied concepts of Donald Knuth letter-number theory and phonex code theory
to implement my own hashfunction based on the frequency of letters stored in this
dictionary.
*/
int hashClass::HashFunc(string key)
{
	int hash = 0;
	int index;


	for (int i = 0; i < key.length(); i++)
	{ 
		key[i] = tolower(key[i]);
		if (key[i] == 'e' || key[i] == 'r' || key[i] == 'a' || key[i] == 'i' || key[i] == 'n' || key[i] == 'o' || key[i] == 't')
		{
			hash = hash + 1;
		}
		else if (key[i] == 's' || key[i] == 'l' || key[i] == 'c')
		{
			hash = hash + 3;
		}
		else if ( key[i] == 'u' || key[i] == 'h' || key[i] == 'p')
		{
			hash = hash + 11;
		}

		else if (key[i] == 'd' || key[i] == 'm')
		{
			hash = hash + 17;
		}
		else if (key[i] == 'b' || key[i] == 'g')
		{
			hash = hash + 23;
		}

		else if (key[i] == 'f' || key[i] == 'k' || key[i] == 'v' || key[i] == 'w')
		{
			hash = hash + 31;
		}
		else if (key[i] == 'y' || key[i] == 'j' || key[i] == 'x')
		{
			hash = hash + 43;
		}
		else
		{
			hash = hash + (int)key[i];
		}

	}

	index = (hash * 7) % tableSize;

	return index;
}

/*
The enter function prompts the user to enter a string to compare to each element in the hashtable. It will also search through
the table the same order and implementation as it stored information in the AddItem function. 
*/
void hashClass::Search()
{
	
	string entry = "";

	cout << "Welcome to the Bonus Round. \nEnter a word to search: \n" << endl;
	 
	getline(cin, entry);

	

	int index = HashFunc(entry);
	// index = the integer returned by HashFunc(name)

	item* Ptr = HashTable[index];


	if (HashTable[index]->name == entry)
		// if the HashTable index is empty then we will create the information at that bucket
	{
		cout << "Match found: " << HashTable[index]->name << " at index: " << index << endl;
	}

	else
	{


		if (HashTable[index] != HashTable[tableSize - 1] && HashTable[index + 1]->name == entry)
		{

			cout << "Match found: " << HashTable[index]->name << "at index: " << index + 1 << endl;
		}


		else if (HashTable[index] != HashTable[tableSize - 1] && HashTable[index] != HashTable[tableSize - 2] && HashTable[index + 2]->name == entry)
		{

			cout << "Match found: " << HashTable[index]->name << "at index: " << index + 2 << endl;
		}
		else
		{
			bool foundIt = false;
			while (Ptr != NULL)
			{
				if (Ptr->name == entry)
				{
					foundIt = true;
				}
				Ptr = Ptr->next;
			}
			if (foundIt == true)
			{
				cout << "Match found: " << Ptr->name << "at index: " << index << endl;
			}
			else
			{
				cout << "The word you are looking for is not apart of this dictionary, and perhaps any, good luck searching!" << endl;
			}
		}
	}

	system("CLS");
	cout << entry << ":";
	PrintItemsInIndex(index);

}

/*
This function provides the user with the information of items in the hashtable as well as
the number of collisions that occurred there. Further, as a little extra treat 
the user will see a visual of the individual bucket linked list at that location. 
*/
void hashClass::PrintItemsInIndex(int index)
{
	int numberOfItems = 0;
	int numberOfCollisions = 0;
	item* Ptr = HashTable[index];

	if (Ptr->name == "empty")
	{

		// Create an item Ptr to point to first item in Hash Table bucket
		cout << "index = " << index << " is empty";
	}
	else
	{
		cout << "index " << index << " contents:  \n \n";

		while (Ptr != NULL)
		{
			cout << "---------------|\n";
			cout << Ptr->name << endl;
			cout << "---------------|\n";
			cout << "     \\  /       \n";
			cout << "      \\/        \n";
			Ptr = Ptr->next;

			numberOfItems++;
		}
		numberOfCollisions = (numberOfItems - 1);
		cout << "     Null        \n";
		cout << "\nThis index contains " << numberOfItems << " items." << endl;
		cout << "Thus, " << numberOfCollisions << " collsion(s) occurred." << endl;


	}
}