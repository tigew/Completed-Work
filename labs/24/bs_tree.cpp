// Name: Travis Peebles
// bs_tree.cpp
#include "bs_tree.h"

BSTree::BSTree()
  : root_(NULL),
    size_(0) {
}

BSTree::~BSTree() {
  Clear(root_);
}

bool BSTree::Insert(int contents) {
  return Insert(contents, root_);
}

void BSTree::Clear() {
  Clear(root_);
}

unsigned int BSTree::GetSize() const {
  return size_;
}

string BSTree::InOrder() {
  return InOrder(root_);
}

bool BSTree::Insert(int contents, BSTNode*& node) {
  if (node == NULL) {
    BSTNode* new_node = new BSTNode(contents);
    node = new_node;
    size_++;
    return true;
  } else if (node->GetContents() > contents) {
    return Insert(contents, node->GetLeftChild());
  } else if (node->GetContents() < contents) {
    return Insert(contents, node->GetRightChild());
  } else {
    return false;
  }
}

void BSTree::Clear(BSTNode*& node) {
  if (node != NULL) {
    Clear(node->GetLeftChild());
    Clear(node->GetRightChild());
    delete node;
    node = NULL;
    size_--;
  }
}

string BSTree::InOrder(BSTNode* node){
  stringstream ss;
  if (node != NULL) {
    ss << InOrder(node->GetLeftChild());
    ss << node->GetContents() << " ";
    ss << InOrder(node->GetRightChild());
  }
  return ss.str();
}
