#include <iostream>
#include <string>
using namespace std;
class Node {
public:
	int rollNumber;
	string name;
	Node* next;
};
class CircularLinkedList {
private:
	Node* LAST;
public:
	CircularLinkedList() {
		LAST = NULL;
	}
	void addNode();
	bool search(int rollno, Node** amalia, Node** dina);
	bool listEmpty();
	bool delNode();
	void traverse();
};
void CircularLinkedList::addNode() {
	int angka;
	string nm;
	cout << "\nEnter the roll number: ";
	cin >> angka;
	cout << "\nEnter the name: ";
	cin >> nm;
	Node* newNode = new Node();			// step 1	
	newNode->rollNumber = angka;		// step 2
	newNode->name = nm;					// step 2

	/*insert a node in the beginning of a double - linked list*/
	newNode->next = LAST;	//step 3
	if (LAST != NULL)
		LAST = newNode;		//step 4
	Node* dina = LAST;	// step 1b
	Node* amalia = NULL;	// step 2b

	while (dina != LAST && amalia->rollNumber < newNode->rollNumber) { //3b
		amalia = dina;	// 4a
		dina = amalia;  // 5b
	}

	bool CircularLinkedList::search(int rollNo, Node * *previous, Node * *current) {
		*previous = LAST->next;
		*current = LAST->next;
		while (*current != LAST) {
			if (rollno == (*current)->rollNumber) {
				return true;
			}
			*previous = *current;
			*current = (*current)->next;
		}
		if (rollno == LAST->rollNumber) {
			return true;
		}
		else {
			return false;
		}
	}
	bool CircularLinkedList::listEmpty() {
		return LAST == NULL;
	}

	bool CircularLinkedList::delNode() {
		Node* amalia, * dina;
		amalia = dina = NULL;
		if (search(rollNo, &dina, &amalia) == false)
			return false;
		if (dina-> LAST != NULL)
		dina = LAST;	//2a
		LAST = dina;	//3a
		
}


void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "\nList is empty\n";
	}
	else {
		cout << "\nRecords in the list are:\n";
		Node* currentNode = LAST->next;
		while (currentNode != LAST) {
			cout << currentNode->rollNumber << " " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
		cout << LAST->rollNumber << " " << LAST->name << endl;
	}
}
int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-5): ";
			char ch;
			cin >> ch;
			switch (ch) {
			case '1': {
			}
			case '2': {
			}
			case '3': {
				obj.traverse();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "Invalid option" << endl;
				break;
			}
			}

			catch (exception& e) {
				cout << e.what() << endl;
			}
		}
		return 0;
	}
