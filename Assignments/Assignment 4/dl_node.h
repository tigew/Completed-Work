/*
 * Name        : dl_node.h
 * Author      : Travis Peebles
 * Description : class DLNode.
 *               Doubly Linked list content class
 */

#ifndef DL_NODE_H
#define DL_NODE_H

#include <iostream>

class DLNode {
 public:
   DLNode();
   ~DLNode();
   void SetContents(int contents);
   void SetNext(DLNode* next);
   void SetPrevious(DLNode* previous);
   int GetContents() const;
   DLNode* GetNext() const;
   DLNode* GetPrevious() const;
 private:
  DLNode* next_node_;
  DLNode* previous_node_;
  int contents_;
};

#endif //  DL_NODE_H
