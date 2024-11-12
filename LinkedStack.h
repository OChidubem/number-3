#ifndef LINKED_STACK_H
#define LINKED_STACK_H

#include "StackInterface.h"
#include "Node.h"

template<class ItemType>
class LinkedStack : public StackInterface<ItemType> {
private:
    Node<ItemType>* topPtr;  // Pointer to first node in the stack

public:
    LinkedStack();  // Default constructor
    LinkedStack(const LinkedStack<ItemType>& originalStack);  // Copy constructor
    virtual ~LinkedStack();  // Destructor

    bool isEmpty() const noexcept override;
    bool push(const ItemType& someItem) override;
    bool pop() noexcept override;
    ItemType peek() const override;
};

#endif // LINKED_STACK_H
