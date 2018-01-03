//
//  Assigned by:
//
//  File Name:        BST.h
//  Files in project: TEST.cpp, BST.h, Node.h
//

#include <iostream>
#include "Node.h"

using namespace std;

template <class T>
class BST {
public:
    BST();
    ~BST();
    void insert(T const &data);
    bool exists(T const &data) const;
    int size() const;
    void print() const;
    void destroy();
    friend ostream &operator<<(ostream &os, BST const &tree) {
        // Print tree using operator overloading '<<'
        // calling public print() method
        tree.print();
        return os;
    }

private:
    Node<T> *root;
	int tree_size;
    void insert(Node<T> *node, T const &data);
    bool exists(Node<T> *node, T const &data) const;
    void print(Node<T> const *node) const;
    void destroy(Node<T> *node);
};

template <class T>
BST<T>::BST()
: root(nullptr), tree_size(0) {}

template <class T>
BST<T>::~BST() {
    this->destroy();        // Destroy all nodes
}

// Public
template <class T>
void BST<T>::insert(T const &data) {
	if (root != nullptr) {
		this->insert(this->root, data);
	}
	else {
		this->root = new Node<T>;
		this->root->data = data;
		this->root->right = NULL;
		this->root->left = NULL;
	}
	this->tree_size++;
}

// Private
// Insert data recursively
template <class T>
void BST<T>::insert(Node<T> *node, T const &data) {
	if (data < node->data) {
		if (node->left != nullptr) {
			this->insert(node->left,data);
		}
		else {
			node->left = new Node<T>;
			node->left->data = data;
			node->left->left = nullptr;   
			node->left->right = nullptr;
		}
	}
	else if (data >= node->data) {
		if (node->right != nullptr) {
			this->insert(node->right,data);
		}
		else {
			node->right = new Node<T>;
			node->right->data = data;
			node->right->left = nullptr;
			node->right->right = nullptr;
		}
	}
}

// Public
template <class T>
bool BST<T>::exists(T const &data) const {
    return this->exists(this->root, data);
}

// Private
// Check if a given value exists in tree
template <class T>
bool BST<T>::exists(Node<T> *node, T const &data) const {
    if (node == nullptr) {
        return false;
    }
    if (node->data == data) {
        return true;
    }
    return this->exists(node->data > data ? node->left : node->right, data);
}

// Public
template <class T>
int BST<T>::size() const {
    return this->tree_size;
}

// Public
template <class T>
void BST<T>::destroy() {
    this->destroy(this->root);
}

// Private
// Destroy tree's nodes recursively - doesn't destroy root node
template <class T>
void BST<T>::destroy(Node<T> *node) {
	if (node != nullptr) {
		this->destroy(node->left);
		this->destroy(node->right);
		delete node;
	}
}

// Public
template <class T>
void BST<T>::print() const {
    if (!this->root) {
        cout << "The tree is empty" << endl;
    }
    else {
        this->print(this->root);
    }
}

// Private
// Print tree's nodes - inorder print
template <class T>
void BST<T>::print(Node<T> const *node) const {
    if (node != nullptr) {
        this->print(node->left);
        cout << node->data << " ";
        this->print(node->right);
    }
}
