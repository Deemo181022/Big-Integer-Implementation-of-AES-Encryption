/*
Let's refer to Alice and Bob as the two exchanging messages
Eve is someone listening in to Alice and Bob's exchnage
We Need to generate the following:
g = public(prime) base-> known to Alice,Bob,Eve
p = public(prime) modulus-> known to Alice,Bob,Eve
a = Alice's private key (any value)-> known only to Alice
b = Bob's private key (any value)-> known only to Bob
A = Alice's public key (g^a mod p)-> known by everyone
B = Bob's public key (g^b mod p)-> known by everyone
s = shared private key
    - Alice finds by (B^a mod p)
    - Bob finds by (A^b mod p)

  Below is a table of known and unkowns by each person:

      Alice                Bob              Eve
  Known     Unknown   Known   Unknown   Known   Unknown
  p                    p                 p
  g                    g                 g
  a         b          b      a                  a,b
  A,B                  A,B               A,B
  s                    s                         s
*/
#include <time.h>

#include <iostream>

#include "MillerRabinPrimality.cpp"
using namespace std;

class Person {
 private:
  int key;
  int message;

 public:
  Person(int k) : key(k) {}
  int publicKey;

  // O(log n)
  int powermod(int a, int b, int r) {  // a^b mod r
    int prod = 1;
    while (b > 0) {
      if (b % 2 != 0) prod = (prod * a) % r;  // if b is even
      a = (a * a) % r;
      b = b / 2;
    }
    return prod;
  }

  // For debugging
  int printKey() {
    int myKey = (*this).key;
    return myKey;
  }
  // For debugging
  int printMessage() {
    int myMessage = (*this).message;
    return myMessage;
  }

  void findPublicKey(int p, int g) {
    int A = powermod(g, (*this).key, p);
    publicKey = A;
  }

  void findMessage(int pubKey, int p) {
    // mod 256 since we want 2 hex digits
    (*this).message = powermod(pubKey, (*this).key, p) % 256;
  }
};

// O(m*2*(log n)^2), where m is number of tests needed and n is the number
// tested
int RandomPrime() {
  while (true) {
    int r = rand();
    if (MillerRabin(r, 2)) return r;
  }
}
/*
Process is as follows:
1) assign private keys
2) determine public keys
3) use opposite public key and own private key to find common private message
*/
// O(4 * log n)
int genKey() {
  // srand(time(NULL));
  // Generate random numbers
  int p = RandomPrime();
  int g = RandomPrime();
  if (g > p) {  // We want p to be larger
    int temp = g;
    g = p;
    p = temp;
  }
  // Want to randomly generate numbers for private keys
  Person* Alice = new Person(rand());
  Person* Bob = new Person(rand());
  // Print just for sanity check
  int A_Private = Alice->printKey();
  // cout << "Alice Private Key: " << A_Private << "\n";
  int B_Private = Bob->printKey();
  // cout << "Bob Private Key: " << B_Private << "\n";
  Alice->findPublicKey(p, g);
  // cout << "Alice Public Key: " << Alice.publicKey << "\n";
  Bob->findPublicKey(p, g);
  // cout << "Bob Public Key: " << Bob.publicKey << "\n";
  Alice->findMessage(Bob->publicKey, p);
  int A_Message = Alice->printMessage();
  // cout << "Alice Message: " << A_Message << "\n";
  Bob->findMessage(Alice->publicKey, p);
  int B_Message = Bob->printMessage();
  // cout << "Bob Message: " << B_Message << "\n";

  // Check to make sure both are the same
  if (A_Message == B_Message) {
    delete Alice;
    delete Bob;
    return A_Message;
  } else
    throw("Something went wrong");
}