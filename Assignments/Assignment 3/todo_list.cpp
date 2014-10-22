#include "todo_list.h"
#include "todo_item.h"

TodoList::TodoList()
  : todo_item_(new TodoItem*[25]),
    list_capacity_(25) {
}

TodoList::~TodoList() {
  for (unsigned int i = 0; i < list_capacity_; i++) {
    delete todo_item_[i];
    todo_item_[i] = NULL;
  }
  delete[] todo_item_;
}

void TodoList::AddItem(TodoItem *item) {
  if (GetSize() == GetCapacity() - 1) {
    IncreaseCapacity();
  }

  for (int i = 0; i < GetCapacity(); ++i) {
    if (todo_item_[i] == NULL) {
      todo_item_[i] = item;
    }
  }
  list_size_++;
}

void TodoList::DeleteItem(int location) {
  if (location - 1 < 0) {
    return;
  }

  delete todo_item_[location - 1];
  todo_item_[location - 1] = NULL;

  for (unsigned int i = 0; i < list_capacity_; i++) {
    if (todo_item_[i] == NULL) {
      todo_item_[i] = todo_item_[i + 1];
      todo_item_[i + 1] = NULL;
    }
  }
  list_size_--;
}

TodoItem* TodoList::GetItem(int location) {
  TodoItem *item;
  item = todo_item_[location - 1];
  return item;
}

int TodoList::GetSize() {
  return list_size_;
}

int TodoList::GetCapacity() {
  return list_capacity_;
}

void TodoList::Sort() {
}

string ToFile() {
  return "test";
}

ostream& operator <<(ostream &out, const TodoList &list) {
  return out << list;
}

void TodoList::IncreaseCapacity() {
  // TodoItem **todo_item_ = new TodoItem*[25]
  TodoItem **temp_items = new TodoItem*[list_capacity_ + 10];

  for (unsigned int i = 0; i < list_capacity_; i++) {
    temp_items[i] = todo_item_[i];
  }

  for (unsigned int i = 0; i < list_capacity_; i++) {
    delete todo_item_[i];
    todo_item_[i] = NULL;
  }
  delete[] todo_item_;

  todo_item_ = new TodoItem*[list_capacity_ + 10];

  for (unsigned int i = 0; i < list_capacity_; i++) {
    todo_item_[i] = temp_items[i];
  }

  for (unsigned int i = 0; i < list_capacity_; i++) {
    delete temp_items[i];
    temp_items[i] = NULL;
  }
  delete[] temp_items;

  list_capacity_ += 10;
}

void TodoList::DecreaseCapacity() {
}
