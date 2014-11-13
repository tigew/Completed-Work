/*
 * Name        : sl_list.cpp
 * Author      : Travis Peebles
 * Description : class SLList.
 *               Linked list content class implementation
 */

#include "sl_list.h"

SLList::SLList()
  : head_(NULL),
    tail_(NULL),
    size_(0) {
}

SLList::~SLList() {
  Clear();
}

void SLList::InsertHead(int new_contents) {
  SLNode* node = new SLNode(new_contents);

  if (head_ == NULL) {
    head_ = tail_ = node;
  } else {
    node->set_next_node(head_);
    head_ = node;
  }
  size_++;
}

void SLList::InsertTail(int new_contents) {
  SLNode* node = new SLNode(new_contents);

  if (tail_ == NULL) {
    head_ = tail_ = node;
  } else {
    tail_->set_next_node(node);
    tail_ = node;
  }
  size_++;
}

void SLList::RemoveHead() {
  if (head_ == NULL) {
    return;
  } else {
    SLNode* temp = head_;
    head_ = temp->next_node();
    delete temp;
    size_--;
    if (size_ == 0) {
      head_ = NULL;
      tail_ = NULL;
    }
  }
}

void SLList::RemoveTail() {
  if (tail_ != NULL && head_ != tail_) {
    SLNode* iter = head_;
    for (; iter->next_node() != tail_; iter = iter->next_node()) {}
    delete tail_;
    tail_ = iter;
    tail_->set_next_node(NULL);
    size_--;
  } else if (tail_ == head_) {
    delete tail_;
    head_ = tail_ = NULL;
    size_ = 0;
  }
}

int SLList::GetHead() const {
  if (head_ != NULL) {
    return head_->contents();
  } else {
    return 0;
  }
}

int SLList::GetTail() const {
  if (tail_ != NULL) {
    return tail_->contents();
  } else {
    return 0;
  }
}

void SLList::Clear() {
  if (head_ == NULL && tail_ == NULL) {
    return;
  } else {
    while (head_ != NULL) {
      SLNode* iterator = head_->next_node();
      delete head_;
      head_ = iterator;
    }
  }
  size_ = 0;
}

unsigned int SLList::size() const {
  return size_;
}

string SLList::ToString() const {
  stringstream ss;
  if (head_ == NULL && tail_ == NULL) {
    return "";
  } else {
    SLNode* tempHead = head_;
    while (tempHead != NULL) {
      if (tempHead->next_node() == NULL) {
        ss << tempHead->contents();
      } else {
        ss << tempHead->contents() << ", ";
      }
      tempHead = tempHead->next_node();
    }
  }
  return ss.str();
}
