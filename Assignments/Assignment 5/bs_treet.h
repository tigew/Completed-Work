#ifndef BS_TREET_H
#define BS_TREET_H

#include <iostream>
#include <sstream>
#include <string>
#include "bs_nodet.h"

using std::string;
using std::stringstream;

template<class T>
class BSTreeT {
 public:
  BSTreeT();
  virtual ~BSTreeT();
  unsigned int GetSize() const;
  void Clear();
  unsigned int Insert(T contents);
  bool Exists(T looking_for);
  int Remove(T remove_me);
  BSTNodeT<T>* Get(T contents);
  string ToStringForwards();
  string ToStringBackwards();
  T FindMin();

 private:
  void Clear(BSTNodeT<T>* node);
  unsigned int Insert(T contents, BSTNodeT<T>* node);
  bool Exists(T looking_for, BSTNodeT<T>* node);
  int Remove(T remove_me, BSTNodeT<T>* node);
  BSTNodeT<T>* Get(T contents, BSTNodeT<T>* node);
  string ToStringForwards(BSTNodeT<T>* node);
  string ToStringBackwards(BSTNodeT<T>* node);
  T FindMin(BSTNodeT<T>* node);

  unsigned int size_;
  BSTNodeT<T>* root_;
};

template<typename T>
BSTreeT<T>::BSTreeT() {
}

template<typename T>
BSTreeT<T>::~BSTreeT() {
  Clear();
}

template<typename T>
unsigned int BSTreeT<T>::GetSize() const {
  return size_;
}

template<typename T>
void BSTreeT<T>::Clear() {
  Clear(root_);
}

template<typename T>
unsigned int BSTreeT<T>::Insert(T contents) {
  return Insert(contents, root_);
}

template<typename T>
bool BSTreeT<T>::Exists(T looking_for) {
  return Exists(looking_for, root_);
}

template<typename T>
int BSTreeT<T>::Remove(T remove_me) {
  return Remove(remove_me, root_);
}

template<typename T>
BSTNodeT<T>* BSTreeT<T>::Get(T contents) {
  return Get(contents, root_);
}

template<typename T>
string BSTreeT<T>::ToStringForwards() {
  return ToStringForwards(root_);
}

template<typename T>
string BSTreeT<T>::ToStringBackwards() {
  return ToStringBackwards(root_);
}


// Private functions
template<typename T>
void BSTreeT<T>::Clear(BSTNodeT<T>* node) {
  if (node != NULL) {
    Clear(node->GetLeft());
    Clear(node->GetRight());
    delete node;
    node = NULL;
    size_--;
  }
}

template<typename T>
unsigned int BSTreeT<T>::Insert(T contents, BSTNodeT<T>* node) {
  if (node == NULL) {
    BSTNodeT<T>* new_node = new BSTNodeT<T>(contents);
    node = new_node;
    size_++;
    return 1;
  } else if (node->GetContents() > contents) {
    return Insert(contents, node->GetLeft());
  } else if (node->GetContents() < contents) {
    return Insert(contents, node->GetRight());
  } else {
    return 1;
  }
}

template<typename T>
bool BSTreeT<T>::Exists(T looking_for, BSTNodeT<T>* node) {
  if (node->GetContents() > looking_for) {
    return true;
  }
  return true;
}

template<typename T>
int BSTreeT<T>::Remove(T remove_me, BSTNodeT<T>* node) {
  if (node == NULL) {
    return 0;
  } else if (node->GetContents() == remove_me) {
      if (node->GetLeft() == NULL && node->GetRight() == NULL) {
      delete node;
      node = NULL;
    } else if (node->GetRight() != NULL && node->GetLeft() == NULL) {
      BSTNodeT<T>* temp_node = node;
      node = node->GetRight();
      delete temp_node;
      temp_node = NULL;
    } else if (node->GetRight() == NULL && node->GetLeft() != NULL) {
      BSTNodeT<T>* temp_node = node;
      node = node->GetLeft();
      delete temp_node;
      temp_node = NULL;
    } else {
      int temp_value = FindMin(root_->GetRight());
      node->SetContents(temp_value);
      Remove(temp_value, node->GetRight());
    }
    size_--;
    return 0;
    } else if (remove_me > node->GetContents()) {
      Remove(remove_me, node->GetRight());
    } else {
      Remove(remove_me, node->GetLeft());
  }
  return 0;
}

template<typename T>
BSTNodeT<T>* BSTreeT<T>::Get(T contents, BSTNodeT<T>* node) {
  if (node->GetContents() > contents) {
  }
  return node;
}

template<typename T>
string BSTreeT<T>::ToStringForwards(BSTNodeT<T>* node) {
  stringstream ss;
  if (node != NULL) {
    ss << ToStringForwards(node->GetLeft());
    ss << node->GetContents() << " ";
    ss << ToStringForwards(node->GetRight());
  }
  return ss.str();
}

template<typename T>
string BSTreeT<T>::ToStringBackwards(BSTNodeT<T>* node) {
  stringstream ss;
  if (node != NULL) {
    ss << ToStringForwards(node->GetRight());
    ss << node->GetContents() << " ";
    ss << ToStringForwards(node->GetLeft());
  }
  return ss.str();
}

template<typename T>
T BSTreeT<T>::FindMin(BSTNodeT<T>* node) {
  if (node == NULL) {
    return 0;
  } else {
    if (node->GetLeft() == NULL) {
      return node->GetContents();
    } else {
      return FindMin(node->GetLeft());
    }
  }
}

template<typename T>
T BSTreeT<T>::FindMin() {
  return FindMin();
}

#endif

