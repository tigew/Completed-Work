/*
 * Name        : dl_list.cpp
 * Author      : Travis Peebles
 * Description : class DLList.
 *               Doubly Linked list content class
 */

#include "dl_list.h"

DLList::DLList()
  : head_(NULL),
    tail_(NULL),
    size_(0) {
}

DLList::~DLList() {
  Clear();
}

int DLList::GetSize() const {
  return size_;
}

void DLList::PushFront(int new_contents) {
  cout << new_contents << endl;
}

void DLList::PushBack(int new_contents) {
  cout << new_contents << endl;
}

int DLList::GetFront() const {
  return head_->GetContents();
}

int DLList::GetBack() const {
  return tail_->GetContents();
}

void DLList::PopFront() {
}

void DLList::PopBack() {
}

int DLList::RemoveFirst(int remove) {
  return remove;
}

int DLList::RemoveAll(int remove) {
  return remove;
}

bool DLList::Exists(int looking_for) {
}

void DLList::Clear() {
}

string DLList::ToStringForwards() {
  return "";
}

string DLList::ToStringBackwards() {
  return "";
}
