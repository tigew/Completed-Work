#ifndef BS_NODET_H
#define BS_NODET_H

#include <iostream>

template<typename T>
class BSTNodeT {
 public:
  BSTNodeT();
  BSTNodeT(T contents);
  virtual ~BSTNodeT();
  void SetContents(T contents);
  void SetLeft(BSTNodeT* left);
  void SetRight(BSTNodeT* right);
  void IncremenCount();
  void DecrementCount();
  T GetContents();
  BSTNodeT* GetLeft();
  BSTNodeT* GetRight();
 private:
  T contents_;
  unsigned int total_added_;
  BSTNodeT* left_;
  BSTNodeT* right_;
};

template<typename T>
BSTNodeT<T>::BSTNodeT()
  : contents_(T()),
    total_added_(0),
    left_(NULL),
    right_(NULL) {
}

template<typename T>
BSTNodeT<T>::BSTNodeT(T contents)
  : contents_(contents),
    total_added_(0),
    left_(NULL),
    right_(NULL) {
}

template<typename T>
BSTNodeT<T>::~BSTNodeT() {
  left_  = NULL;
  right_ = NULL;
}

template<typename T>
void BSTNodeT<T>::SetContents(T contents) {
  contents_ = contents;
}

template<typename T>
void BSTNodeT<T>::SetLeft(BSTNodeT* left) {
  left_ = left;
}

template<typename T>
void BSTNodeT<T>::SetRight(BSTNodeT* right) {
  right_ = right;
}

template<typename T>
void BSTNodeT<T>::IncremenCount() {
  total_added_++;
}

template<typename T>
void BSTNodeT<T>::DecrementCount() {
  total_added_--;
}

template<typename T>
T BSTNodeT<T>::GetContents() {
  return contents_;
}

template<typename T>
BSTNodeT<T>* BSTNodeT<T>::GetLeft() {
  return left_;
}

template<typename T>
BSTNodeT<T>* BSTNodeT<T>::GetRight() {
  return right_;
}

#endif

