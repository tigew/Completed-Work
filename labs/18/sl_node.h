/*
 * Name        : sl_node.h
 * Author      : Travis Peebles
 * Description : Unit Test for class SLNode.
 *               node header file
 */

#ifndef SL_NODE_H
#define SL_NODE_H

#include <iostream>

class SLNode {
 public:
  SLNode();
  SLNode(int contents);
  ~SLNode();
  void set_contents(int contents);
  int contents() const;
  void set_next_node(SLNode* node);
  SLNode* next_node() const;

 private:
  SLNode* next_node_;
  int contents_;
};

#endif  // SL_NODE_H
