/*
 * Name        : sl_list.h
 * Author      : Travis Peebles
 * Description : class SLList.
 *               Linked list content class
 */

#ifndef SLLIST_H
#define SLLIST_H

#include "sl_node.h"


#include <sstream>
#include <string>

using std::string;
using std::stringstream;

class SLList {
 public:
  SLList();
  ~SLList();
  void InsertHead(int new_contents);
  void InsertTail(int new_contents);
  void RemoveHead();
  void RemoveTail();
  int GetHead() const;
  int GetTail() const;
  void Clear();
  unsigned int size() const;
  string ToString() const;

 private:
  SLNode* head_;
  SLNode* tail_;
  unsigned int size_;
};

#endif  // SLLIST_H
