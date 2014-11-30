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
	DLNode* node = new DLNode();
	node->SetContents(new_contents);
	if (head_ == NULL)
	{
		head_ = tail_ = node;
		head_->SetNext(tail_);
		head_->SetPrevious(tail_);
		tail_->SetNext(head_);
		tail_->SetPrevious(head_);
	}
	else {
		node->SetNext(head_);
		head_->SetPrevious(node);
		node->SetPrevious(tail_);
		head_ = node;
		tail_->SetNext(head_);
	}
	size_++;
}

void DLList::PushBack(int new_contents) {
	DLNode* node = new DLNode();
	node->SetContents(new_contents);
	if (head_ == NULL)
	{
		head_ = tail_ = node;
		head_->SetNext(tail_);
		head_->SetPrevious(tail_);
		tail_->SetNext(head_);
		tail_->SetPrevious(head_);
	}
	else {
		node->SetNext(head_);
		node->SetPrevious(tail_);
		tail_->SetNext(node);
		tail_ = node;
		head_->SetPrevious(tail_);
	}
	size_++;
}

int DLList::GetFront() const {
	if (head_ != NULL) {
		return head_->GetContents();
	}
	else {
		cerr << "List Empty";
		return 0;
	}
}

int DLList::GetBack() const {
	if (tail_ != NULL) {
		return tail_->GetContents();
	}
	else {
		cerr << "List Empty";
		return 0;
	}
}

void DLList::PopFront() {
	if (head_ == NULL) {
    cerr << "List Empty";
		return;
	}
	else {
		DLNode* temp = head_;
		head_ = temp->GetNext();
		head_->SetPrevious(tail_);
		delete temp;
		temp = NULL;
		size_--;
		if (size_ == 0) {
			cerr << "List Empty";
			head_ = NULL;
			tail_ = NULL;
		}
	}
}

void DLList::PopBack() {
	if (size_ == 0) {
		cerr << "List Empty";
		return;
	}
	if (tail_ != NULL && head_ != tail_) {
		DLNode* node = tail_->GetPrevious();
		tail_->GetPrevious()->SetNext(head_);
		delete tail_;
		tail_ = node;
		size_--;
	}
	else if (tail_ == head_) {
		delete tail_;
		head_ = tail_ = NULL;
		size_ = 0;
	}
}

void DLList::RemoveFirst(int remove) {
  bool found_number = false;
	if (head_ != NULL) {
		DLNode* iter = head_;
		for (unsigned int i = 0; i < size_; i++) {
			if (iter->GetContents() == remove) {
        found_number = true;
				if (remove == head_->GetContents()) {
					PopFront();
					break;
				}
				else if (remove == tail_->GetContents()) {
					PopBack();
					break;
				}
				else {
					iter->GetPrevious()->SetNext(iter->GetNext());
					iter->GetNext()->SetPrevious(iter->GetPrevious());
					delete iter;
					iter = NULL;
					break;
				}
				iter = iter->GetNext();
			}
		}
	}
	else {
		cerr << "Not Found";
		return;
	}
  if (found_number == true) {
    cerr << "Not Found";
  }
}

void DLList::RemoveAll(int remove) {
  bool found_number = false;
	if (head_ != NULL) {
		DLNode* iter = head_;
		for (unsigned int i = 0; i < size_; i++) {
			if (iter->GetContents() == remove) {
        found_number = true;
				if (remove == head_->GetContents()) {
					PopFront();
				}
				else if (remove == tail_->GetContents()) {
					PopBack();
				}
				else {
					iter->GetPrevious()->SetNext(iter->GetNext());
					iter->GetNext()->SetPrevious(iter->GetPrevious());
					delete iter;
					iter = NULL;
				}
				iter = iter->GetNext();
			}
		}
	}
	else {
		cerr << "Not Found";
		return;
	}
  if (found_number == true) {
    cerr << "Not Found";
  }
}

bool DLList::Exists(int looking_for) {
	bool return_bool = false;
	if (head_ != NULL) {
		DLNode* iter = head_;
		for (unsigned int i = 0; i < size_; i++) {
			if (iter->GetContents() == looking_for) {
				return_bool = true;
				break;
			}
			iter = iter->GetNext();
		}
	}
	return return_bool;
}

void DLList::Clear() {
	if (head_ == NULL && tail_ == NULL) {
		return;
	}
	else {
		while (head_ != NULL) {
			if (tail_ == head_) {
				tail_ = NULL;
			}
			DLNode* iterator = head_->GetNext();
			delete head_;
			head_ = iterator;
		}
	}
	size_ = 0;
}

string DLList::ToStringForwards() {
	stringstream ss;
	if (size_ == 0) {
    cerr << "List Empty";
		ss << "";
	}
	else {
		DLNode* node = head_;
		for (unsigned int i = 0; i < size_; i++) {
			if (node == tail_) {
				ss << node->GetContents();
				break;
			}
			ss << node->GetContents() << ", ";
			node = node->GetNext();
		}
	}
	return ss.str();
}

string DLList::ToStringBackwards() {
	stringstream ss;
	if (size_ == 0) {
    cerr << "List Empty";
		ss << "";
	}
	else {
		DLNode* node = tail_;
		for (unsigned int i = 0; i < size_; i++) {
			if (node == head_) {
				ss << node->GetContents();
				break;
			}
			ss << node->GetContents() << ", ";
			node = node->GetPrevious();
		}
	}
	return ss.str();
}
