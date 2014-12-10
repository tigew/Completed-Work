// Travis Peebles
#include "magic_item.h"

MagicItem::MagicItem(string name, unsigned int value, string description,
                     unsigned int mana_required)
  : Item(name, value),
    description_(description),
    mana_required_(mana_required) {
}

MagicItem::~MagicItem() {
}

string MagicItem::description() {
  return description_;
}

unsigned int MagicItem::mana_required() {
  return mana_required_;
}

void MagicItem::set_description(string description) {
  description_ = description;
}

void MagicItem::set_mana_required(unsigned int mana_required) {
  mana_required_ = mana_required;
}

// format -- NAME, $VALUE, DESCRIPTION, requires MANAREQUIRED mana
string MagicItem::ToString() {
  stringstream ss;
  ss << name() << ", $" << value() << ", " << description_
     << ", requires " << mana_required_ << " mana";
  return ss.str();
}
