/*
 * Name        : bst_node.cpp
 * Author      : Travis Peebles
 * Description : Creating a Node for a Binary Search Tree
 */

#include "bst_node.h"

BSTNode::BSTNode()
  : left_child_(NULL),
    right_child_(NULL),
    contents_(0) {
}

BSTNode::BSTNode(int contents)
  : left_child_(NULL),
    right_child_(NULL),
    contents_(contents) {
}

BSTNode::~BSTNode() {
  left_child_  = NULL;
  right_child_ = NULL;
}

void BSTNode::SetContents(int contents) {
  contents_ = contents;
}

int BSTNode::GetContents() const {
  return contents_;
}

int& BSTNode::GetContents() {
  return contents_;
}

void BSTNode::SetLeftChild(BSTNode* new_child_left) {
  left_child_ = new_child_left;
}

void BSTNode::SetRightChild(BSTNode* new_child_right) {
  right_child_ = new_child_right;
}

BSTNode* BSTNode::GetLeftChild() const {
  return left_child_;
}

BSTNode*& BSTNode::GetLeftChild() {
  return left_child_;
}

BSTNode* BSTNode::GetRightChild() const {
  return right_child_;
}

BSTNode*& BSTNode::GetRightChild() {
  return right_child_;
}

