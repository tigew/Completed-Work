/*
 * Name        : assignment_3_unit_test.cpp
 * Author      : Luke Sathrum
 * Description : Unit Test for class TodoItem and TodoList.
 *               THIS FILE SHOUD NOT BE ALTERED, UNLESS DEBUGGING IN MAIN
 */

#include <iostream>
#include <sstream>
#include <streambuf>
#include "todo_list.h"
#include "todo_item.h"
using std::cout;
using std::endl;
using std::string;

// For testing (DO NOT ALTER)
void Test(bool test, string more_info = "");
void UnitTest();

// Program Execution Starts Here
int main() {
  // START DEBUGGING CODE
  // END DEBUGINH CODE
  // To test your code (DO NOT ALTER)
  UnitTest();
  // This ends program execution
  return 0;
}

// For testing (DO NOT ALTER)
void UnitTest() {
  string temp = "This unit test will test some of your code:\n";
  cout << temp << string(temp.length() - 1, '-') << endl;
  // Tests
  string desc1 = "Go to Store";
  string desc2 = "Brush Teeth @ 8PM";

  cout << "*****TodoItem(\"Go to Store\")*****\n";
  TodoItem item(desc1);
  Test(item.description() == desc1, "description()");
  Test(item.priority() == 1, "priority()");
  Test(item.completed() == false, "completed()");
  Test(item.ToFile() == "Go to Store@1@0", "ToFile()");
  cout << "Testing Overloaded <<: " << item << endl;

  cout << "\n*****TodoItem(\"Go to Store\", 3)*****\n";
  TodoItem item2(desc1, 3);
  Test(item2.description() == desc1, "description()");
  Test(item2.priority() == 3, "priority()");
  Test(item2.completed() == false, "completed()");
  Test(item2.ToFile() == "Go to Store@3@0", "ToFile()");
  cout << "Testing Overloaded <<: " << item2 << endl;

  cout << "\n*****TodoItem(\"Go to Store\", 2, true)*****\n";
  TodoItem item3(desc1, 2, true);
  Test(item3.description() == desc1, "description()");
  Test(item3.priority() == 2, "priority()");
  Test(item3.completed() == true, "completed()");
  Test(item3.ToFile() == "Go to Store@2@1", "ToFile()");
  cout << "Testing Overloaded <<: " << item3 << endl;

  cout << "\n*****TodoItem Mutators*****\n";
  item.set_description(desc2);
  Test(item.description() == desc2,
       "set_description(\"Brush Teeth @ 8PM\") / description()");
  item.set_priority(4);
  Test(item.priority() == 4, "set_priority(4) / priority()");
  item.set_priority(0);
  Test(item.priority() == 5, "set_priority(0) / priority()");
  item.set_priority(6);
  Test(item.priority() == 5, "set_priority(6) / priority()");
  item.set_completed(true);
  Test(item.completed() == true, "set_completed(true) / completed()");
  Test(item.ToFile() == "Brush Teeth # 8PM@5@1", "ToFile()");
  cout << "Testing Overloaded <<: " << item << endl;

  cout << "\n*****TodoList Constructor*****\n";
  TodoList list;
  Test(list.GetSize() == 0, "GetSize()");
  Test(list.GetCapacity() == 25, "GetCapacity()");
  Test(list.ToFile() == "", "ToFile()");

  cout << "\n*****TodoList Member Functions with 1 Item*****\n";
  list.AddItem(new TodoItem(desc1));
  Test(list.GetSize() == 1, "AddItem(TodoItem(\"Go to Store\")) / GetSize()");
  Test(list.GetCapacity() == 25, "GetCapacity()");
  Test(list.GetItem(1)->ToFile() == "Go to Store@1@0", "GetItem(1)->ToFile()");
  Test(list.ToFile() == "Go to Store@1@0\n", "ToFile()");
  cout << "Testing Overloaded <<:\n" << list << endl;

  cout << "\n*****TodoList Member Functions with 2 Items*****\n";
  list.AddItem(new TodoItem(desc1, 2, true));
  Test(list.GetSize() == 2,
       "AddItem(TodoItem(\"Go to Store\", 2, true)) / GetSize()");
  Test(list.GetCapacity() == 25, "GetCapacity()");
  Test(list.GetItem(1)->ToFile() == "Go to Store@1@0", "GetItem(1)->ToFile()");
  Test(list.GetItem(2)->ToFile() == "Go to Store@2@1", "GetItem(2)->ToFile()");
  Test(list.ToFile() == "Go to Store@1@0\nGo to Store@2@1\n", "ToFile()");
  list.DeleteItem(1);
  Test(list.GetSize() == 1, "DeleteItem(1) / GetSize()");
  Test(list.GetCapacity() == 25, "GetCapacity()");
  cout << "Testing Overloaded <<:\n" << list << endl;

  cout << "\n*****TodoList Member Functions with 25 Items*****\n";
  list.AddItem(new TodoItem(desc2, 4, true));
  stringstream ss;
  for (int i = 0; i < 23; i++) {
    ss << "Description #" << i + 3;
    list.AddItem(new TodoItem(ss.str(), i % 5 + 1));
    ss.str("");
  }
  Test(list.GetSize() == 25, "AddItem(Adding 24 More Items) / GetSize()");
  Test(list.GetCapacity() == 25, "GetCapacity()");
  Test(list.GetItem(17)->ToFile() == "Description #17@5@0",
       "GetItem(17)->ToFile()");
  Test(list.GetItem(25)->ToFile() == "Description #25@3@0",
       "GetItem(25)->ToFile()");
  string to_file =
      "Go to Store@2@1\nBrush Teeth # 8PM@4@1\nDescription #3@1@0\n"
          "Description #4@2@0\nDescription #5@3@0\nDescription #6@4@0\n"
          "Description #7@5@0\nDescription #8@1@0\nDescription #9@2@0\n"
          "Description #10@3@0\nDescription #11@4@0\nDescription #12@5@0\n"
          "Description #13@1@0\nDescription #14@2@0\nDescription #15@3@0\n"
          "Description #16@4@0\nDescription #17@5@0\nDescription #18@1@0\n"
          "Description #19@2@0\nDescription #20@3@0\nDescription #21@4@0\n"
          "Description #22@5@0\nDescription #23@1@0\nDescription #24@2@0\n"
          "Description #25@3@0\n";
  Test(list.ToFile() == to_file, "ToFile()");
  cout << "Testing Overloaded <<:\n" << list << endl;

  list.DeleteItem(15);
  Test(list.GetSize() == 24, "DeleteItem(15) / GetSize()");
  Test(list.GetCapacity() == 25, "GetCapacity()");
  Test(list.GetItem(10)->ToFile() == "Description #10@3@0",
       "GetItem(10)->ToFile()");
  Test(list.GetItem(20)->ToFile() == "Description #21@4@0",
       "GetItem(20)->ToFile()");
  to_file = "Go to Store@2@1\nBrush Teeth # 8PM@4@1\nDescription #3@1@0\n"
      "Description #4@2@0\nDescription #5@3@0\nDescription #6@4@0\n"
      "Description #7@5@0\nDescription #8@1@0\nDescription #9@2@0\n"
      "Description #10@3@0\nDescription #11@4@0\nDescription #12@5@0\n"
      "Description #13@1@0\nDescription #14@2@0\n"
      "Description #16@4@0\nDescription #17@5@0\nDescription #18@1@0\n"
      "Description #19@2@0\nDescription #20@3@0\nDescription #21@4@0\n"
      "Description #22@5@0\nDescription #23@1@0\nDescription #24@2@0\n"
      "Description #25@3@0\n";
  Test(list.ToFile() == to_file, "ToFile()");
  cout << "Testing Overloaded <<:\n" << list << endl;

  cout << "\n*****TodoList Member Functions with 30 Items*****\n";
  for (int i = 25; i <= 30; i++) {
    ss << "New Description #" << i;
    list.AddItem(new TodoItem(ss.str(), i % 5 + 1, true));
    ss.str("");
  }
  Test(list.GetSize() == 30, "AddItem(Adding 6 More Items) / GetSize()");
  Test(list.GetCapacity() == 35, "GetCapacity()");
  Test(list.GetItem(11)->ToFile() == "Description #11@4@0",
       "GetItem(11)->ToFile()");
  Test(list.GetItem(30)->ToFile() == "New Description #30@1@1",
       "GetItem(30)->ToFile()");
  to_file = "Go to Store@2@1\nBrush Teeth # 8PM@4@1\nDescription #3@1@0\n"
      "Description #4@2@0\nDescription #5@3@0\nDescription #6@4@0\n"
      "Description #7@5@0\nDescription #8@1@0\nDescription #9@2@0\n"
      "Description #10@3@0\nDescription #11@4@0\nDescription #12@5@0\n"
      "Description #13@1@0\nDescription #14@2@0\n"
      "Description #16@4@0\nDescription #17@5@0\nDescription #18@1@0\n"
      "Description #19@2@0\nDescription #20@3@0\nDescription #21@4@0\n"
      "Description #22@5@0\nDescription #23@1@0\nDescription #24@2@0\n"
      "Description #25@3@0\nNew Description #25@1@1\nNew Description #26@2@1\n"
      "New Description #27@3@1\nNew Description #28@4@1\n"
      "New Description #29@5@1\nNew Description #30@1@1\n";
  Test(list.ToFile() == to_file, "ToFile()");
  cout << "Testing Overloaded <<:\n" << list << endl;

  cout << "\n*****Sorting TodoList with 30 Items*****\n";
  list.Sort();
  bool sorted = true;
  for (int i = 1; i <= 30; i++) {
    if ((i <= 7) && (list.GetItem(i)->priority()) != 1)
      sorted = false;
    else if ((i > 7 && i <= 14) && (list.GetItem(i)->priority()) != 2)
      sorted = false;
    else if ((i > 14 && i <= 19) && (list.GetItem(i)->priority()) != 3)
      sorted = false;
    else if ((i > 19 && i <= 25) && (list.GetItem(i)->priority()) != 4)
      sorted = false;
    else if ((i > 25 && i <= 30) && (list.GetItem(i)->priority()) != 5)
      sorted = false;
  }
  Test(sorted, "Sort()");
  cout << "Testing Overloaded <<:\n" << list << endl;

  cout << "\n*****TodoList Member Functions with 1000 Items*****\n";
  for (int i = 0; i < 970; i++)
    list.AddItem(new TodoItem("A", 1, true));
  Test(list.GetSize() == 1000, "AddItem(Adding 970 More Items) / GetSize()");
  Test(list.GetCapacity() == 1005, "GetCapacity()");
  cout << "**Deleting All Items**\n";
  for (int i = 1000; i >= 1; i--)
    list.DeleteItem(i);
  Test(list.GetSize() == 0, "DeleteItem() / GetSize()");
  Test(list.GetCapacity() == 1005, "GetCapacity()");

  //Testing Destructors
  cout << "\n*****Testing Destructors*****" << endl
       << "If the next line is the \"END Testing Destructors\" then you passed!"
       << endl;
  TodoItem *dynamic_item = new TodoItem("testing");
  delete dynamic_item;
  dynamic_item = new TodoItem("testing2", 5);
  delete dynamic_item;
  dynamic_item = new TodoItem("Testing3", 3, true);
  TodoList *dynamic_list = new TodoList();
  delete dynamic_list;
  dynamic_list = new TodoList();
  for (int i = 0; i < 50; i++)
    dynamic_list->AddItem(new TodoItem("testing"));
  delete dynamic_list;
  cout << "*****END Testing Destructors*****" << endl;

  cout << string(temp.length() - 1, '-') << endl;
  cout << "Unit Test Complete!\n\n";
}

// For testing (DO NOT ALTER)
void Test(bool test, string more_info) {
  static int test_number = 1;
  if (test)
    cout << "PASSSED TEST ";
  else
    cout << "FAILED  TEST ";
  cout << test_number << " " << more_info << "!" << endl;
  test_number++;
}

