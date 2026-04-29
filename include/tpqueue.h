// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
    struct Node {
        T item;
        Node* nextNode;
        Node(const T& element) : item(element), nextNode(nullptr) {}
    };
    Node* top;

 public:
    TPQueue() : top(nullptr) {}

    ~TPQueue() {
        while (top) {
            Node* tempNode = top;
            top = top->nextNode;
            delete tempNode;
        }
    }

    TPQueue(const TPQueue&) = delete;
    TPQueue& operator=(const TPQueue&) = delete;

    void push(const T& val) {
        Node* newNode = new Node(val);
        if (!top || top->item.priority < val.priority) {
            newNode->nextNode = top;
            top = newNode;
        } else {
            Node* current = top;
            while (current->nextNode && current->nextNode->item.priority >= val.priority) {
                current = current->nextNode;
            }
            newNode->nextNode = current->nextNode;
            current->nextNode = newNode;
        }
    }

    T pop() {
        Node* tempNode = top;
        T popped = tempNode->item;
        top = top->nextNode;
        delete tempNode;
        return popped;
    }
};

struct SYM {
    char character;
    int priority;
};

#endif  // INCLUDE_TPQUEUE_H_
