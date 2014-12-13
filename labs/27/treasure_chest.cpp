#include "treasure_chest.h"

void TreasureChest::AddItem(const Item& item_to_add) {
  chest_.push_back(item_to_add);
}

void TreasureChest::InsertItem(const Item& item_to_add, unsigned int position) {
  if (chest_.size() < position || chest_.empty()) {
    chest_.push_back(item_to_add);
  } else {
    chest_.insert(chest_.begin() + position, item_to_add);
  }
}

const Item* TreasureChest::GetItem(unsigned int position) {
  if (chest_.size() <= position || chest_.empty()) {
    return NULL;
  } else {
    return &chest_.at(position);
  }
}

Item TreasureChest::RemoveItem(unsigned int position) {
  if (chest_.size() <= position || chest_.empty()) {
    throw string("ERROR: Remove at invalid position");
  } else {
    Item copy = chest_.at(position);
    chest_.erase(chest_.begin() + position);
    return copy;
  }
}

void TreasureChest::Clear() {
  chest_.clear();
}

bool TreasureChest::Empty() const {
  return chest_.empty();
}

unsigned int TreasureChest::GetSize() const {
  return chest_.size();
}

void TreasureChest::SortByName() {
  sort(chest_.begin(), chest_.end(), CompareItemsByName);
}

void TreasureChest::SortByValue() {
  sort(chest_.begin(), chest_.end(), CompareItemsByValue);
}

void TreasureChest::SortByQuantity() {
  sort(chest_.begin(), chest_.end(), CompareItemsByQuantity);
}

ostream& operator<<(ostream& outs, const TreasureChest& src) {
  if (src.chest_.empty()) {
    return outs << "Chest Empty!";
  }
  for (vector<Item>::const_iterator it = src.chest_.begin();
       it != src.chest_.end(); it++) {
    if (it == src.chest_.end () - 1) {
      outs << *it;
    } else {
      outs << *it << ", ";
    }
  }
  return outs;
}

string TreasureChest::ToString() {
  stringstream ss;
  ss << *this;
  return ss.str();
}

bool CompareItemsByName(const Item& lsrc, const Item& rsrc) {
  return lsrc.name_ < rsrc.name_;
}

bool CompareItemsByValue(const Item& lsrc, const Item& rsrc) {
  return lsrc.value_ < rsrc.value_;
}

bool CompareItemsByQuantity(const Item& lsrc, const Item& rsrc) {
  return lsrc.quantity_ < rsrc.quantity_;
}
