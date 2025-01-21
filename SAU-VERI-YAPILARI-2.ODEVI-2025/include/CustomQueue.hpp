/**
* @file B211210091
* @description BST agac
* @course 2.Öğretim A Grubu
* @assignment 2.Ödev
* @date 21.12.2024
* @author Bedirhan Baltık - bedirhan.baltık@ogr.sakarya.edu.tr
*/

#ifndef CUSTOMQUEUE_HPP
#define CUSTOMQUEUE_HPP
using namespace std;

#include "NodeQueue.hpp"

class CustomQueue {
private:
    NodeQueue* front;
    NodeQueue* rear;

public:
    CustomQueue();
    ~CustomQueue();
    void enqueue(Bst* node);
    Bst* dequeue();
    bool isEmpty();
    int size();
    Bst* frontNode();
};

#endif

