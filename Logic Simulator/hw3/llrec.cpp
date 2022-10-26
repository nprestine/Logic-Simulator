#include "llrec.h"
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <list>
//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){ //has address of node pointer
    if(head == nullptr){ //once at end of list then set all to NULL
        smaller = larger = nullptr;
        return;
    }
    else if (head->val > pivot){ //take care of case with val larger than pivot
        larger = head;
        head = head->next;
        return llpivot(head, smaller, larger->next, pivot);
    }
    else{ //take care of remaining cases (lower than pivot)
        smaller = head;
        head = head->next;
        return llpivot(head, smaller->next, larger, pivot);
    }
}