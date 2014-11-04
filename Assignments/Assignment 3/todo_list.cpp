#include "todo_list.h"
#include "todo_item.h"

TodoList::TodoList()
  : todo_item_(new TodoItem*[25]),
    list_size_(0),
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
  if (list_size_ == list_capacity_) {
    cout << "IncreaseCapacity\n";
    IncreaseCapacity();
  }

  todo_item_[list_size_] = item;

  list_size_++;
}

void TodoList::DeleteItem(int location) {
  if ((location - 1) < 0) {
    return;
  }

  delete todo_item_[location - 1];

  todo_item_[list_size_ - 1] = NULL;

  DecreaseCapacity(location);

  list_size_--;
}

TodoItem* TodoList::GetItem(int location) const {
  return todo_item_[location - 1];
}

int TodoList::GetSize() const {
  return list_size_;
}

int TodoList::GetCapacity() {
  return list_capacity_;
}

void TodoList::Sort() {
  for (unsigned int i = 0; i <= (list_capacity_ - 1); i++) {
    unsigned int j = i;

    while ((j > 0) && (todo_item_[j]->priority() <
                       todo_item_[j - 1]->priority())) {
        SwapValues(todo_item_[j], todo_item_[j - 1]);
        j = j - 1;
    }
  }
}

string TodoList::ToFile() {
  string printed_list;
  for (unsigned int i = 0; i < list_size_; i++) {
    printed_list += todo_item_[i]->ToFile() + "\n";
  }
  return printed_list;
}

ostream& operator <<(ostream &out, const TodoList &list) {
  for (unsigned int i = 1; i < list.list_size_; i++) {
    out << i << ". " << list.GetItem(i - 1) << endl;
  }
  return out << endl;
}

void TodoList::IncreaseCapacity() {
  TodoItem **temp_items = new TodoItem*[list_capacity_ + 10];

  for (unsigned int i = 0; i < list_size_; i++) {
    temp_items[i] = todo_item_[i];
  }

  for (unsigned int i = 0; i < list_size_; i++) {
    delete todo_item_[i];
    todo_item_[i] = NULL;
  }
  delete[] todo_item_;

  todo_item_ = temp_items;

  for (unsigned int i = list_size_; i < list_capacity_ + 10; i++) {
    todo_item_[i] = NULL;
  }

  list_capacity_ += 10;
}

void TodoList::DecreaseCapacity(int location) {
  for (unsigned int i = location - 1; i < list_size_ - 1; i++) {
    todo_item_[i] = todo_item_[i + 1];
  }
}
