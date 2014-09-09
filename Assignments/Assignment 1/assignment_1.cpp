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

// Program Execution Starts Here
int main() {
  int is_alpha = 0;
  int is_numeric = 0;
  int foo[5] = {16, 2, 77, 40, 12071};

  CountCharacters("Tester123", is_alpha, is_numeric);
  cout << "# of alpha characters in 'Tester123' " << is_alpha << endl;
  cout << "# of numeric characters in 'Tester123' " << is_numeric << endl;
  cout << "'Hello World' mutated " << UpAndDown("HelloWorld") << endl;
  cout << "Number of words in 'Hello World' "
       << CountWords("Hello World") << endl;
  cout << "Average of 16, 2, 77, 40, 12071 (non floating) is "
       << Average(foo, 5) << "." << endl;
  cout << "Minimum of 16, 2, 77, 40, 12071 (non floating) is "
       << Minimum(foo, 5) << "." << endl;
  cout << "Maximum of 16, 2, 77, 40, 12071 (non floating) is "
       << Maximum(foo, 5) << "." << endl;
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
