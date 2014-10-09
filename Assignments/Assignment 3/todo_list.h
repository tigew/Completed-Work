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
   * Default Constructor
   */
  TodoList();
  /**
   * Default Destructor
   */
  ~TodoList();
  /**
   *
   * If there is room in the array add the new dynamic
   * instance to the first available spot (i.e. the current size). If the array
   * is full, increase capacity by 10 and then add the item.
   *
   * @param item - item to be added
   */
  void AddItem(TodoItem *item);
  /**
   * Please note the location is in human-readable form, i.e.
   * location 1 is really array index 0. After you delete the item you will
   * need to pack your array (shift all items "down" so there are no
   * empty slots between items).
   *
   * @param location - location of the item to be deleted
   */
  void DeleteItem(int location);
  /**
   * Please note the location is in human-readable form, i.e.
   * location 1 is really array index 0. After you delete the item you will
   * need to pack your array (shift all items "down" so there are no
   * empty slots between items).
   *
   * @return TodoItem pointer
   */
  TodoItem* GetItem();
  /**
   * Returns an integer containing the current size of
   * the list (number of items present).
   *
   * @return int - int that contains the current size of list
   */
  int GetSize();
  /**
   * Returns an integer containing the current
   * maximum capacity of the list (number of slots).
   *
   * @return int - the capacity of the list
   */
  int GetCapacity();
  /**
   *  Sorts the array by the priorities of the items. (1 is
   * highest priority, 5 is lowest).
   */
  void Sort();
  /**
   * Returns a string containing all TodoItems in the list.
   * Uses the TodoItems ToFile function to create. Each item should be
   * on its own line.
   *
   * @return string - formated string with infor requested
   */
  string ToFile();
  /**
   * Outputs a numbered list of all TodoItem present in the list. Will use
   * TodoItem overloaded<<
   */
  friend ostream& operator <<(ostream &out, const TodoList &list);

 private:
  /**
   * Increases the capacity of the array by 10. Should be called by
   * AddItem at the appropriate time.
   */
  void IncreaseCapacity();
  /**
   * Compacts the array to get rid of an empty spot in the array.
   * Should be called by DeleteItem at the appropriate time.
   */
  void DecreaseCapacity();
};
#endif
