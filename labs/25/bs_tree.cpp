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

bool BSTree::Remove(int contents) {
  return Remove(contents, root_);
}

int BSTree::FindMin() {
  return FindMin(root_);
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

bool BSTree::Remove(int contents, BSTNode*& node) {
  if (node == NULL) {
    return false;
  } else if (node->GetContents() == contents) {
    if (node->GetLeftChild() == NULL && node->GetRightChild() == NULL) {
      delete node;
      node = NULL;
    } else if (node->GetRightChild() != NULL && node->GetLeftChild() == NULL) {
      BSTNode* temp_node = node;
      node = node->GetRightChild();
      delete temp_node;
      temp_node = NULL;
    } else if (node->GetRightChild() == NULL && node->GetLeftChild() != NULL) {
      BSTNode* temp_node = node;
      node = node->GetLeftChild();
      delete temp_node;
      temp_node = NULL;
    } else { // Has 2 Children, seg faulting right here.
      int temp_value = FindMin(root_->GetRightChild());
      node->SetContents(temp_value);
      return Remove(temp_value, node->GetLeftChild());
    }
    size_--;
    return true;
  } else if (contents > node->GetContents()) {
    return Remove(contents, node->GetRightChild());
  } else {
    return Remove(contents, node->GetLeftChild());
  }
}

BSTNode* BSTree::FindMinSub(BSTNode* node) {
  if (node->GetLeftChild() == NULL) {
    return node;
  } else {
    return FindMinSub(node->GetLeftChild());
  }
}

int BSTree::FindMin(BSTNode* node) {
  if (node == NULL) {
    return 0;
  } else {
    if (node->GetLeftChild() == NULL) {
      return node->GetContents();
    } else {
      return FindMin(node->GetLeftChild());
    }
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
