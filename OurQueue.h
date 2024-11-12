// OurQueue.h
#ifndef OUR_QUEUE_H
#define OUR_QUEUE_H

#include <queue>
#include "QueueInterface.h"  // Include the QueueInterface header

/**
 * @brief A concrete implementation of a queue using STL's std::queue.
 * 
 * This class implements the QueueInterface and provides basic queue operations 
 * such as enqueue, dequeue, peek, and clear. It is backed by the standard 
 * library's std::queue container.
 * 
 * @tparam ItemType The type of elements held in the queue.
 */
template <typename ItemType>
class OurQueue : public QueueInterface<ItemType> {
private:
    std::queue<ItemType> queue;  /**< Internal STL queue to hold the items */

public:
    /**
     * @brief Default constructor for OurQueue.
     */
    OurQueue() = default;

    /**
     * @brief Checks if the queue is empty.
     * 
     * @return True if the queue is empty, otherwise false.
     */
    bool isEmpty() const override {
        return queue.empty();
    }

    /**
     * @brief Adds an item to the back of the queue.
     * 
     * @param item The item to be added to the queue.
     */
    void enqueue(const ItemType& item) override {
        queue.push(item);
    }

    /**
     * @brief Removes the front item of the queue.
     * 
     * @return True if an item was successfully removed, otherwise false.
     */
    bool dequeue() override {
        if (!queue.empty()) {
            queue.pop();
            return true;
        }
        return false;
    }

    /**
     * @brief Returns the front item of the queue.
     * 
     * @return The front item in the queue.
     * @throws std::runtime_error if the queue is empty.
     */
    ItemType peekFront() const override {
        if (queue.empty()) {
            throw std::runtime_error("Queue is empty!");
        }
        return queue.front();
    }

    /**
     * @brief Clears all items from the queue.
     */
    void clear() override {
        while (!queue.empty()) {
            queue.pop();
        }
    }

    /**
     * @brief Prints the contents of the queue.
     * 
     * Prints all the items in the queue, from front to back.
     * 
     * @note This method is primarily for debugging purposes.
     */
    void printQueue() const override {
        if (queue.empty()) {
            std::cout << "Queue is empty.\n";
        } else {
            std::queue<ItemType> tempQueue = queue;  // Copy the queue
            std::cout << "Queue items: ";
            while (!tempQueue.empty()) {
                std::cout << tempQueue.front() << " ";
                tempQueue.pop();
            }
            std::cout << std::endl;
        }
    }

    /**
     * @brief Destructor for OurQueue.
     * 
     * The destructor ensures proper cleanup (though no explicit cleanup is 
     * needed for std::queue).
     */
    ~OurQueue() = default;
};

#endif
