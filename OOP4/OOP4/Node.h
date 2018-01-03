//
//  Assigned by:
//
//  File Name:        Node.h
//  Files in project: TEST.cpp, BST.h, Node.h
//

#ifndef Node_h
#define Node_h

template <class T>
class Node {
public:
    // Data members
    T data;
    Node<T> *left;
    Node<T> *right;
};

#endif /* Node_h */
