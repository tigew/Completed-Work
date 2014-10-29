#include "todo_item.h"

TodoItem::TodoItem(string description, int priority,
    bool completed)
    : description_(description),
      priority_(priority),
      completed_(completed) {
}

TodoItem::~TodoItem() {
}

void TodoItem::SetDescription(string description) {
  description_ = description;
}

void TodoItem::SetPriority(int priority) {
  priority_ = priority;
}

void TodoItem::SetCompleted(bool completed) {
  completed_ = completed;
}

string TodoItem::GetDescription() const {
  return description_;
}

int TodoItem::GetPriority() const {
  return priority_;
}

bool TodoItem::GetCompleted() const {
  return completed_;
}

string TodoItem::ToFile() {
  string return_string = "";
  return return_string;
}

ostream& operator <<(ostream &out, const TodoItem &item) {
  return out << item;
}

string Scrub(string unmodified) {
  std::cout << unmodified;
  return unmodified;
}
