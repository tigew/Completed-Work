#include "todo_item.h"

TodoItem::TodoItem(string description, int priority,
    bool completed)
    : description_(description),
      priority_(priority),
      completed_(completed) {
}

TodoItem::~TodoItem() {
}

void TodoItem::SetDescription(string description){
  std::cout << description;
}

void TodoItem::SetPriority(int priority) {
  std::cout << priority;
}

void TodoItem::SetCompleted(bool completed) {
  std::cout << completed;
}

string TodoItem::GetDescription() const {
  return "test";
}

int TodoItem::GetPriority() const {
  return 0;
}

bool TodoItem::GetCompleted() const {
  return false;
}

string TodoItem::ToFile() {
  return "test";
}

ostream& operator <<(ostream &out, const TodoItem &item) {
return out << item;
}

string Scrub(string unmodified) {
  std::cout << unmodified;
  return unmodified;
}
