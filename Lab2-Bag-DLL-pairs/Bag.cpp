#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;


Bag::Bag() {
    //nrElems = 0;
    head = nullptr;
    tail = nullptr;
    nrElems = 0;
}


void Bag::add(TElem elem) {
    Node * current = head;
    //elem already in linked list
    while (current != nullptr) {
        if (current->elem.first == elem) {
            current->elem.second++;
            return;
        }
        current = current->next;
    }
    
    //elem not found above
    TPair newElem = std::make_pair(elem, 1);
    Node * newNode = new Node(newElem);
    newNode->next = head;
    newNode->prev = nullptr;
    
    
    // If the list was not empty, update the old head's prev pointer
    if (head != nullptr) {
        head->prev = newNode;
    }

    head = newNode;  // The new node becomes the head

    // If the list was empty, set the tail to the new node as well
    if (tail == nullptr) {
        tail = newNode;
    }

    nrElems++;
}


bool Bag::remove(TElem elem) {
	//search in list, stops when found;
    Node * current = head;
    while (current != nullptr && current->elem.first != elem) {
        current = current->next;
    }
    
    // If current is nullptr, element is not found, return false
    if (current == nullptr) {
        return false;
    }
    //decrement freq of elem
    current->elem.second--;
    
    //if freq == 0 also remove the pair element;
    if (current->elem.second == 0) {
        //
        if (current != nullptr) {
            if (current == head) {
                //delete head
                head = head->next;
                if (head != nullptr) {
                    head->prev = nullptr;
                } else {
                    tail=nullptr;
                }
            }
            
            else if (current == tail) {
                //delete tail
                tail = tail->prev;
                if (tail != nullptr) {
                    tail->next = nullptr;
                }
            }
            else {
                //[[currentNode].next].prev ← [currentNode].prev
                //[[currentNode].prev].next ← [currentNode].next
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
        }
        delete current;
    }
	return true;
}


bool Bag::search(TElem elem) const {
    Node * current = head;
    while (current != nullptr) {
        if (current->elem.first == elem) {
            return true;
        }
        current = current->next;
    }
	return false;
}

int Bag::nrOccurrences(TElem elem) const {
    Node * current = head;
    while (current != nullptr) {
        if (current->elem.first == elem) {
            return current->elem.second;
        }
        current = current->next;
    }
	return 0;
}


int Bag::size() const {
    int sizeCounter = 0;
    Node * current = head;
    while (current != nullptr) {
        sizeCounter += current->elem.second;
        current = current->next;
    }
	return sizeCounter;
}


bool Bag::isEmpty() const {
    //return nrElems == 0;
    return head == nullptr;
}

BagIterator Bag::iterator() const {
	return BagIterator(*this);
}


Bag::~Bag() {
	//TODO - Implementation
}

