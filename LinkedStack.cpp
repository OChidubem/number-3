#include "LinkedStack.h"
#include <cassert>
#include <string>

template<class ItemType>
LinkedStack<ItemType>::LinkedStack() : topPtr(nullptr) {}

template<class ItemType>
LinkedStack<ItemType>::LinkedStack(const LinkedStack<ItemType>& originalStack) {
    auto originalChainPtr = originalStack.topPtr;
    if (originalChainPtr == nullptr) {
        topPtr = nullptr;
    } else {
        topPtr = new Node<ItemType>(originalChainPtr->getItem());
        auto myChainTailPtr = topPtr;
        originalChainPtr = originalChainPtr->getNext();
        while (originalChainPtr != nullptr) {
            auto nextItem = originalChainPtr->getItem();
            auto itemNodePtr = new Node<ItemType>(nextItem);
            myChainTailPtr->setNext(itemNodePtr);
            myChainTailPtr = myChainTailPtr->getNext();
            originalChainPtr = originalChainPtr->getNext();
        }
        myChainTailPtr->setNext(nullptr);
    }
}

template<class ItemType>
LinkedStack<ItemType>::~LinkedStack() {
    while (!isEmpty()) {
        pop();
    }
}

template<class ItemType>
bool LinkedStack<ItemType>::isEmpty() const noexcept {
    return topPtr == nullptr;
}

template<class ItemType>
bool LinkedStack<ItemType>::push(const ItemType& someItem) {
    auto itemNodePtr = new Node<ItemType>(someItem, topPtr);
    topPtr = itemNodePtr;
    return true;
}

template<class ItemType>
bool LinkedStack<ItemType>::pop() noexcept {
    bool result = false;
    if (!isEmpty()) {
        auto nodeToDeletePtr = topPtr;
        topPtr = topPtr->getNext();
        nodeToDeletePtr->setNext(nullptr);
        delete nodeToDeletePtr;
        result = true;
    }
    return result;
}

template<class ItemType>
ItemType LinkedStack<ItemType>::peek() const {
    assert(!isEmpty());
    return topPtr->getItem();
}

// Explicit template instantiations if needed
template class LinkedStack<int>;       // Example for int
template class LinkedStack<double>;    // Example for double
template class LinkedStack<std::string>;  // Example for std::string
