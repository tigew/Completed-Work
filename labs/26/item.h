// Travis Peebles
#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

class Item {
 public:
    Item(string name = "item", unsigned int value = 0);
    virtual ~Item();
    string name();
    unsigned int value();
    void set_name(string name);
    void set_value(unsigned int value);
    // Format NAME, $VALUE
    string ToString();
 private:
    string name_;
    unsigned int value_;
};

#endif  // ITEM_H
