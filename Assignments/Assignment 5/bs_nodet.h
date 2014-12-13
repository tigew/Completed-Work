#ifndef BS_NODET_H
#define BS_NODET_H

#include <iostream>

template<class T>
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

template<class T>
BSTNodeT<T>::BSTNodeT()
  : contents_(T()),
    total_added_(0),
    left_(NULL),
    right_(NULL) {
}

template<class T>
BSTNodeT<T>::BSTNodeT(T contents)
  : contents_(contents),
    total_added_(0),
    left_(NULL),
    right_(NULL) {
}

template<class T>
BSTNodeT<T>::~BSTNodeT() {
  left_  = NULL;
  right_ = NULL;
}

template<class T>
void BSTNodeT<T>::SetContents(T contents) {
  contents_ = contents;
}

template<class T>
void BSTNodeT<T>::SetLeft(BSTNodeT* left) {
  left_ = left;
}

template<class T>
void BSTNodeT<T>::SetRight(BSTNodeT* right) {
  right_ = right;
}

template<class T>
void BSTNodeT<T>::IncremenCount() {
  total_added_++;
}

template<class T>
void BSTNodeT<T>::DecrementCount() {
  total_added_--;
}

template<class T>
T BSTNodeT<T>::GetContents() {
  return contents_;
}

template<class T>
BSTNodeT<T>* BSTNodeT<T>::GetLeft() {
  return left_;
}

template<class T>
BSTNodeT<T>* BSTNodeT<T>::GetRight() {
  return right_;
}

#endif

