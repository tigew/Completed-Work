#include "temperature.h"

// CLASS FUNCTION DEFINITIONS GO HERE
Temperature::Temperature() {
  kelvin_ = 0;
}

Temperature::Temperature(double kelvin) {
  kelvin_ = kelvin;
}

Temperature::Temperature(double temp, char unit) {
  switch (unit) {
    case 'C':
    case 'c':
      SetTempFromCelsius(temp);
    break;

    case 'F':
    case 'f':
      SetTempFromFahrenheit(temp);
    break;

    default:  // K
      kelvin_ = temp;
    break;
  }
}

void Temperature::SetTempFromKelvin(double kelvin) {
  kelvin_ = kelvin;
}

void Temperature::SetTempFromCelsius(double celsius) {
  kelvin_ = celsius + 273.15;
}

void Temperature::SetTempFromFahrenheit(double fahrenheit) {
  kelvin_ = (5.0 * (fahrenheit - 32) / 9) + 273.15;
}

double Temperature::GetTempAsKelvin() const {
  return kelvin_;
}

double Temperature::GetTempAsCelsius() const {
  return kelvin_ - 273.15;
}

double Temperature::GetTempAsFahrenheit() const {
  return ((GetTempAsCelsius() * 9.0) / 5) + 32;
}

string Temperature::ToString(char unit) const {
  stringstream ss;
  ss.setf(std::ios::fixed|std::ios::showpoint);
  ss.precision(2);

  switch (unit) {
    case 'c':
    case 'C':
      ss << GetTempAsCelsius() << " Celsius";
    break;

    case 'f':
    case 'F':
      ss << GetTempAsFahrenheit() << " Fahrenheit";
    break;

    case 'k':
    case 'K':
      ss << GetTempAsKelvin() << " Kelvin";
    break;

    default:
      ss << "Invalid Unit";
    break;
  }

  return ss.str();
}





