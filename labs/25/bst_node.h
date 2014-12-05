/*
 * Name        : bst_node.h
 * Author      : Travis Peebles
 * Description : Creating a Node for a Binary Search Tree
 */

#ifndef BST_NODE_H
#define BST_NODE_H

#include <iostream>

class BSTNode {
 public:
    BSTNode();
    BSTNode(int contents);
    ~BSTNode();
    void SetContents(int contents);
    int GetContents() const;
    int& GetContents();
    void SetLeftChild(BSTNode* new_child_left);
    void SetRightChild(BSTNode* new_child_right);
    BSTNode* GetLeftChild() const;
    BSTNode*& GetLeftChild();
    BSTNode* GetRightChild() const;
    BSTNode*& GetRightChild();
 private:
    BSTNode* left_child_;
    BSTNode* right_child_;
    int contents_;
};

#endif
