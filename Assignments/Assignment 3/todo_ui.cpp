#include "todo_ui.h"

TodoUI::TodoUI()
  : todo_list_(new TodoList()) {
}

TodoUI::~TodoUI() {
  delete todo_list_;
}

void TodoUI::menu() {
  bool running = true;
  bool are_you_sure = false;
  int choice = 0;
  string description;
  int priority;
  bool completed;

    while (running) {
    cout << "(1) Create New Item\n"
         << "(2) Edit an Item\n"
         << "(3) Delete an Item\n"
         << "(4) View All Items\n"
         << "(5) View Specific Item\n"
         << "(6) Delete All Items\n"
         << "(7) Quit Program\n";

    choice = sc.readInt(1, 7);

    switch (choice) {
      case 1:
        TodoItem *item;

        cout << "Enter Description" << endl;
        description = sc.readString();

        cout << "Enter priority (1 - 5)" << endl;
        priority    = sc.readInt(1, 5);

        cout << "Is is completed?" << endl;
        completed   = sc.readBool();

        item = new TodoItem(description, priority, completed);

        todo_list_->AddItem(item);
      break;

      case 2:
        if (todo_list_->GetSize() <= 0) {
          cout << todo_list_->GetSize() << endl;
          cout << "No items to edit." << endl;
          break;
        }
        cout << "Enter what item 1 - " << todo_list_->GetSize()
             << " that you would like to edit." << endl;
        choice = sc.readInt(1, todo_list_->GetSize());

        cout << "Enter Description" << endl;
        description = sc.readString();

        cout << "Enter priority (1 - 5)" << endl;
        priority    = sc.readInt(1, 5);

        cout << "Is is completed?" << endl;
        completed   = sc.readBool();

        todo_list_->GetItem(choice)->SetDescription(description);
        todo_list_->GetItem(choice)->SetPriority(priority);
        todo_list_->GetItem(choice)->SetCompleted(completed);
      break;

      case 3:
        if (todo_list_->GetSize() <= 0) {
          cout << todo_list_->GetSize() << endl;
          cout << "No items to delete." << endl;
          break;
        }
        cout << "Enter what item 1 - " << todo_list_->GetSize()
             << " that you would like to delete." << endl;
        choice = sc.readInt(1, todo_list_->GetSize());
        todo_list_->DeleteItem(choice);
      break;

      case 4:
        if (todo_list_->GetSize() <= 0) {
          cout << "No items to view." << endl;
          break;
        }
        for (int i = 0; i < todo_list_->GetSize(); i++) {
          cout << todo_list_->GetItem(i);
        }
      break;

      case 5:
        if (todo_list_->GetSize() <= 0) {
          cout << "No items to view." << endl;
          break;
        }
        cout << "Enter what item 1 - " << todo_list_->GetSize()
             << " that you would like to view." << endl;
        choice = sc.readInt(1, todo_list_->GetSize());
        cout << todo_list_->GetItem(choice);
      break;

      case 6:
        cout << "Are you sure you want to delete everything?";
        are_you_sure = sc.readBool();
        if (!are_you_sure) {
          break;
        }
        for (int i = 0; i < todo_list_->GetSize(); i++) {
          todo_list_->DeleteItem(i);
        }
      break;

      case 7:
        running = false;
      break;
    }
    ClearScreen();
  }
}
