#ifndef STACK_INTERFACE_
#define STACK_INTERFACE_

template<class ItemType>
class StackInterface {
public:
    /** 
     * @brief Checks if the stack is empty.
     * @return true if the stack is empty, false otherwise.
     */
    virtual bool isEmpty() const noexcept = 0;

    /** 
     * @brief Pushes an item onto the stack.
     * @param someItem The item to be pushed onto the stack.
     * @return true if the item was successfully pushed, false otherwise.
     */
    virtual bool push(const ItemType& someItem) = 0;

    /** 
     * @brief Pops the top item from the stack.
     * @return true if the item was successfully popped, false otherwise.
     */
    virtual bool pop() noexcept = 0;

    /** 
     * @brief Peeks at the top item of the stack without removing it.
     * @return The top item of the stack.
     * @throw std::runtime_error if the stack is empty.
     */
    virtual ItemType peek() const = 0;

    virtual ~StackInterface() {}  // Virtual destructor to allow proper cleanup of derived classes
};

#endif // STACK_INTERFACE_
