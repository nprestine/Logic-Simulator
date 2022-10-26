#include <iostream>
#include <fstream>
#include <functional>
#include "llrec.h"

using namespace std;

/**
 * Reads integers (separated by whitespace) from a file
 * into a linked list.
 *
 * @param[in] filename
 *  The name of the file containing the data to read
 * @return
 *  Pointer to the linked list (or NULL if empty or the
 *  file is invalid)
 */
Node* readList(const char* filename);

/**
 * Prints the integers in a linked list pointed to
 * by head.
 */
void print(Node* head);

/**
 * Deallocates the linked list nodes
 */
void dealloc(Node* head);


Node* readList(const char* filename)
{
    Node* h = NULL;
    ifstream ifile(filename);
    int v;
    if( ! (ifile >> v) ) return h;
    h = new Node(v, NULL);
    Node *t = h;
    while ( ifile >> v ) {
        t->next = new Node(v, NULL);
        t = t->next;
    }
    return h;
}

void print(Node* head)
{
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void dealloc(Node* head)
{
    Node* temp;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

// -----------------------------------------------
//   Add any helper functions or
//   function object struct declarations
// -----------------------------------------------
 struct funct{ //struct to mimic filter condition
        bool operator() (int x){
            if((x+1)%2 ==1) return true;
            else return false;
        }
    };



int main(int argc, char* argv[])
{
    if(argc < 2) {
        cout << "Please provide an input file" << endl;
        return 1;
    }

    // -----------------------------------------------
    // Feel free to update any code below this point
    // -----------------------------------------------
    Node* head = readList(argv[1]);
    cout << "Original list: ";
    print(head);

    // Test out your linked list code
    Node* smaller;
    Node* larger;
    smaller = nullptr;
    larger = nullptr;
    llpivot(head, smaller, larger, 8); //test pivot
    cout<< "smaller:";
    print(smaller);
    cout <<"larger:";
    print(larger);
    cout << endl;
    dealloc(smaller);
    dealloc(larger);
    Node* head2 = readList(argv[1]);
    cout << "Input list: ";
    print(head2);
    head2 = llfilter(head2,funct()); //test filter
    cout<< "<<list filtered to exclude even numbers>>" << endl;
    cout <<"Filtered list: ";
    print(head2);
    dealloc(head2);

    cout << endl;
    return 0;

   
}
