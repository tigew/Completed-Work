#ifndef TODO_UI_H
#define TODO_UI_H

#include "CinReader.h"
#include "todo_list.h"

class TodoUI {
 public:
  /**
   * 
   */
  TodoUI();
  /**
   * 
   */
  ~TodoUI();
  /**
   * [menu description]
   */
  void menu();

 private:
  CinReader sc;
};
#endif
