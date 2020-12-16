#include "bigint.h"

#include <malloc.h>
#include <stdlib.h>

#include <cmath>
#include <iostream>
#include <vector>

#define max(x, y) ((x) > (y) ? (x) : (y))

using namespace std;

// will be written by David Li
// basic helper function and skeleton for this code taken from
// https://github.com/jubaer-pantho/RSA-Implementation-Cpp/blob/master/BigInteger.h
// modifications will be made to simplify and specify the class for the sake
// of this project

BigInteger::BigInteger(int n) {
  size = n;
  for (int i = 0; i < n; i++) {
    nums.push_back(1);
  }
}

BigInteger::BigInteger(const BigInteger& obj)
    : nums(obj.nums), size(obj.size) {}

BigInteger::~BigInteger() {}

void BigInteger::add(BigInteger& a, BigInteger& b) {
  unsigned long long int base = 4294967296;
  unsigned int next = 0;
  for (int i = 0; i < size; i++) {
    unsigned long long int sum = 0;
    sum = (unsigned long long int)a.nums.at(i) +
          (unsigned long long int)b.nums.at(i) + next;
    nums.at(i) = (unsigned int)(sum % base);
    next = (unsigned int)(sum / base);
  }
}

void BigInteger::sub(BigInteger& a, BigInteger& b) {
  unsigned long long int base = 4294967296;
  unsigned int next = 0;
  for (int i = 0; i < size; i++) {
    unsigned long long int sum = 0;
    sum = (long long int)a.nums.at(i) - (long long int)b.nums.at(i) + next;
    nums.at(i) = (unsigned int)(sum % base);
    next = (unsigned int)(sum / base);
  }
}

void BigInteger::setDigits(unsigned int index, unsigned int val) {
  nums.at(index) = (unsigned int)val;
}
/*
void BigInteger::showDigits() {
  int nonZeroDigitFlag = 0;
  for (int i = (nSize - 1); i >= 0; i--) {
    if (digit[i] != 0) {
      nonZeroDigitFlag = 1;
    }
    if (nonZeroDigitFlag == 1) {
      printf("%u ", digit[i]);
    }
  }

  if (nonZeroDigitFlag == 0) {
    printf("0");
  }
  cout << endl;
}







void BigInteger::multBigInteger(BigInteger& a, BigInteger& b) {
  for (int k = 0; k < nSize; k++) {
    digit[k] = 0;
  }

  int smallN = a.nSize / 2;
  unsigned long long int base = 4294967296;

  for (int j = 0; j < smallN; j++) {
    if (b.digit[j] == 0) {
      digit[j + smallN] = 0;
    } else {
      unsigned int k = 0;

      for (int i = 0; i < smallN; i++) {
        unsigned long long int t =
            ((unsigned long long int)a.digit[i]) * b.digit[j] +
            (unsigned long long int)digit[i + j] + k;
        digit[i + j] = t % base;
        k = t / base;
      }
    }
  }
}

void BigInteger::copy(BigInteger& a, int index) {
  for (int i = 0; i < nSize; i++) {
    if (i >= index && (i - index) < a.nSize) {
      digit[i] = a.digit[i - index];
    } else {
      digit[i] = 0;
    }
  }
}
*/
int compare(BigInteger& a, BigInteger& b) {
  int ptr = 0;
  if (a.size < b.size) {
    return -1;
  }
  if (a.size > b.size) {
    return 1;
  }

  while (ptr < a.size) {
    if (a.nums.at(ptr) < b.nums.at(ptr)) {
      return -1;
    } else if (a.nums.at(ptr) > b.nums.at(ptr)) {
      return 1;
    }
    ptr++;
  }

  return 0;
}

void print(BigInteger a) {
  for (int i = 0; i < a.nums.size(); i++) {
    cout << a.nums.at(i) << " ";
  }
  cout << "\n";
}

/*int main() {
  BigInteger a(10);
  // cout << a.nums.at(1) << " ";
  print(a);
  BigInteger b(10);
  print(b);
  BigInteger c(10);
  c.add(a, b);
  print(c);
  c.setDigits(1, 3);
  print(c);
  cout << compare(a, c) << "\n";
}
*/