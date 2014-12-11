#ifndef BS_TREET_H
#define BS_TREET_H

#include <iostream>
#include <sstream>
#include <string>
#include "bs_nodet.h"

using std::string;
using std::stringstream;

template<typename T>
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
 private:
  void Clear(BSTNodeT<T>* node);
  unsigned int Insert(T contents, BSTNodeT<T>* node);
  bool Exists(T looking_for, BSTNodeT<T>* node);
  int Remove(T remove_me, BSTNodeT<T>* node);
  BSTNodeT<T>* Get(T contents, BSTNodeT<T> node);
  string ToStringForwards(BSTNodeT<T>* node);
  string ToStringBackwards(BSTNodeT<T>* node);

  unsigned int size_;
  BSTNodeT<T> root_;
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


//private functions
template<typename T>
void BSTreeT<T>::Clear(BSTNodeT<T>* node) {
}

template<typename T>
unsigned int BSTreeT<T>::Insert(T contents, BSTNodeT<T>* node) {
}

template<typename T>
bool BSTreeT<T>::Exists(T looking_for, BSTNodeT<T>* node) {
}

template<typename T>
int BSTreeT<T>::Remove(T remove_me, BSTNodeT<T>* node) {
}

template<typename T>
BSTNodeT<T>* BSTreeT<T>::Get(T contents, BSTNodeT<T> node) {
}

template<typename T>
string BSTreeT<T>::ToStringForwards(BSTNodeT<T>* node) {
}

template<typename T>
string BSTreeT<T>::ToStringBackwards(BSTNodeT<T>* node) {
}

#endif

