// Name: Travis Peebles
// bs_tree.h
#ifndef BS_TREE_H
#define BS_TREE_H

#include <iostream>
#include <string>
#include <sstream>
#include "bst_node.h"

using std::string;
using std::stringstream;

class BSTree {
 public:
    BSTree();
    ~BSTree();
    bool Insert(int contents);
    bool Remove(int contents);
    int FindMin();
    void Clear();
    unsigned int GetSize() const;
    string InOrder();

 private:
    BSTNode* root_;
    unsigned int size_;
    bool Insert(int contents, BSTNode*& node);
    bool Remove(int contents, BSTNode*& node);
    BSTNode* FindMinSub(BSTNode* node);
    int FindMin(BSTNode* node);
    void Clear(BSTNode*& node);
    string InOrder(BSTNode* node);
};

#endif
