#ifndef _COMPLEX_HPP_
#define _COMPLEX_HPP_

#include <iostream>

class Complex
{
private:
  double _real;
  double _imaginary;
public:
  Complex(double realPart, double imaginaryPart);

  double& imaginary() { return _imaginary;}
  double imaginary() const  { return _imaginary;}
  
  
  Complex operator+(const Complex& otherNumber) const; // do this + otherNumber
  Complex operator+(double otherNumber); // do this + otherNumber
  friend Complex operator+(double realVal, Complex complexVal); // do realVal + complexVal

  Complex operator*(Complex otherNumber); // do this * otherNumber

  Complex operator/(Complex otherNumber); // do this / otherNumber
  
  friend std::ostream& operator<<(std::ostream &os, Complex someNumber); 
  
  void print();
};

#endif
