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
  void RemoveHead();
  void Clear();
  unsigned int size() const;
  string ToString() const;

 private:
  SLNode* head_;
  unsigned int size_;
};

#endif  // SLLIST_H
