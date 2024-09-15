#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;


BagIterator::BagIterator(const Bag& c): bag(c)
{
    currentElem = bag.head;
    freqCount = 1;
}

void BagIterator::first() {
    currentElem = bag.head;
    freqCount = 1;
}

void BagIterator::next() {
    if (!valid()) {
        throw exception();
    }
    freqCount++;
    if (freqCount > currentElem->elem.second) {
        currentElem = currentElem->next;
        freqCount = 1;
    }
}


bool BagIterator::valid() const {
    return currentElem != nullptr;
}



TElem BagIterator::getCurrent() const
{
    if (!valid()) {
        throw exception();
    }
    return currentElem->elem.first;
}
