#ifndef NODE_H
#define NODE_H

template<class ItemType>
class Node {
private:
    ItemType item;              // Data for the node
    Node<ItemType>* next;       // Pointer to the next node

public:
    Node();  // Default constructor
    Node(const ItemType& anItem, Node<ItemType>* nextNodePtr = nullptr);  // Parametrized constructor
    
    void setItem(const ItemType& anItem);
    void setNext(Node<ItemType>* nextNodePtr);
    
    ItemType getItem() const;
    Node<ItemType>* getNext() const;
};

#endif // NODE_H
