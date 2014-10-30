#include "sl_list.h"

SLList::SLList()
  : head_(NULL),
    size_(0) {
}

SLList::~SLList() {
  Clear();
}

void SLList::InsertHead(int new_contents) {
  SLNode* node = new SLNode(new_contents);

  if (head_ == NULL) {
    head_ = node;
  } else {
    node->set_next_node(head_);
    head_ = node;
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
  }
}

void SLList::Clear() {
  if (head_ == NULL) {
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
  if (head_ == NULL) {
    return "";
  } else {
    SLNode* tempContents = head_;
    while (tempContents != NULL) {
      if (tempContents->next_node() == NULL) {
        ss << tempContents->contents();
      } else {
        ss << tempContents->contents() << ", ";
      }
      tempContents = tempContents->next_node();
    }
  }
  return ss.str();
}
