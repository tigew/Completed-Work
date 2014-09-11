/*
 * Name        : assignment_1.cpp
 * Author      : Travis Peebles
 * Description : The purpose of this assignment is to practice basic programming
 *               techniques using the C++ programming language.
 *
 */

#include <iostream>
#include <string>
#include <iostream>
#include <climits>
using std::cin;
using std::cout;
using std::endl;
using std::string;

// Function Prototypes (DO NOT ALTER)
void CountCharacters(string input, int &is_alpha, int &is_numeric);
string UpAndDown(string input);
int CountWords(string input);
int Average(int num_array[], int limit);
int Minimum(int num_array[], int limit);
int Maximum(int num_array[], int limit);
void UnitTest();
void Test(bool test, string more_info = "");

// Program Execution Starts Here
int main() {
  // Calls UnitTest
  UnitTest();
  // This ends program execution
  return 0;
}

/*
 * This function will count the number of alphabetic characters and the 
 * number of numeric characters in a string.
 * @uses
 * @param string input - The input string to itterate
 * @param int &is_alpha - The store of alpha chars
 * @param int &is_numeric - The store of numeric chars
 * @return Nothing 
 */
void CountCharacters(string input, int &is_alpha, int &is_numeric) {
  char test_char = ' ';
  is_alpha = 0;
  is_numeric = 0;

  for (unsigned int i = 0; i < input.length(); i++) {
    test_char = input.at(i);
    // Checks if alpha or numeric, and counts accordingly
    if (isalpha(test_char)) {
      is_alpha++;
    } else if (isdigit(test_char)) {
      is_numeric++;
    }
  }
}

/*
 * This function will take a string and return a version of it where the 
 * first letter is capitalized, the second is lowercase, the third is 
 * capitalized, etc.
 * @uses 
 * @param string input - The input String
 * @return string - Returns the input string with the first Letter capital
 *                  second letter lowercase, third capital and so on.
 */
string UpAndDown(string input) {
  for (unsigned int i = 0; i < input.length(); i++) {
    // Checks if even or odd, to change case
    if (i % 2 == 0) {
      input.at(i) = toupper(static_cast<char>(input.at(i)));
    } else {
      input.at(i) = tolower(static_cast<char>(input.at(i)));
    }
  }
  return input;
}

/* 
 * This function will take a string of words, delimited by a space 
 * character, and count how many words there are. The string will 
 * never have multiple spaces between words or a space at the
 * beginning or the end.
 * @uses 
 * @param string input - The string of words to be counted
 * @return int - The number of words that have been counted from the 
 *                     string
 */
int CountWords(string input) {
  int num_words = 0;
  // If it contains at least one word + 1
  if (input.length() > 0) {
    num_words++;
  }
  // Count spaces beyond that for word count
  // This would not work if leading and ending spaces were included
  for (unsigned int i = 0; i < input.length(); ++i) {
    if (input.at(i) == ' ') {
      num_words++;
    }
  }
  return num_words;
}

/* 
 * This function will compute the mean average of the values in the 
 * array. The array will always be at least of size 1.
 * @uses
 * @param int num_array[] - The Array of which the average will be computed
 * @param int limit - the size of the array
 * @return int - The average of the values in the array.
 */
int Average(int num_array[], int limit) {
  // Average(foo, (sizeof(foo)/sizeof(*foo))); example function call
  int total = 0;
  int average = 0;
  // Adds array together, then divides by the total size
  for (int i = 0; i < limit; i++) {
    total += num_array[i];
  }
  average = total / limit;
  return average;
}

/*
 * This function will find and return the smallest value in an array. The 
 * array will always be at least of size 1.
 * @uses
 * @param int num_array[] - The array of which the smallest value will be found
 * @param int limit - the size of the array
 * @return int - The samllest number contained in the array
 */
int Minimum(int num_array[], int limit) {
  int smallest_num = num_array[0];
  // compares to entire array to itself to find the smallest
  for (int i = 0; i < limit; i++) {
    if (num_array[i] < smallest_num) {
      smallest_num = num_array[i];
    }
  }
  return smallest_num;
}

/*
 * This function will find and return the largest value in an array. The 
 * array will always be at least of size 1.
 * @uses
 * @param int num_array[] - The array of which the largest value will be found
 * @param int limit - the size of the array
 * @return int - The largest number contained in the array
 */
int Maximum(int num_array[], int limit) {
  int largest_num = num_array[0];
  // compares to entire array to itself to find the largest
  for (int i = 0; i < limit; i++) {
    if (num_array[i] > largest_num) {
      largest_num = num_array[i];
    }
  }
  return largest_num;
}

// Function Definitions
void UnitTest() {
  cout << "\nSTARTING UNIT TEST\n\n";

  int n1 = 0, n2 = 0;
  CountCharacters("", n1, n2);
  Test((n1 == 0) && (n2 == 0), "CountCharacters(empty string)");
  CountCharacters("hello", n1, n2);
  Test((n1 == 5) && (n2 == 0), "CountCharacters(\"hello\")");
  CountCharacters("12345", n1, n2);
  Test((n1 == 0) && (n2 == 5), "CountCharacters(\"12345\")");
  CountCharacters("hello 12345", n1, n2);
  Test((n1 == 5) && (n2 == 5), "CountCharacters(\"hello 12345\")");
  CountCharacters("&,.", n1, n2);
  Test((n1 == 0) && (n2 == 0), "CountCharacters(\"&,.\")");
  string s;
  s = UpAndDown("hello");
  Test(s == "HeLlO", "UpAndDown(\"hello\")");
  s = UpAndDown("HeLlO");
  Test(s == "HeLlO", "UpAndDown(\"HeLlO\")");
  s = UpAndDown("hElLo");
  Test(s == "HeLlO", "UpAndDown(\"hElLo\")");
  s = UpAndDown("");
  Test(s == "", "UpAndDown(\"\")");
  s = UpAndDown("a");
  Test(s == "A", "UpAndDown(\"a\")");
  Test(CountWords("") == 0, "CountWords(\"\")");
  Test(CountWords("hello") == 1, "CountWords(\"hello\")");
  Test(CountWords("hello,world") == 1, "CountWords(\"hello world\")");
  Test(CountWords("hello world") == 2, "CountWords(\"hello world\")");
  Test(CountWords("hello, world") == 2, "CountWords(\"hello, world\")");
  int values[] = { 10, 20, 30 };
  Test(Average(values, 3) == 20, "ComputeAverage([10,20,30])");
  values[0] = 0, values[1] = 0, values[2] = 0;
  Test(Average(values, 3) == 0, "ComputeAverage([0,0,0])");
  values[0] = 5, values[1] = 7, values[2] = 11;
  Test(Average(values, 3) == 7, "ComputeAverage([5,7,11])");
  values[0] = -10, values[1] = -20, values[2] = -30;
  Test(Average(values, 3) == -20, "ComputeAverage([-10,-20,-30])");
  values[0] = -5, values[1] = 0, values[2] = 5;
  Test(Average(values, 3) == 0, "ComputeAverage([-5,0,5])");
  values[0] = -1, values[1] = 0, values[2] = 1;
  Test(Minimum(values, 3) == -1, "FindMinValue([-1,0,1])");
  values[0] = -3, values[1] = -2, values[2] = -1;
  Test(Minimum(values, 3) == -3, "FindMinValue([-3,-2,-1])");
  values[0] = 0, values[1] = 1, values[2] = 2;
  Test(Minimum(values, 3) == 0, "FindMinValue([0,1,2])");
  values[0] = 1, values[1] = 1, values[2] = 1;
  Test(Minimum(values, 3) == 1, "FindMinValue([1,1,1])");
  values[0] = INT_MAX, values[1] = INT_MAX, values[2] = INT_MAX;
  Test(Minimum(values, 3) == INT_MAX,
       "FindMinValue([INT_MAX,INT_MAX,INT_MAX])");
  values[0] = -1, values[1] = 0, values[2] = 1;
  Test(Maximum(values, 3) == 1, "FindMaxValue([-1,0,1])");
  values[0] = -3, values[1] = -2, values[2] = -1;
  Test(Maximum(values, 3) == -1, "FindMaxValue([-3,-2,-1])");
  values[0] = 0, values[1] = 1, values[2] = 2;
  Test(Maximum(values, 3) == 2, "FindMaxValue([0,1,2])");
  values[0] = 1, values[1] = 1, values[2] = 1;
  Test(Maximum(values, 3) == 1, "FindMaxValue([1,1,1])");
  values[0] = INT_MIN, values[1] = INT_MIN, values[2] = INT_MIN;
  Test(Maximum(values, 3) == INT_MIN,
       "FindMaxValue([INT_MIN,INT_MIN,INT_MIN])");

  cout << "\nUNIT TEST COMPLETE\n\n";
}

// For testing (DO NOT ALTER)
void Test(bool test, string more_info) {
  static int test_number = 1;
  if (test)
    cout << "PASSSED TEST ";
  else
    cout << "FAILED  TEST ";
  cout << test_number << " " << more_info << "!\n";
  test_number++;
}
