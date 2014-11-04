#ifndef TODO_UI_H
#define TODO_UI_H

#include <iostream>
#include <assert.h>
#include "CinReader.h"
#include "todo_list.h"
#include "todo_item.h"

class TodoUI {
 public:
  /**
   * Default Constructor
   */
  TodoUI();
  /**
   * Defalt Destructor
   */
  ~TodoUI();
  /**
   * Create New Item
   * Edit an Item
   * Delete an Item
   * View All Items
   * View Specific Item
   * Delete All Items
   * Quit Program
   *
   * Named Menu. Contains all of the options specified above. All
   * options may be contained in this function, but it would be better to
   * make private member helper functions to help out the Menu
   * function.
   */
  void menu();

  void ClearScreen() {
    system("printf \"\\033c\"");
  };

 private:
  CinReader sc;
  TodoList *todo_list_;
};
#endif
