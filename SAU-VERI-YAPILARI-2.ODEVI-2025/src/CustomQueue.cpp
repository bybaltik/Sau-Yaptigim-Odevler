/**
* @file B211210091
* @description BST agac
* @course 2.Öğretim A Grubu
* @assignment 2.Ödev
* @date 21.12.2024
* @author Bedirhan Baltık - bedirhan.baltık@ogr.sakarya.edu.tr
*/

#include "CustomQueue.hpp"
#include "Bst.hpp"

CustomQueue::CustomQueue() : front(nullptr), rear(nullptr) {}
CustomQueue::~CustomQueue() {}



void CustomQueue::enqueue(Bst* node) {
    NodeQueue* newNode = new NodeQueue(node);
    if (rear == nullptr) {
        front = rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }
}

Bst* CustomQueue::dequeue() {
    if (front == nullptr) return nullptr;
    NodeQueue* temp = front;
    Bst* node = temp->node;
    front = front->next;
    if (front == nullptr) rear = nullptr;
    delete temp;
    return node;
}

bool CustomQueue::isEmpty() {
    return front == nullptr;
}

int CustomQueue::size() {
    int count = 0;
    NodeQueue* temp = front;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

Bst* CustomQueue::frontNode() {
    if (front == nullptr) return nullptr;
    return front->node;
}
