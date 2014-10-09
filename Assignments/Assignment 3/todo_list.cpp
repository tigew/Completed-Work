#include "todo_list.h"
#include "todo_item.h"

TodoList::TodoList() {
}

TodoList::~TodoList() {
}

void TodoList::AddItem(TodoItem *item) {
  std::cout << item;
}

void TodoList::DeleteItem(int location) {
  std::cout << location;
}

TodoItem* TodoList::GetItem() {
  TodoItem *item;
  item = new TodoItem("test");
  return item;
}

int TodoList::GetSize() {
  return 0;
}

int TodoList::GetCapacity() {
  return 0;
}

void TodoList::Sort() {
}

string ToFile() {
  return "test";
}

ostream& operator <<(ostream &out, const TodoList &list) {
  return out << list;
}

void IncreaseCapacity() {
}

void DecreaseCapacity() {
}
