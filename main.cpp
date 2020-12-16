#include <time.h>

#include <fstream>
#include <iostream>
#include <string>

#include "DiffieHellman.cpp"
#include "hmap_final.cpp"
#include "implement_Rijndael.cpp"

#define size 32  // 32 8 bit values -> 32*8 = 256
using namespace std;

bool valid[10000][32] = {false};

void createKey() {
  for (int i = 0; i < size; i++) {
    int val = genKey();
    Key[i] = val;
  }
  printf("Key Generated\n");
}

// O(n/128) -> O(n) - 1 loop for every 128 input characters
void encryption(Hashtable_ctoh hash_ctoh, string encrypted_data) {
  string filename;
  unsigned char ch, letter;
  int round, counter = 0;

  printf("Enter name of file to encrypt: ");
  cin >> filename;
  printf("Reading input...\n");

  fstream input(filename);
  while (true) {
    input >> noskipws >> ch;  // we want to read white space
    if (input.eof()) {
      if (counter = 0)
        break;
      else {  // might reach end of file before counter reaches 16
        Expand_Keys();
        Encrypt();

        for (int i = 0; i < keyLength * blockSize; i++) {
          if (encrypted[i] == 0x1a) {  // 1a is EOF character, need to modify
            encrypted[i] += 1;         // set as 1b
            valid[round][i] = true;    // mark as modified
          }
          encrypted_data += encrypted[i];
        }
        break;
      }
    } else if (counter < 16) {  // Need to encrypt by 128 bit chunks
      int num = hash_ctoh.get(ch);
      plaintext[counter] = num;
      counter++;
    } else {
      // Expand_Keys before encryption
      Expand_Keys();
      Encrypt();

      for (int i = 0; i < keyLength * blockSize; i++) {
        if (encrypted[i] == 0x1a) {  // In case of EOF character
          encrypted[i] += 1;         // add 1 to avoid 1a
          valid[round][i] = true;    // mark as modifed
        }
        encrypted_data += encrypted[i];
      }
      // Finished Block
      round++;
      for (int i = 0; i < blockSize * 4; i++) {
        plaintext[i] = 0;
      }
      for (int i = 0; i < keyLength * blockSize; i++) {
        encrypted[i] = 0;
      }
      int num = hash_ctoh.get(ch);  // Need to start at beginning again
      plaintext[0] = num;
      counter = 1;
    }
  }
  ofstream output("encryptedData.txt");
  output << encrypted_data;
  output.close();
  printf("File written\n");
}

// O(n/128) -> O(n) - one loop for every 128 input characters
void decryption(Hashtable_htoc hash_htoc, string decrypted_data) {
  string filename;
  unsigned char ch, letter;
  int round, counter = 0;

  printf("Enter name of file to decrypt: ");
  cin >> filename;
  printf("Reading input...\n");

  fstream input(filename);
  while (true) {
    input >> noskipws >> ch;  // want to read whitespace
    if (input.eof()) {
      if (counter = 0)
        break;
      else {  // might reach end of file before counter reaches 16
        Expand_Keys();
        Decrypt();

        for (int i = 0; i < blockSize * 4; i++) {
          letter = hash_htoc.get(plaintext[i]);
          decrypted_data += letter;
        }
        break;
      }
    } else if (counter < keyLength * blockSize) {
      if (ch == 0x1b && valid[round][counter]) {  // check if modified
        ch--;
        encrypted[counter] = ch;
        counter++;
        valid[round][counter] = false;  // change back to unmodified
      } else {
        encrypted[counter] = ch;
        counter++;
      }
    } else {
      // Expand_Keys before encryption
      Expand_Keys();
      Decrypt();

      for (int i = 0; i < blockSize * 4; i++) {
        letter = hash_htoc.get(plaintext[i]);
        decrypted_data += letter;
      }
      // Finished Block
      round++;
      // need to reset back to beginning
      for (int i = 0; i < keyLength * blockSize; i++) {
        encrypted[i] = 0;
      }
      for (int i = 0; i < blockSize * 4; i++) {
        plaintext[i] = 0;
      }
      if (ch == 0x1b && valid[round][0]) {  // also check if modified for 1a
        ch--;
        encrypted[0] = ch;
        counter = 1;
        valid[round][0] = false;
      } else {
        encrypted[0] = ch;
        counter = 1;
      }
    }
  }
  ofstream output("decryptedData.txt");
  output << decrypted_data;
  output.close();
  printf("File written\n");
}

// Overall O(n), where n is # of characters in input file
int main() {
  string encrypted_data, decrypted_data;
  srand(time(NULL));

  Hashtable_ctoh hash_ctoh;  // char to hex
  hash_ctoh.fillTable();
  Hashtable_htoc hash_htoc;  // hex to char
  hash_htoc.fillTable();

  createKey();

  int input;
  bool run = true;

  while (run) {
    printf("\nPress 1 for encryption of file\n");
    printf("Press 2 for decryption of file\n");
    printf(
        "Press 3 to generate new key.. WARNING: make sure encrypted file was "
        "first "
        "decrypted!\n");
    printf("Press 4 to quit\n");

    cin >> input;

    switch (input) {
      case 1:
        encrypted_data = "";  // Need to empty string if used before
        encryption(hash_ctoh, encrypted_data);
        break;
      case 2:
        decrypted_data = "";  // Need to empty string if used before
        decryption(hash_htoc, decrypted_data);
        break;
      case 3:
        createKey();
        break;
      case 4:
        run = false;
        break;
      default:
        printf("Bad input\n");
        break;
    }
  }
  return 0;
}