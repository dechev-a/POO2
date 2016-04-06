#ifndef FRACTION_HPP_
#define FRACTION_HPP_

#include <iostream>

class fraction
{
 private:
  int	numerator;
  int	denominator;

 public:
  fraction(int numerator, int denominator);
  ~fraction();

  int	get_numerator();
  int	get_denominator();
  
  fraction operator+(const int & n);
  fraction operator-(const int & n);
  fraction operator*(const int & n);
  fraction operator/(const int & n);

  fraction operator+(const fraction & f);
  fraction operator-(const fraction & f);
  fraction operator*(const fraction & f);
  fraction operator/(const fraction & f);

  
  fraction operator+();
  fraction operator-();
  fraction operator~();
};

fraction	operator+(int num, fraction f);
fraction	operator-(int num, fraction f);
fraction	operator*(int num, fraction f);
fraction	operator/(int nume, fraction f);

std::ostream		&operator<<(std::ostream &flux, fraction f);

#endif
