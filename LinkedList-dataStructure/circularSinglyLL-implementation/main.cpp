/*
	This is a circular singly linked list implementation.

	A circular singly linked list is a lot like a regular singly linked list,
	except the last node links back to the first node, AKA the head.
*/

#include <iostream>

struct CLLNode
{
	CLLNode() : next(nullptr), data(0) {}
	CLLNode(int d) : next(nullptr), data(d) {}
	~CLLNode() {}

	int data;
	CLLNode* next; // create a pointer to the next node in the list
};

class CLList
{
private:
	int length;
	CLLNode* head; // create a pointer to the first node in the list
public:
	CLList() : head(nullptr), length(0) {} // create new empty list

	~CLList()
	{
		CLLNode* cur = head;  // create temporary node to read through the list

		// since a circular list links back to the head at the end, you need to
		// count how many elements are in the list using the length
		for (int i = 0; i < length; ++i)
		{
			CLLNode* node = cur->next;
			delete cur;
			cur = node;
		}
	}




	int getLength()
	{
		return length;
	}




	bool search(int val)
	{
		CLLNode* cur = head; // temporary node to read through the list

		for (int i = 0; i < length; ++i)
		{
			if (val == cur->data)
			{
				return true;
			}
			cur = cur->next; // move on to the next node in the list
		}
		return false;
	}




	void insertAtBeg(int val)
	{
		CLLNode* newNode = new CLLNode(val); // store new value in a new node

		// empty list
		if (!head)
		{
			head = newNode;
			newNode->next = newNode; // last node links with the head
		}

		else
		{
			CLLNode* cur = head; // create temporary node to read through the list

			for (int i = 0; i < length - 1; ++i)
			{
				cur = cur->next;
			}

			// cur is now the last node in the list
			cur->next = newNode;
			newNode->next = head;
			head = newNode;
		}
		++length;
	}




	void insertAtIndex(int val, int i)
	{
		// list starts at index 0

		// invalid index to insert at
		if (i < 0 || i > length)
		{
			std::cout << "Invalid index." << std::endl;
			return;
		}

		// inserting at index 0 is the same as inserting at the beginning
		else if (i == 0)
		{
			insertAtBeg(val);
		}

		// inserting at this index is the same as inserting at the end
		else if (i == length)
		{
			insertAtEnd(val);
		}

		else
		{
			CLLNode* newNode = new CLLNode(val); // store new value in a new node
			CLLNode* cur = head; // create temporary node to read through the list

			for (int j = 0; j < i - 1; ++j)
			{
				cur = cur->next;
			}

			// cur is now the node before the insertion point
			newNode->next = cur->next;
			cur->next = newNode;
			++length;
		}
	}




	void insertAtEnd(int val)
	{
		CLLNode* newNode = new CLLNode(val); // store new value in a new node

		// empty list
		if (!head)
		{
			head = newNode;
			newNode->next = newNode;
		}

		else
		{
			CLLNode* cur = head; // create temporary node to read through the list
			for (int i = 0; i < length - 1; ++i)
			{
				cur = cur->next;
			}

			// cur is now the last element in the list
			cur->next = newNode;
			newNode->next = head; // last node links with the head
		}
		++length;
	}




	void deleteAtBeg()
	{
		// empty list
		if (!head)
		{
			return;
		}

		// only one element in list
		else if (!head->next)
		{
			delete head;
			head = nullptr;
		}

		else
		{
			CLLNode* tmp = head;
			head = head->next;
			delete tmp;
		}
		--length;
	}




	void deleteAtIndex(int i)
	{
		// list starts at index 0

		// invalid index to delete at
		if (i < 0 || i >= length)
		{
			std::cout << "Invalid index." << std::endl;
			return;
		}

		// deleting at index 0 is the same as delete the first node
		else if (i == 0)
		{
			deleteAtBeg();
		}

		// deleting at this index is the same as deleting at the last node
		else if (i == length - 1)
		{
			deleteAtEnd();
		}

		else
		{
			CLLNode* cur = head; // temporary node to read through the list

			for (int j = 0; j < i - 1; ++j)
			{
				cur = cur->next;
			}

			// cur is now the node before the deletion point

			CLLNode* tmp;
			tmp = cur->next->next; // store the node after the deletion point
			delete cur->next; // free memory at the deletion point
			cur->next = tmp;
			--length;
		}
	}




	void deleteAtEnd()
	{
		// empty list
		if (!head)
		{
			return;
		}

		// only one element in list
		else if (!head->next)
		{
			delete head;
			head = nullptr;
		}

		else
		{
			CLLNode* cur = head; // temporary node to read through the list

			for (int i = 0; i < length - 2; ++i)
			{
				cur = cur->next;
			}

			// cur->next is now the last node in the list
			delete cur->next;
			cur->next = head;
		}
		--length;
	}




	void display() {
		CLLNode* cur = head; // temporary node to read through the list

		// since a circular list links back to the head at the end, you need to
		// count how many elements are in the list using the length
		std::cout << "Data: ";

		for (int i = 0; i < length; ++i)
		{
			std::cout << cur->data << ' ';
			cur = cur->next;
		}

		std::cout << std::endl;
	}
};


int main() {
	CLList list = CLList();

	list.insertAtEnd(1);
	list.insertAtEnd(2);
	list.insertAtEnd(4);
	list.insertAtEnd(5);

	list.display();

	list.insertAtBeg(0);

	list.display();

	list.deleteAtEnd();

	list.display();

	return 0;
}