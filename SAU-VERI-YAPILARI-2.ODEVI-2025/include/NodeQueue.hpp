/**
* @file B211210091
* @description BST agac
* @course 2.Öğretim A Grubu
* @assignment 2.Ödev
* @date 21.12.2024
* @author Bedirhan Baltık - bedirhan.baltık@ogr.sakarya.edu.tr
*/

#ifndef NODEQUEUE_HPP
#define NODEQUEUE_HPP

class Bst; // Forward declaration

class NodeQueue {
public:
    Bst* node;
    NodeQueue* next;

    NodeQueue(Bst* n);
};

#endif
