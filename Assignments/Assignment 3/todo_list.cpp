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
  if (list_size_ == list_capacity_ - 1) {
    cout << "IncreaseCapacity";
    IncreaseCapacity();
  }

  for (unsigned int i = 0; i < list_capacity_; i++) {
    if (todo_item_[i] == NULL) {
      todo_item_[i] = item;
      break;
    }
  }
  cout << "List size before: " << list_size_ << "\n";
  list_size_++;
  cout << "List size before: " << list_size_ << "\n";
}

void TodoList::DeleteItem(int location) {
  if ((location - 1) < 0) {
    return;
  }

  unsigned int null_count = 0;

  delete todo_item_[location - 1];
  todo_item_[location - 1] = NULL;

  for (unsigned int i = 0; i < list_capacity_ - 1; i++) {
    if (todo_item_[i] == NULL) {
      todo_item_[i] = todo_item_[i + 1];
      todo_item_[i + 1] = NULL;
    }
  }
  cout << "List size before: " << list_size_ << "\n";
  list_size_--;
  cout << "List size before: " << list_size_ << "\n";

  for (unsigned int i = 0; i < list_capacity_; i++) {
    if (todo_item_[i] == NULL) {
      null_count++;
      if (null_count <= 11) {
        DecreaseCapacity();
        break;
      }
    }
  }
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
  for (int i = 0; i < list.GetSize(); i++) {
    out << i << ". " << list.GetItem(i) << endl;
  }
  return out << endl;
}

void TodoList::IncreaseCapacity() {
  TodoItem **temp_items = new TodoItem*[list_capacity_ + 10];

  for (unsigned int i = 0; i < list_capacity_; i++) {
    temp_items[i] = todo_item_[i];
  }

  for (unsigned int i = 0; i < list_capacity_; i++) {
    delete todo_item_[i];
    todo_item_[i] = NULL;
  }
  delete[] todo_item_;

  // todo_item_ = new TodoItem*[list_capacity_ + 10];
  todo_item_ = temp_items;

  /*
  for (int i = 0; list_capacity_ + 10; i++) {
    todo_item_[i] = NULL;
  }

  for (unsigned int i = 0; i < list_capacity_; i++) {
    todo_item_[i] = temp_items[i];
  }*/

  for (unsigned int i = 0; i < list_capacity_; i++) {
    delete temp_items[i];
    temp_items[i] = NULL;
  }
  delete[] temp_items;

  list_capacity_ += 10;
}

void TodoList::DecreaseCapacity() {
  TodoItem **temp_items = new TodoItem*[list_capacity_ - 10];

  for (unsigned int i = 0; i < list_size_; i++) {
    temp_items[i] = todo_item_[i];
  }

  for (unsigned int i = 0; i < list_capacity_; i++) {
    delete todo_item_[i];
    todo_item_[i] = NULL;
  }
  delete[] todo_item_;

  // todo_item_ = new TodoItem*[list_capacity_ - 10];
  todo_item_ = temp_items;

/*
  for (int i = 0; list_capacity_ - 10; i++) {
    todo_item_[i] = NULL;
  }

  for (unsigned int i = 0; i < list_capacity_; i++) {
    todo_item_[i] = temp_items[i];
  } */

  for (unsigned int i = 0; i < list_capacity_; i++) {
    delete temp_items[i];
    temp_items[i] = NULL;
  }
  delete[] temp_items;

  list_capacity_ -= 10;
}
