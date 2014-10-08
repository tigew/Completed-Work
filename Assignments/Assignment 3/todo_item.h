#ifndef TODO_ITEM_H
#define TODO_ITEM_H

#include <string>
#include <iostream>

using std::string;
using std::ostream;

class TodoItem {
 public:
  /**
   * 
   */
  TodoItem(string description, int priority = 1, bool completed = false);
  /**
   * 
   */
  ~TodoItem();
  /**
   * [SetDescription description]
   * @param  description [description]
   * @return             [description]
   */
  string SetDescription(string description);
  /**
   * [SetPriority description]
   * @param  priority [description]
   * @return          [description]
   */
  int SetPriority(int priority);
  /**
   * [SetCompleted description]
   * @param  completed [description]
   * @return           [description]
   */
  bool SetCompleted(bool completed);
  /**
   * [GetDescription description]
   * @return [description]
   */
  string GetDescription() const;
  /**
   * [GetPriority description]
   * @return [description]
   */
  int GetPriority() const;
  /**
   * [GetCompleted description]
   * @return [description]
   */
  bool GetCompleted() const;
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
  string description_;
  int priority_;
  bool completed_;
  /**
   * [Scrub description]
   * @return [description]
   */
  string Scrub();
};

#endif
