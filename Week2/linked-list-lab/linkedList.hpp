#include <iostream>
#include <string>

using namespace std;

struct Node
{
    int value;
    Node *next;
};

class LinkedList
{
    // properties = var
private:
    Node *head, *cur;
    int n;

    // constructor = special method
public:
    LinkedList()
    {
        head = nullptr;
        cur = nullptr;
        n = 0;
    }

    // methods = func
    int size() { return n; };

    void traverse(){
        if (n == 0)
        {
            cout << "(empty!)" << endl;
            return;
        }
        cur = head;
        while (cur != nullptr)
        {
            cout << cur->value << "->";
            cur = cur->next;
        }
    }

    Node *getHead() { return head; }

    void insertFront(int val)
    {
        Node *newNode = new Node{val, nullptr};
        newNode->next = head;
        head = newNode;
        n++;
    }

    void insertEnd(int val)
    {
        if (n == 0)
        {
            insertFront(val);
            return;
        }
        cur = head;
        for (int i = 0; i < n - 1; i++)
        {
            cur = cur->next;
        }
        // while(cur->next != nullptr){
        //     cur = cur->next;
        // }
        Node *newNode = new Node{val, nullptr};
        cur->next = newNode;
        n++;
    }

    void insertAt(int val, int pos){ // Between two Nodes
        if (pos > n){
            cout << "Out of node range!\n";
            return;
        }
        if (pos == 0){
            insertFront(val);
            return;
        }
        if (pos == n){
            insertEnd(val);
            return;
        }
        cur = head;
        for (int i = 0; i < pos - 1; i++){
            cur= cur->next;
        }
        Node *newNode = new Node{val, nullptr};
        newNode->next = cur->next;
        cur->next = newNode;
        n++;
    }

    void deleteFront(){
        if(n==0){
            cout<<"No node to delete!\n";
            return;
        }
        Node* tmp = head;
        head = head->next;
        delete tmp;
        n--;
    }

    void deleteEnd(){
        if(n==0){
            cout<<"No node to delete!\n";
            return;
        }
        cur = head;
        while(cur->next->next != nullptr)
            cur = cur->next;
        delete cur->next;
        cur->next = nullptr;
        n--;
    }

    void deleteAt(int pos){// Between two Nodes
        if (pos > n-1){
            cout << "Out of node range!\n";
            return;
        }
        if (pos == 0){
            deleteFront();
            return;
        }
        if (pos == n-1){
            deleteEnd();
            return;
        }
        cur = head;
        for (int i = 0; i < pos -1; i++){
            cur= cur->next;
        }
        Node* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
    }

    void swap2Nodes(int pA, int pB) {
        // check the number of nodes must have at least 2
        if (n < 2) {
            cout << "Need at least 2 nodes to swap (currently have " << n << ")\n";
            return;
        }
        
        // check range of the valid position
        if (pA < 0 || pB < 0 || pA >= n || pB >= n) {
             cout << "Error: Position out of range [0, " << n-1 << "]\n";
             return;
        }

        //the same position, no need to swap.
        if (pA == pB) return; 

        //guarantee that pA is always less than pB for simplicity
        if (pA > pB) {
            swap(pA, pB); 
        }
        
        // Find four required pointers (A, B, and their previous)
        Node* pA_prev = nullptr;
        Node* pB_prev = nullptr;
        Node* currA = head;
        Node* currB = head;

        Node* temp_curr = head;
        Node* temp_prev = nullptr;
        int count = 0;

        while (temp_curr != nullptr) {
            if (count == pA) {
                pA_prev = temp_prev;
                currA = temp_curr;
            }
            if (count == pB) {
                pB_prev = temp_prev;
                currB = temp_curr;
                break; 
            }

            temp_prev = temp_curr;
            temp_curr = temp_curr->next;
            count++;
        }

        // Re-wire pointers
        
        // Connect node before A to B
        if (pA_prev != nullptr) {
            pA_prev->next = currB;
        } else {
            head = currB; 
        }

        // Connect node before B to A
        if (pB_prev != nullptr) {
            pB_prev->next = currA;
        } else {
            head = currA;
        }

        // Swap 'next' pointers of nodes themselves (currA and currB)
        Node* tempNext = currB->next;
        currB->next = currA->next;
        currA->next = tempNext;
    }

    
    int search(int target_val) {
        if (head == nullptr) {
            cout<<"List is empty!\n";
            return -1;
        }

        Node* current = head;
        int position = 0;

        // Traverse the list until the end (nullptr)
        while (current != nullptr) {
            if (current->value == target_val) {
                return position; // Value found
            }
            
            // Move to next node, increment position counter
            current = current->next;
            position++;
        }
        cout<<"Target value not found!\n";
        return -1; 
    }
};