#include "todo_item.h"

TodoItem::TodoItem(string description, int priority,
    bool completed)
    : description_(description),
      priority_(priority),
      completed_(completed) {
}

TodoItem::~TodoItem() {
}

string TodoItem::SetDescription(string description) {
}

void TodoItem::SetDescription(string description) {
}

void TodoItem::SetPriority(int priority) {
}

void TodoItem::SetCompleted(bool completed) {
}

string TodoItem::GetDescription() const {
}

int TodoItem::GetPriority() const {
}

bool TodoItem::GetCompleted() const {
}

string TodoItem::ToFile() {
}

ostream& operator <<(ostream &out, const TodoItem &item) {
}

string Scrub(string unmodified) {
}
