#include <iostream>
#include <unordered_map>
using namespace std;
class Hashtable_htoc {
  unordered_map<int, char> hmap;

 public:
  void put(int key, char value) {  // place, search for dupes. O(n)
    for (auto it : hmap) {
      if (it.first == key) {  // if collision,
        cout << "Key/value pair exists already. Replacing...\n";  // replace it
        // return; or exit function
      }
    }
    hmap[key] = value;
  }

  char get(int key) {  // search. O(n)
    bool found = false;
    for (auto it : hmap) {
      if (it.first == key) {  // if collision,
        found = true;
      }
    }
    if (!found) {
      cout << "Item not found.\n";
      return 0;
    }
    return hmap[key];
  }

  void remove(int key) {  // remove. O(n)
    bool found = false;
    for (auto it : hmap) {
      if (it.first == key) {  // if collision,
        hmap.erase(key);      // erase
        found = true;
        break;
      }
    }
    if (!found) {
      cout << "Item not found. Cannot Erase.\n";
    }
  }

  void fillTable() {
    (*this).put(0x00, ' ');  // Space needs to be 0!!
    (*this).put(0x01, 'a');
    (*this).put(0x02, 'b');
    (*this).put(0x03, 'c');
    (*this).put(0x04, 'd');
    (*this).put(0x05, 'e');
    (*this).put(0x06, 'f');
    (*this).put(0x07, 'g');
    (*this).put(0x08, 'h');
    (*this).put(0x09, 'i');
    (*this).put(0x0a, 'j');
    (*this).put(0x0b, 'k');
    (*this).put(0x0c, 'l');
    (*this).put(0x0d, 'm');
    (*this).put(0x0e, 'n');
    (*this).put(0x0f, 'o');
    (*this).put(0x10, 'p');
    (*this).put(0x11, 'q');
    (*this).put(0x12, 'r');
    (*this).put(0x13, 's');
    (*this).put(0x14, 't');
    (*this).put(0x15, 'u');
    (*this).put(0x16, 'v');
    (*this).put(0x17, 'w');
    (*this).put(0x18, 'x');
    (*this).put(0x19, 'y');
    (*this).put(0x1a, 'z');
    //-----Capitals
    (*this).put(0x1b, 'A');
    (*this).put(0x1c, 'B');
    (*this).put(0x1d, 'C');
    (*this).put(0x1e, 'D');
    (*this).put(0x1f, 'E');
    (*this).put(0x20, 'F');
    (*this).put(0x21, 'G');
    (*this).put(0x22, 'H');
    (*this).put(0x23, 'I');
    (*this).put(0x24, 'J');
    (*this).put(0x25, 'K');
    (*this).put(0x26, 'L');
    (*this).put(0x27, 'M');
    (*this).put(0x28, 'N');
    (*this).put(0x29, 'O');
    (*this).put(0x2a, 'P');
    (*this).put(0x2b, 'Q');
    (*this).put(0x2c, 'R');
    (*this).put(0x2d, 'S');
    (*this).put(0x2e, 'T');
    (*this).put(0x2f, 'U');
    (*this).put(0x30, 'V');
    (*this).put(0x31, 'W');
    (*this).put(0x32, 'X');
    (*this).put(0x33, 'Y');
    (*this).put(0x34, 'Z');
    //---Digits
    (*this).put(0x35, '0');
    (*this).put(0x36, '1');
    (*this).put(0x37, '2');
    (*this).put(0x38, '3');
    (*this).put(0x39, '4');
    (*this).put(0x3a, '5');
    (*this).put(0x3b, '6');
    (*this).put(0x3c, '7');
    (*this).put(0x3d, '8');
    (*this).put(0x3e, '9');
    // Special characters
    (*this).put(0x3f, '!');
    (*this).put(0x40, '?');
    (*this).put(0x41, '"');
    (*this).put(0x42, '#');
    (*this).put(0x43, '%');
    (*this).put(0x44, '@');
    (*this).put(0x45, '^');
    (*this).put(0x46, '&');
    (*this).put(0x47, '*');
    (*this).put(0x48, '(');
    (*this).put(0x49, ')');
    (*this).put(0x4a, '+');
    (*this).put(0x4b, '-');
    (*this).put(0x4c, '/');
    (*this).put(0x4d, '=');
    (*this).put(0x4e, '[');
    (*this).put(0x4f, ']');
    (*this).put(0x50, '{');
    (*this).put(0x51, '}');
    (*this).put(0x52, '|');
    (*this).put(0x53, '~');
    (*this).put(0x54, '`');
    (*this).put(0x55, '$');
    (*this).put(0x56, '<');
    (*this).put(0x57, '>');
    (*this).put(0x58, ',');
    (*this).put(0x59, '.');
    (*this).put(0x5a, ':');
    (*this).put(0x5b, ';');
    (*this).put(0x5c, '\'');
    (*this).put(0x5d, '\\');
    (*this).put(0x5e, '\n');
    (*this).put(0x5f, '\t');
    (*this).put(0x60, '_');
  }
};

class Hashtable_ctoh {
  unordered_map<char, int> hmap;

 public:
  void put(char key, int value) {  // place, search for dupes. O(n)
    for (auto it : hmap) {
      if (it.first == key) {  // if collision,
        cout << "Key/value pair exists already. Replacing...\n";  // replace it
        // return; or exit function
      }
    }
    hmap[key] = value;
  }

  unsigned int get(char key) {  // search. O(n)
    bool found = false;
    for (auto it : hmap) {
      if (it.first == key) {  // if collision,
        found = true;
      }
    }
    if (!found) {
      cout << "Item not found.\n";
      return 0;
    }
    return hmap[key];
  }

  void remove(char key) {  // remove. O(n)
    bool found = false;
    for (auto it : hmap) {
      if (it.first == key) {  // if collision,
        hmap.erase(key);      // erase
        found = true;
        break;
      }
    }
    if (!found) {
      cout << "Item not found. Cannot Erase.\n";
    }
  }

  void fillTable() {
    (*this).put(' ', 0x00);  // Space needs to be 0!!
    (*this).put('a', 0x01);
    (*this).put('b', 0x02);
    (*this).put('c', 0x03);
    (*this).put('d', 0x04);
    (*this).put('e', 0x05);
    (*this).put('f', 0x06);
    (*this).put('g', 0x07);
    (*this).put('h', 0x08);
    (*this).put('i', 0x09);
    (*this).put('j', 0x0a);
    (*this).put('k', 0x0b);
    (*this).put('l', 0x0c);
    (*this).put('m', 0x0d);
    (*this).put('n', 0x0e);
    (*this).put('o', 0x0f);
    (*this).put('p', 0x10);
    (*this).put('q', 0x11);
    (*this).put('r', 0x12);
    (*this).put('s', 0x13);
    (*this).put('t', 0x14);
    (*this).put('u', 0x15);
    (*this).put('v', 0x16);
    (*this).put('w', 0x17);
    (*this).put('x', 0x18);
    (*this).put('y', 0x19);
    (*this).put('z', 0x1a);
    //-----Capitals
    (*this).put('A', 0x1b);
    (*this).put('B', 0x1c);
    (*this).put('C', 0x1d);
    (*this).put('D', 0x1e);
    (*this).put('E', 0x1f);
    (*this).put('F', 0x20);
    (*this).put('G', 0x21);
    (*this).put('H', 0x22);
    (*this).put('I', 0x23);
    (*this).put('J', 0x24);
    (*this).put('K', 0x25);
    (*this).put('L', 0x26);
    (*this).put('M', 0x27);
    (*this).put('N', 0x28);
    (*this).put('O', 0x29);
    (*this).put('P', 0x2a);
    (*this).put('Q', 0x2b);
    (*this).put('R', 0x2c);
    (*this).put('S', 0x2d);
    (*this).put('T', 0x2e);
    (*this).put('U', 0x2f);
    (*this).put('V', 0x30);
    (*this).put('W', 0x31);
    (*this).put('X', 0x32);
    (*this).put('Y', 0x33);
    (*this).put('Z', 0x34);
    //---Digits
    (*this).put('0', 0x35);
    (*this).put('1', 0x36);
    (*this).put('2', 0x37);
    (*this).put('3', 0x38);
    (*this).put('4', 0x39);
    (*this).put('5', 0x3a);
    (*this).put('6', 0x3b);
    (*this).put('7', 0x3c);
    (*this).put('8', 0x3d);
    (*this).put('9', 0x3e);
    // Special characters
    (*this).put('!', 0x3f);
    (*this).put('?', 0x40);
    (*this).put('"', 0x41);
    (*this).put('#', 0x42);
    (*this).put('%', 0x43);
    (*this).put('@', 0x44);
    (*this).put('^', 0x45);
    (*this).put('&', 0x46);
    (*this).put('*', 0x47);
    (*this).put('(', 0x48);
    (*this).put(')', 0x49);
    (*this).put('+', 0x4a);
    (*this).put('-', 0x4b);
    (*this).put('/', 0x4c);
    (*this).put('=', 0x4d);
    (*this).put('[', 0x4e);
    (*this).put(']', 0x4f);
    (*this).put('{', 0x50);
    (*this).put('}', 0x51);
    (*this).put('|', 0x52);
    (*this).put('~', 0x53);
    (*this).put('`', 0x54);
    (*this).put('$', 0x55);
    (*this).put('<', 0x56);
    (*this).put('>', 0x57);
    (*this).put(',', 0x58);
    (*this).put('.', 0x59);
    (*this).put(':', 0x5a);
    (*this).put(';', 0x5b);
    (*this).put('\'', 0x5c);
    (*this).put('\\', 0x5d);
    (*this).put('\n', 0x5e);
    (*this).put('\t', 0x5f);
    (*this).put('_', 0x60);
  }
};