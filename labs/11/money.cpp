#include "money.h"

// This function definition provided as an example
const Money operator +(const Money& amount1, const Money& amount2) {
  // Get all the cents of object 1
  int all_cents1 = amount1.cents_ + amount1.dollars_ * 100;
  // Get all the cents of object 2
  int all_cents2 = amount2.cents_ + amount2.dollars_ * 100;
  // Add all the cents together
  int sum_all_cents = all_cents1 + all_cents2;
  // Handle the fact that money can be negative
  int abs_all_cents = abs(sum_all_cents);
  int final_dollars = abs_all_cents / 100;
  int final_cents = abs_all_cents % 100;
  // If the result of the operation was negative, negate final dollars and cents
  if (sum_all_cents < 0) {
    final_dollars = -final_dollars;
    final_cents = -final_cents;
  }
  return Money(final_dollars, final_cents);
}

// CLASS FUNCTION DEFINITIONS GO HERE

const Money operator -(const Money& amount1, const Money& amount2) {
  // get cents from both objects
  int cents_1 = amount1.cents_ + amount1.dollars_ * 100;
  int cents_2 = amount2.cents_ + amount2.dollars_ * 100;

  // subtract them
  int sum_all_cents = cents_1 - cents_2;

  // handle negatives
  int abs_all_cents = abs(sum_all_cents);
  int final_dollars = abs_all_cents / 100;
  int final_cents = abs_all_cents % 100;

  if (sum_all_cents < 0) {
    final_dollars = -final_dollars;
    final_cents  = -final_cents;
  }
  // return
  return Money(final_dollars, final_cents);
}

bool operator ==(const Money &amount1, const Money &amount2) {
  int get_cents1 = amount1.cents_ + amount1.dollars_ * 100;
  int get_cnets2 = amount2.cents_ + amount2.dollars_ * 100;
  if (get_cents1 == get_cnets2) {
    return true;
  } else {
    return false;
  }
  return true;
}

const Money operator -(const Money &amount) {
  // return the opposite of what it gets
  return Money(-amount.dollars_, -amount.cents_);
}

/*
ostream& operator <<(ostream &out, const Money &amount) {
  //  handle negatives
  if (amount.cents_ < 0 || amount.dollars_ < 0) {
    //  handle negatives that are greater then -10
    if (amount.cents_ > -10) {
      return out << "$-" << abs(amount.dollars_) << ".0" << abs(amount.cents_);
    }
    return out << "$-" << abs(amount.dollars_) << "." << abs(amount.cents_);
  }
  // handle less then 10
  if (amount.cents_ < 10) {
    return out << "$" << abs(amount.dollars_) << ".0" << abs(amount.cents_);
  }
  // straight print from object
  return out << "$" << abs(amount.dollars_) << "." << abs(amount.cents_);
}
*/

// USE THIS ONE NOT THE ONE ABOVE
ostream& operator <<(ostream &out, const Money &amount) {
  //  handle negatives
  if (amount.dollars_ < 0 || amount.cents_ < 0) {
    return out << "$-" << abs(amount.dollars_) << "."
                    << setw(2) << setfill('0')
                    << abs(amount.cents_);
  } else {
    return out << "$" << abs(amount.dollars_) << "."
                    << setw(2) << setfill('0')
                    << abs(amount.cents_);
  }
}










