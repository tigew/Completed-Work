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
    final_dollars -= final_dollars;
    final_cents   -= final_cents;
  }

  // return
  return Money(final_dollars, final_cents);
}

bool operator ==(const Money &amount1, const Money &amount2) {
  int get_cents1 = amount1.cents_ + (amount1.dollars_ * 100);
  int get_cnets2 = amount2.cents_ + (amount2.dollars_ * 100);
  if (get_cents1 == get_cnets2) {
    return true;
  } else {
    return false;
  }
}

const Money operator -(const Money &amount) {
  return amount.cents_;
}

ostream& operator <<(ostream &out, const Money &amount) {
  int cents_1 = amount.cents_ + (amount.dollars_ * 100);
  int abs_all_cents = abs(cents_1);
  int final_dollars = abs_all_cents / 100;
  int final_cents = abs_all_cents % 100;
  out << "$" << final_dollars << "." << final_cents;
}












