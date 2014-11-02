#include "todo_item.h"

TodoItem::TodoItem(string description, int priority,
    bool completed)
    : description_(description),
      priority_(priority),
      completed_(completed) {
}

TodoItem::~TodoItem() {
}

void TodoItem::set_description(string description) {
  description_ = description;
}

void TodoItem::set_priority(int priority) {
  if (priority > 5 || priority <= 0) {
    priority_ = 5;
    return;
  }
  priority_ = priority;
}

void TodoItem::set_completed(bool completed) {
  completed_ = completed;
}

string TodoItem::description() const {
  return description_;
}

int TodoItem::priority() const {
  return priority_;
}

bool TodoItem::completed() const {
  return completed_;
}

string TodoItem::ToFile() {
  stringstream ss;

  ss << Scrub(description_) << "@" << priority_ << "@" << completed_;
  return ss.str();
}

ostream& operator <<(ostream &out, const TodoItem &item) {
  out << "Description: " << item.description() << endl;
  out << "Priority: "        << item.priority()       << endl;
  out << "Completed: "  << item.completed() << endl;
  return out;
}

string TodoItem::Scrub(string unmodified) {
  for (unsigned int i = 0; i < unmodified.length(); i++) {
    if (static_cast<char>(unmodified.at(i)) == '@') {
      unmodified.at(i) =  '#';
    }
  }
  return unmodified;
}
