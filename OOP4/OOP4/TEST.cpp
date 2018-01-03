//
//  Assigned by:
//
//  File Name:        TEST.cpp
//  Files in project: TEST.cpp, BST.h, Node.h
//

#include <iostream>
#include "BST.h"

using namespace std;

void main() {
    BST<int> intBst;
    intBst.insert(11);
    intBst.insert(12);
    intBst.insert(6);
    intBst.insert(1);
    intBst.insert(10);
    intBst.insert(100);
    cout << "Int tree inorder: " << intBst << endl;
    if (intBst.exists(6) == true) {
        cout << "6 IS IN TREE!!!" << endl;
    }
    if (intBst.exists(999) == false) {
        cout << "999 IS NOT IN TREE!!!" << endl;
    }
    cout << "Int tree size is " << intBst.size() << endl;
    cout << endl;

    BST<double> doubleBst;
    doubleBst.insert(1.1);
    doubleBst.insert(1.2);
    doubleBst.insert(6.6);
    doubleBst.insert(12.3);
    doubleBst.insert(10.2);
    doubleBst.insert(100.9);
    cout << "Double tree inorder: " << doubleBst << endl;
    if (doubleBst.exists(6.6) == true) {
        cout << "6.6 IS IN TREE!!!" << endl;
    }
    if (doubleBst.exists(99.9) == false) {
        cout << "99.9 IS NOT IN TREE!!!" << endl;
    }
    cout << "Double tree size is " << doubleBst.size() << endl;
    cout << endl;

    BST<int> emptyBst;
    cout << "Empty tree inorder: " << emptyBst;
    if (emptyBst.exists(6) == false) {
        cout << "6.6 IS NOT IN TREE!!!" << endl;
    }
    if (emptyBst.exists(9) == false) {
        cout << "9 IS NOT IN TREE!!!" << endl;
    }
    cout << "Empty tree size is " << emptyBst.size() << endl;
    cout << endl;

    BST<double> *doublePointerBst = new BST<double>();
    doublePointerBst->insert(1.1);
    doublePointerBst->insert(1.2);
    doublePointerBst->insert(6.6);
    doublePointerBst->insert(12.3);
    doublePointerBst->insert(10.2);
    doublePointerBst->insert(100.9);
    cout << "Double pointer tree inorder: " << doubleBst << endl;
    if (doublePointerBst->exists(6.6) == true) {
        cout << "6.6 IS IN TREE!!!" << endl;
    }
    if (doublePointerBst->exists(99.9) == false) {
        cout << "99.9 IS NOT IN TREE!!!" << endl;
    }
    cout << "Double pointer tree size is " << doublePointerBst->size() << endl;
    cout << endl;
}
