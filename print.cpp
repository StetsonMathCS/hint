#include <iostream>
#include <string>
#include "datastructures.h"
using namespace std;

// separate print functions to print out the data given
// I thought the data was supposed to be kept in a struct but I don't know if I'll have time tonight
// So I'll pull from the classes

/*
// Queue
void print(Queue<*void> q) { //take in the Queue that is given. *void since I'm pretty sure the data can be anything but subject to change
	cout << "====== Start Of Data ======" << endl; // Makes it more readable
	while(!q.empty()) {
		cout << q.front() << endl;
		q.pop();
	}
	cout << "====== End Of Data ======" << endl; // Makes it more readable
}

// Linked List
void print(LinkedList<*void> l) { // This has it's own print function...? Again, *void can be replaced
	cout << "====== Start Of Data ======" << endl; // Makes it more readable
	l.print(); // I don't know what this print looks like...
	 // This is here in case the print function stated above needs to be redone/reformatted
	for(int i = 0; i < l.length(); i++) {
		cout << l.nth(i); // I'm assuming nth function accesses a specific section of the linkedlist? 
	}
	/	
	cout << "====== End Of Data ======" << endl; // Makes it more readable
}

// Dynamic Array
// Wait a second this defines the functions in the class???
void print(DynamicArray<*void> d) { // same deal as above, *void can be replaced
	cout << "====== Start Of Data ======" << endl;
	for(int i = 0; i < d.size(); i++) {
		cout << d[i] << endl; // I'm actually not 100% on how to access the data for this class
	}
	cout << "====== End Of Data ======" << endl;
}
*/
// since the data structures changed, this isn't how it's being done now

void print(DataStructures d) {
	cout << "====== Start Of Data ======" << endl;
	d.display();
	cout << "====== End Of Data ======" << endl;

}
