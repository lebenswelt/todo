#include <cstddef>
#include <iostream>

#define eol "\n"
using namespace std;

class LinkedList{
    // Struct inside the class LinkedList
    // This is one node which is not needed by the caller. It is just
    // for internal work.
    struct Node {
        int x;
        Node *next;
    };

// public member
public:
    // constructor
    LinkedList(){
        head = NULL; // set head to NULL
	cur = NULL;
    }

    // This prepends a new value at the beginning of the list
    void addValue(int val){
        Node *n = new Node();   // create new Node
        n->x = val;             // set value
        n->next = head;         // make the node point to the next node.
                                //  If the list is empty, this is NULL, so the end of the list --> OK
        head = n;               // last but not least, make the head point at the new node.
	if( cur == NULL)
		cur = head;
    }

	void rewind(){
		cur = head;
	}
	void next(){
		if( cur != NULL )
			cur = cur->next;
	}
	int getValue(){
		if( cur != NULL )
			return cur->x;
		return 0; // really we should raise exception
	}
	int hasValue(){
		return ( cur != NULL ? true : false );
	}

// private member
private:
    Node *head; // this is the private member variable. It is just a pointer to the first Node
    Node *cur;
};

int main() {
    LinkedList list;

    list.addValue(5);
    list.addValue(10);
    list.addValue(20);
	list.rewind();

	while( list.hasValue()){
		cout << "Value: " << list.getValue() << eol;
		list.next();
	}
	list.rewind();
	while( list.hasValue()){
		cout << "Value: " << list.getValue() << eol;
		list.next();
	}
    return 0;
}

//Alternate (and more likely source of guidance) is at https://www.geeksforgeeks.org/custom-tree-problem/
//It implements two arrays rather than a linked list to generate a forest of multichild trees.
//
