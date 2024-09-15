#pragma once
//DO NOT INCLUDE BAGITERATOR
#include <utility>

//DO NOT CHANGE THIS PART
#define NULL_TELEM -111111;
typedef int TKey;
typedef int TFreq;

typedef TKey TElem;
typedef std::pair<TKey, TFreq> TPair;
#define NULL_TPAIR pair<TKey, TFreq>(-111111, -111111);

struct Node {
    Node * next; //dll node forward
    Node * prev; //dll node backwards
    TPair elem;  // elem struct that has (key, freq) int's
    Node(const TPair& e): elem(e), next(nullptr), prev(nullptr) {} //Node struct constructor
    //don't understand the constructor syntax yet
};

class BagIterator;
class Bag {

private:
    Node * head;
    Node * tail;
    int nrElems;


	//DO NOT CHANGE THIS PART
	friend class BagIterator;
public:
	//constructor
	Bag();

	//adds an element to the bag
	void add(TElem e);

	//removes one occurence of an element from a bag
	//returns true if an element was removed, false otherwise (if e was not part of the bag)
	bool remove(TElem e);

	//checks if an element appearch is the bag
	bool search(TElem e) const;

	//returns the number of occurrences for an element in the bag
	int nrOccurrences(TElem e) const;

	//returns the number of elements from the bag
	int size() const;

	//returns an iterator for this bag
	BagIterator iterator() const;

	//checks if the bag is empty
	bool isEmpty() const;

	//destructor
	~Bag();
};
