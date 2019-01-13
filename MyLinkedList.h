#ifndef MyLinkedList_H
#define MyLinkedList_H

class MyLinkedList
{
private:
    struct Node
    {
        int value;
        Node *next;
    };

    Node* head;

public:
    // Constructor
    MyLinkedList()
    { head = NULL; } // make head point to NULL

    // Mutators
    void insert(int);
    void remove(int);

    // Accessors
    bool isEmpty() const;
    bool search(int) const;
    void print() const;

    // Destructor
    ~MyLinkedList();
};

// Function to insert a new node in order in the linked list
void MyLinkedList::insert(int val)
{
    // Create a new node
    Node* newNode = new Node;
    newNode->value = val;
    newNode->next = NULL;

    // Case 1: empty linked list
    if(head == NULL)
    {
        head = newNode; //head points to the new node

        newNode->next = NULL; // newNode points to the next node
                              // also equivalent to head->next = NULL;

        return;
    }

    // case 2: insert the new node to be the first node
    if(head->value > newNode->value)
    {
        newNode->next = head;

        head = newNode;

        return;
    }

    // case 3: find the insertion point to the rest of the linked list
    // Create two pointers to traverse the list
    Node *trail = head, // pointer to trail behind one node, to point to node before point of insertion
         *lead = head->next;  // pointer to locate the node with data value greater than that of node to be inserted

    // Loop to find the insertion point. Until lead points to NULL or the newNode's value is greater than the lead node's value
    for( ; lead != NULL && lead->value < newNode->value; trail = trail->next, lead = lead->next);

    // insert the new node between nodes or at the end of the list
    trail->next = newNode; // trail points to the new node
    newNode->next = lead; // newnode points to the lead
}

// Function to remove a node by a given target value
void MyLinkedList::remove(int num)
{

    // case 1: empty linked list, do nothing
    if(head == NULL)
            return;

    // case 2: the node to remove is the first node
    if(head->value == num)
    {
        Node* r = head; // r points to the first node

        head = head->next;  // head points to the new head node

        delete r;   // delete the old head node

        return;
    }

    //case 3: search the rest of the linked list to look for the node to be deleted
    // Create two helper pointers
    Node* prev = head;  // pointer to point to the node before the node to be deleted
    Node* lead = head->next;    // pointer to locate the node to be deleted

    // Loop to search the node to be deleted. Search until lead points to NULL
    // or the value of the node lead points to is the value we want to remove
    for( ;lead != NULL && lead->value != num; prev = prev->next, lead = lead->next);

    if(lead == NULL) // if value is not found in the linked list, do nothing
        return;

    // if value is found, make prev points to the next node of the lead node
    prev->next = lead->next;

    delete lead; // lead points to the node we want to remove
}

// Function to know if the linked list is empty or not
bool MyLinkedList::isEmpty() const
{
    // If list is empty, return true
    // Otherwise return false;
    if(head == NULL)
        return true;

    else
        return false;
}

// Function to search for a target value in the linked list
bool MyLinkedList::search(int integer) const
{
    // If the integer is in the linked list, return true
    // Otherwise return false
    Node* s = NULL;
    s = head;

    while(s) // Keep looping until s points to NULL
    {
        if(integer == s->value)  //if the integer is found in the node, return true
            return true;

        s = s->next;  // set s to  point to the next node
    }

    // If we get here, the value is not found in the linked list, so return false
    return false;
}

// Function to print the linked list
void MyLinkedList::print() const
{
    Node *p = NULL; // pointer to help print the value in the node
    p = head; // set p to point to the address where head is pointing

    cout << "Linked List: ";

    while(p) // loop until p returns null
    {
        cout << p->value << " "; // print the value in the node
        p = p->next; // set p to point to the next node
                     // making the p point node by node
    }

    cout << endl;
}

// Destructor to destroy the entire list
MyLinkedList::~MyLinkedList()
{
        // create a helper pointer to destroy each node
        Node* d = NULL;

        while(head != NULL) // loop until head points to NULL
        {
            d = head;  // set d to point to the address where head is pointing
            head = head->next; // set head to point to the next node
            delete d; // delete the node
        }
}

#endif


