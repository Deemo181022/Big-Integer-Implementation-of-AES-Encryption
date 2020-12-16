#include <cmath>
#include <iostream>

using namespace std;

int powermod(int a, int b, int r) {  // a^b mod r
  int prod = 1;
  while (b > 0) {
    if (b % 2 != 0) prod = (prod * a) % r;  // if b is even
    a = (a * a) % r;
    b = b / 2;
  }
  return prod;
}

bool singleTest(int n, int a) {
  int d = n - 1;
  // While even, divide by 23
  while (d % 2 == 0) {
    d = d >> 1;
  }
  if (powermod(a, d, n) == 1) return true;  // If a^d mod n = 1, probably prime

  while (d < n - 1) {
    if (powermod(a, d, n) == n - 1)
      return true;  // if a^d mod n = n-1, probably prime
    d = d << 1;     // d = d^2
  }

  return false;  // if we get here, definitely not prime
}

// O(k*(log n)^2), where n is number and k is # of trials
bool MillerRabin(int n, int trials) {
  // Repeat for number of trials
  for (int i = 1; i <= trials; i++) {
    int a = rand() % (n - 2) + 2;         // random number between 2 and n-2
    if (!singleTest(n, a)) return false;  // if determined definitely not prime
  }
  return true;  // if we reach here, probably prime
}

// If prime, returns true. Not prime returns false
// 561, 1105, 1729, 2465, 2821, 6601, 8911
// tested with carmichael #'s listed above