// Travis Peebles
#ifndef MAGIC_ITEM_H
#define MAGIC_ITEM_H

#include <iostream>
#include <string>
#include <sstream>
#include "item.h"

using std::string;
using std::stringstream;

class MagicItem : public Item {
 public:
    MagicItem(string name = "magicitem", unsigned int value = 0,
              string description = "no description",
              unsigned int mana_required = 0);
    virtual ~MagicItem();
    string description();
    unsigned int mana_required();
    void set_description(string description);
    void set_mana_required(unsigned int mana_required);
    // format -- NAME, $VALUE, DESCRIPTION, requires MANAREQUIRED mana
    string ToString();
 private:
    string description_;
    unsigned int mana_required_;
};

#endif  // MAGIC_ITEM_H
