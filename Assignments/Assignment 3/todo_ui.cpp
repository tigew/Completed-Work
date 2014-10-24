#include "todo_ui.h"

TodoUI::TodoUI()
  : todo_list_(new TodoList()) {
}

TodoUI::~TodoUI() {
  delete todo_list_;
}

void TodoUI::menu() {
  bool running = true;
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
      break;

      case 3:
      break;

      case 4:
      break;

      case 5:
      break;

      case 6:
      break;

      case 7:
        running = false;
      break;
    }
    // ClearScreen();
  }
}
