// DarinPalermo_SortingAlogorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <ctime>

class Node
{
	// Public Variables
public:
	int data;				// The data stored in the node
	Node* nextNode;			// The next node in the list
	Node* previousNode;		// The previous node in the list
};


class LinkedList
{
	// Public Variables
public:
	int length;		// The current length of the linked list
	Node* head;		// The first element in the linked list
	Node* tail;		// The last element in the linked list

	// Constructor
	LinkedList()
	{
		// Set the length to 0 for the new empty list
		length = 0;

		// The tail is null because there aren't any elements in the list yet
		head = NULL;
		tail = NULL;
	}

	// Returns a pointer to the node whose key matches dataToFind
	Node* Find(int dataToFind)
	{
		// Start from the head of the list
		Node* nodeToFind = head;

		// For every element in the list
		for (int i = 0; i < length; ++i)
		{
			// If their data matches the data we're looking for
			if (nodeToFind->data == dataToFind)
			{
				// return the pointer to that node
				return nodeToFind;
			}

			// If we don't return, then check the next node
			nodeToFind = nodeToFind->nextNode;
		}

		// If none of the elements in the list match the data, then return null
		return NULL;
	}

	// Inserts a new node at the end of the list with a key equal to newData
	void Insert(int newData)
	{
		// Create a new node
		Node* newNode = new Node();

		// Set the new nodes data
		newNode->data = newData;

		// If there is no current head, then this is the head of the list
		if (head == NULL)
		{
			head = newNode;
		}
		// If this is not the first element, then set the previous node's nextNode to this node
		else
		{
			tail->nextNode = newNode;
		}

		// The previous node is the current tail of the list
		// If this is the first element, then tail is null
		newNode->previousNode = tail;

		// The new node is now the tail of the list
		tail = newNode;

		// The list's count is increased by one
		length++;
	}

	// Deletes the node that delNode points to from the list
	void Delete(Node* delNode)
	{
		// Set the previous node's nextNode to this node's nextNode
		delNode->previousNode->nextNode = delNode->nextNode;

		// Set the next node's previousNode to this node's previousNode
		delNode->nextNode->previousNode = delNode->previousNode;

		// If this node was the tail
		if (tail == delNode)
		{
			// Set the previous node to be the new tail
			tail = delNode->previousNode;
		}

		// If this node was the head
		if (head == delNode)
		{
			// Set the next node to be the head
			head = delNode->nextNode;
		}

		// Delete the node
		delete delNode;

		// Decrease the length
		length--;
	}

	void Display()
	{
		// Start from the head of the list
		Node* current = head;

		std::cout << "\nLinked List:\n\n\tLength: " << length << "\n\n";

		// For every element in the list
		for (int i = 0; i < length; ++i)
		{
			if (i == 0)
			{
				std::cout << "\tHead: " << current->data << std::endl;
			}
			else if (i == length - 1)
			{
				std::cout << "\tTail: " << current->data << std::endl;
			}
			else
			{
				std::cout << "\t" << i + 1 << ": " << current->data << "\n";
			}
			current = current->nextNode;
		}
	}

	void Swap(Node* a, Node* b)
	{
		// Store a's next and previous
		Node* tempANext = a->nextNode;
		Node* tempAPrevious = a->previousNode;

		// Store weather a is the tail or head before making changes to the node
		bool aIsTail = false;
		bool aIsHead = false;
		if (a == tail)
		{
			aIsTail = true;
		}
		if (a == head)
		{
			aIsHead = true;
		}

		// If a is b's next node
		if (b->nextNode == a)
		{
			// The nodes are being swapped, so a now points to b
			a->nextNode = b;
		}
		// If not
		else
		{
			// a now points to whatever b pointed to
			a->nextNode = b->nextNode;
		}

		// If a pointed to b before it was swapped
		if (tempANext == b)
		{
			// The nodes are being swapped, so b is now a's previous
			a->previousNode = b;
		}
		// If not
		else
		{
			// a's previous is now whatever b's was
			a->previousNode = b->previousNode;
		}

		// If b is the head
		if (b == head)
		{
			// a takes b's place as the head, and it doesn't have a previous node
			head = a;
		}
		// If not
		else
		{
			// Make sure a's previous now points to a instead of b
			a->previousNode->nextNode = a;
		}

		// If b's previous wasn't a
		if (b->previousNode != a)
		{
			// b's next node is whatever a's was
			b->nextNode = tempANext;
		}

		// If be was the tial
		if (b == tail)
		{
			// a is the new tail, and it does not have a next pointer
			tail = a;
		}
		// If not
		else
		{
			// Make sure a's next now points to a instead of b
			a->nextNode->previousNode = a;
		}

		// If a's previous was not b before the swap
		if (tempAPrevious != b)
		{
			// Set b's previous to whatever a's was
			b->previousNode = tempAPrevious;
		}

		// If a was the head
		if (aIsHead)
		{
			// b is now the head
			head = b;
			// b's previous is now null
			b->previousNode = NULL;
		}
		// If not
		else
		{
			// Make sure b's previous points to b instead of a
			b->previousNode->nextNode = b;
		}

		// If a was the tail
		if (aIsTail)
		{
			// b is now the tail
			tail = b;
			// b's next is now null
			b->nextNode = NULL;
		}
		// If not
		else
		{
			// Make sure b's next node points to b instead of a
			b->nextNode->previousNode = b;
		}
	}

	void BubbleSort()
	{
		Node* current = head;
		Node* next;
		bool isSorted = true;

		for (int i = 0; i < length - 1; i++)
		{
			// If the current node is greater than the next, swap them
			if (current->data > current->nextNode->data)
			{
				// If we swap, than we need to make another pass through
				isSorted = false;

				// Swap them
				Swap(current, current->nextNode);
			}
			// If not, move onto the next node
			else
			{
				current = current->nextNode;
			}
		}

		// If the list isn't sorted yet, go through again
		if (!isSorted)
		{
			BubbleSort();
		}
	}

	void SelectionSort()
	{
		// Set i to the head of the list
		Node* currentI = head;
		// For every element in the list
		for (int i = 0; i < length; i++)
		{
			// Reset j
			Node* currentJ = currentI;
			// Reset minimum
			Node* minimum = currentI;

			// For every element after the current i
			for (int j = i; j < length; j++)
			{
				// If the current node is less than the current minimum
				if (currentJ->data < minimum->data) {
					// Update the minimum
					minimum = currentJ;
				}

				// Move onto the next node
				currentJ = currentJ->nextNode;
			}
			// Swap out the minimum with the current i
			Swap(minimum, currentI);

			// Move onto the next node
			currentI = minimum->nextNode;
		}
	}
};

using namespace std;

int main()
{
	// Variables
	int amountOfNodes;							// The amount of nodes to add to the linked list
	const int AMOUNT_TO_START = 10;				// The amount of nodes to start with
	const int AMOUNT_TO_INCREMENT = 500;		// The amount to increment by
	const int AMOUNT_OF_TEST = 6;				// The amount of times to test the sort algorithms

	amountOfNodes = AMOUNT_TO_START;

	for (int n = 0; n < AMOUNT_OF_TEST; n++)
	{
		LinkedList linkedListA;					// The linked list
		LinkedList linkedListB;					// The linked list

		for (int i = 0; i < amountOfNodes; ++i)
		{
			linkedListA.Insert(rand() % 100);
			linkedListB.Insert(rand() % 100);
		}

		if (amountOfNodes == AMOUNT_TO_START)
		{
			cout << "Unsorted List:";
			linkedListA.Display();
		}
		else { cout << "\n\n" << amountOfNodes << " Nodes: \n"; }

		{
			cout << "\nBubble Sort:";
			clock_t start = clock();
			linkedListA.BubbleSort();
			clock_t duration = clock() - start;
			float seconds = (((float)duration) / CLOCKS_PER_SEC);
			if (amountOfNodes == AMOUNT_TO_START) { linkedListA.Display(); }
			else
			{
				cout.setf(ios::fixed);
				cout.precision(30);
				cout << " Took " << seconds << " seconds" << endl;
			}
		}

		if (amountOfNodes == AMOUNT_TO_START)
		{
			cout << "Unsorted List:";
			linkedListB.Display();
		}
		{
			cout << "\nSelection Sort:";
			clock_t start = clock();
			linkedListB.SelectionSort();
			clock_t duration = clock() - start;
			float seconds = (((float)duration) / CLOCKS_PER_SEC);
			if (amountOfNodes == AMOUNT_TO_START) { linkedListB.Display(); }
			else
			{
				cout.setf(ios::fixed);
				cout.precision(30);
				cout << " Took " << seconds << " seconds" << endl;
			}
		}
		if (amountOfNodes == AMOUNT_TO_START) { amountOfNodes = 0; }
		amountOfNodes += AMOUNT_TO_INCREMENT;
	} 
}

