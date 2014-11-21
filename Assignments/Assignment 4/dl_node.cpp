/*
 * Name        : dl_node.cpp
 * Author      : Travis Peebles
 * Description : class DLNode.
 *               Doubly Linked list content class
 */

#include "dl_node.h"

DLNode::DLNode()
  : next_node_(NULL),
    previous_node_(NULL),
    contents_(0) {

}

DLNode::~DLNode() {
}

void DLNode::SetContents(int contents) {
  contents_ = contents;
}

void DLNode::SetNext(DLNode* next) {
  next_node_ = next;
}

void DLNode::SetPrevious(DLNode* previous) {
  previous_node_ = previous;
}

int DLNode::GetContents() const {
  return contents_;
}

DLNode* DLNode::GetNext() const {
  return next_node_;
}

DLNode* DLNode::GetPrevious() const {
  return previous_node_;
}
