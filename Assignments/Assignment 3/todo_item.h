#ifndef TODO_ITEM_H
#define TODO_ITEM_H

#include <string>
#include <iostream>

using std::string;
using std::ostream;

class TodoItem {
 public:
  /**
   * Default Constructor
   */
  TodoItem(string description, int priority = 1, bool completed = false);
  /**
   * Default Destructor
   */
  ~TodoItem();
  /**
   * Sets the private string description_
   *
   * @param description - Desired description
   */
  void SetDescription(string description);
  /**
   * Sets the private int priority_
   * set the priority to 5 if invalid value is given
   * @param priority - Desired priority
   */
  void SetPriority(int priority = 5);
  /**
   * Sets the private bool completed_
   * @param completed - is the task completed or not
   */
  void SetCompleted(bool completed);
  /**
   * Accsesor
   * @return private string description_
   */
  string GetDescription() const;
  /**
   * Accsesor
   * @return private int priority_
   */
  int GetPriority() const;
  /**
   * Accsesor
   * @return private bool completed_
   */
  bool GetCompleted() const;
  /**
   * Returns a string containing the description,
   * priority, and completed status, separated by the @ symbol (This is
   * the description@3@1). Uses the scrub function to change @
   * symbols in the description.
   *
   * @return string containing all item details seperated by an '@' symbol
   */
  string ToFile();
  /**
   * Outputs (in a nice looking way) all of the information about the
   * item
   */
  friend ostream& operator <<(ostream &out, const TodoItem &item);

 private:
  string description_;
  int priority_;
  bool completed_;
  /**
   * Replaces all '@' wiht '#' symbols and returns the modified string
   * @param string to be scrubed from ToFile()
   *
   * @return the modifed string with the new symbol
   */
  string Scrub(string unmodifed);
};

#endif
