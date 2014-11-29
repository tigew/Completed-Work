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
	if (head_ == NULL) {
		head_ = tail_ = node;
	} else {
		node->SetNext(head_);
		head_ = node;
		tail_->SetNext(head_);
	}
	size_++;
}

void DLList::PushBack(int new_contents) {
	DLNode* node = new DLNode();
	node->SetContents(new_contents);
	if (tail_ == NULL) {
		head_ = tail_ = node;
	}
	else {
		node->SetNext(node);
		tail_ = node;
		tail_->SetNext(head_);
	}
	size_++;
}

int DLList::GetFront() const {
	if (head_ != NULL) {
		head_->GetContents();
	} else {
		return 0;
	}
}

int DLList::GetBack() const {
	if (tail_ != NULL) {
		tail_->GetContents();
	}
	else {
		return 0;
	};
}

void DLList::PopFront() {
	if (head_ == NULL) {
		return;
	}
	else {
		DLNode* temp = head_;
		head_ = temp->GetNext();
		delete temp;
		size_--;
		if (size_ == 0) {
			head_ = NULL;
			tail_ = NULL;
		}
	}
}

void DLList::PopBack() {
	if (tail_ != NULL && head_ != tail_) {
		DLNode* iter = head_;
		for (; iter->GetNext() != tail_; iter = iter->GetNext()) {}
		delete tail_;
		tail_ = iter;
		tail_->SetNext(NULL);
		size_--;
	}
	else if (tail_ == head_) {
		delete tail_;
		head_ = tail_ = NULL;
		size_ = 0;
	}
}

int DLList::RemoveFirst(int remove) {
	return remove;
}

int DLList::RemoveAll(int remove) {
	return remove;
}

bool DLList::Exists(int looking_for) {
	return true;
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
			size_--;
			delete head_;
			head_ = iterator;
		}
	}
	//size_ = 0;
}

string DLList::ToStringForwards() {
	return "";
}

string DLList::ToStringBackwards() {
	return "";
}
