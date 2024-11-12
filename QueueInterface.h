// QueueInterface.h
#ifndef QUEUE_INTERFACE_H
#define QUEUE_INTERFACE_H

/**
 * @brief Interface for a Queue data structure.
 * 
 * This abstract class defines the essential operations that a queue must implement.
 * Classes that inherit from this interface should implement these methods.
 * 
 * @tparam ItemType The type of elements held in the queue.
 */
template <typename ItemType>
class QueueInterface {
public:
    /**
     * @brief Virtual destructor to allow proper cleanup of derived classes.
     */
    virtual ~QueueInterface() {}

    /**
     * @brief Checks if the queue is empty.
     * 
     * @return True if the queue is empty, otherwise false.
     */
    virtual bool isEmpty() const = 0;

    /**
     * @brief Adds an item to the queue.
     * 
     * @param item The item to be added to the queue.
     */
    virtual void enqueue(const ItemType& item) = 0;

    /**
     * @brief Removes the front item from the queue.
     * 
     * @return True if an item was successfully removed, otherwise false.
     */
    virtual bool dequeue() = 0;

    /**
     * @brief Returns the front item of the queue.
     * 
     * @return The front item in the queue.
     * @throws std::runtime_error if the queue is empty.
     */
    virtual ItemType peekFront() const = 0;

    /**
     * @brief Clears all items from the queue.
     */
    virtual void clear() = 0;

    /**
     * @brief Prints the contents of the queue.
     * 
     * This is an optional method for debugging and visualizing the queue's state.
     */
    virtual void printQueue() const = 0;
};

#endif
