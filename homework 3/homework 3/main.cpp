#include <iostream>	

using namespace std;
#define MAXSIZE 26


class CharVectArray {
public:
	CharVectArray(int vsize = MAXSIZE);	// default constructor
	CharVectArray(char vlist[], int arraysize); // constructor with init parameters
	CharVectArray(const CharVectArray& fva);  // copy constructor
	CharVectArray& operator = (const CharVectArray& fva); // assignment operator
	~CharVectArray();	  // destructor
	void printElements();  // prints all elements in the vector
private:
	char *vector;		// the vector
	int vectorsize;	// size of the vector
};

// default constructor
CharVectArray::CharVectArray(int vsize): vectorsize(vsize) {
	vector = new char[vsize];
}

// constructor with initialization parameters
CharVectArray::CharVectArray(char vlist[]=NULL, int arraysize=0):vectorsize(arraysize) {
	vector = new char[vectorsize];
	/*====================================NOTES================================================
		what brandon did was he then made a strcpy to copy all the elements in vist to vector
		however, wouldn't the copy constructor do the same?
	============================================================================================*/
	
}

// copy constructor
CharVectArray::CharVectArray(const CharVectArray& fva) {
	/*
	this allows us to make a copy of the object class CharVectArray and lets us assign
		whatever values we get from the original object, into the new copy of the object
		CharVectArray
	*/
	vectorsize = fva.vectorsize;
	vector = new char[vectorsize];
	char* ptr = vector + vectorsize;	
	char* copyptr = fva.vector + vectorsize;
	

}
// assignment operator
CharVectArray& CharVectArray::operator = (const CharVectArray &fva) {
	// to be completed
}

// destructor
CharVectArray::~CharVectArray() {
	// to be completed 
}

void CharVectArray::printElements() {
		// to be completed 
	}

		int main() {
			// testing the implementation of a char vector using array

			// declare & initialize an array of char and create a char vector aVect 
			char CharArray1[MAXSIZE];
			for (int i = 0; i<MAXSIZE; i++)
				CharArray1[i] = 'a' + i;
			CharVectArray aVect(CharArray1, MAXSIZE);
			cout << "Printing all elements in aVect:" << endl;
			aVect.printElements();

			// declare & initialize another array of char and create char vector bVect
			char CharArray2[MAXSIZE];
			for (int i = 0; i<MAXSIZE; i++)
				CharArray2[i] = 'z' - i;
			CharVectArray bVect(CharArray2, MAXSIZE);
			cout << "Printing all elements in bVect:" << endl;
			bVect.printElements();

			// try the assignment constructor
			bVect = aVect;
			cout << "Assigned bVect = aVect. Printing now all elements in bVect:" << endl;
			bVect.printElements();

			// try the copy constructor
			CharVectArray cVect = aVect;
			cout << "cVect is a copy of aVect. Printing all elements in cVect:" << endl;
			cVect.printElements();

			return 0;
		}
