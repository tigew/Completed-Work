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
  void SetLeft(BSTNodeT<T>* left);
  void SetRight(BSTNodeT<T>* right);
  void IncremenCount();
  void DecrementCount();
  T GetContents();
  BSTNodeT<T>* GetLeft();
  BSTNodeT<T>* GetRight();
  BSTNodeT<T>* GetLeft() const;
  BSTNodeT<T>* GetRight() const;

 private:
  T contents_;
  unsigned int total_added_;
  BSTNodeT<T>* left_;
  BSTNodeT<T>* right_;
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
void BSTNodeT<T>::SetLeft(BSTNodeT<T>* left) {
  left_ = left;
}

template<typename T>
void BSTNodeT<T>::SetRight(BSTNodeT<T>* right) {
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

template<typename T>
BSTNodeT<T>* BSTNodeT<T>::GetLeft() const {
  return left_;
}

template<typename T>
BSTNodeT<T>* BSTNodeT<T>::GetRight() const {
  return right_;
}

#endif

