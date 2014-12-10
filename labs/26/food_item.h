// Travis Peebles
#ifndef FOOD_ITEM_H
#define FOOD_ITEM_H

#include <iostream>
#include <string>
#include <sstream>
#include "item.h"

using std::string;
using std::stringstream;

class FoodItem : public Item {
 public:
    FoodItem(string name = "fooditem", unsigned int value = 0,
             unsigned int calories = 0, string unit_of_measure = "nounits",
             double units = 0);
    virtual ~FoodItem();
    unsigned int calories();
    string unit_of_measure();
    double units();
    void set_calories(unsigned int calories);
    void set_unit_of_measure(string unit_of_measure);
    void set_units(double units);
    // Format -- NAME, $VALUE, UNITS UNITOFMEASURE, CALORIES calories
    string ToString();
 private:
    unsigned int calories_;
    string unit_of_measure_;
    double units_;
};

#endif  // FOOD_ITEM_H
