#ifndef TODO_LIST_H
#define TODO_LIST_H

#include "todo_item.h"
#include <string>
#include <iostream>

using std::string;
using std::ostream;

class TodoList {
 public:
  /**
   * 
   */
  TodoList();
  /**
   * 
   */
  ~TodoList();
  /**
   * [AddItem description]
   * @param item [description]
   */
  void AddItem(TodoItem *item);
  /**
   * [DeleteItem description]
   * @param location [description]
   */
  void DeleteItem(int location);
  /**
   * [GetItem description]
   */
  void GetItem();
  /**
   * [GetSize description]
   * @return [description]
   */
  int GetSize();
  /**
   * [GetCapacity description]
   * @return [description]
   */
  int GetCapacity();
  /**
   * [Sort description]
   */
  void Sort();
  /**
   * [ToFile description]
   * @return [description]
   */
  string ToFile();
  /**
   * 
   */
  friend ostream& operator <<(ostream &out, const TodoItem &item);

 private:
  /**
   * [IncreaseCapacity description]
   */
  void IncreaseCapacity();
  /**
   * [DecreaseCapacity description]
   */
  void DecreaseCapacity();
};
#endif
