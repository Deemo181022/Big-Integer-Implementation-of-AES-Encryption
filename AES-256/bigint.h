#ifndef BIGINTEGER_H
#define BIGINTEGER_H
#include <vector>
// helper file for this code taken from
// https://github.com/jubaer-pantho/RSA-Implementation-Cpp/blob/master/BigInteger.h
// modifications will be made to simplify and specify the class for the sake
// of this project

class BigInteger {
 public:
  int size;                        // size
  std::vector<unsigned int> nums;  // vector to hold objects
  BigInteger() {}
  BigInteger(int n);
  BigInteger(const BigInteger& obj);
  ~BigInteger();  // deconstructor

  void add(BigInteger& a, BigInteger& b);
  void sub(BigInteger& a, BigInteger& b);
  void setDigits(unsigned int index, unsigned int val);
  /* void mult(BigInteger& a, BigInteger& b);
   void copy(BigInteger& a, int index);
   void expoModNBigInteger(BigInteger& x, BigInteger& y, BigInteger& N,
                           BigInteger& result);
   void setSize(int n);*/
};

int Compare(BigInteger& first, BigInteger& second);

#endif  // BIGINTEGER_H
