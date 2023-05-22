#include "victorian.h"
#include <fstream>
#include <iostream>

void Victorian::enter() {
  // Input a victorian theme script to get information and choices from
}

void Victorian::moveTo(int m) {
  // set variable to greater to move forward in script

  dagger = false;
  key = false;

  if (v > 4 && v < 7) {
    v += 1;
    h = 2;
    v += m;
    m += 1;
  } else if (v == 7) {
    v += 2;
    v += m;
    m +=2;
  } else if (v ==11 || v == 12) {
    v+=m;
  } else {
    v += m;
  }

  mb = m;
}
void Victorian::moveBack() {
  if ((v >= 4 && v <= 5) || (v <=13 && v>=12)) {
    mb = 1;
  } else if ((v >= 6 && v < 8) || (v > 9 && v < 10)) {
    mb = 2;
  } else if (v == 9) {
    mb = 1;
  } else if (v == 8) {
    mb = 3;
  } else if (v == 10) {
    mb =3;
  }
  v -= mb;
}
void Victorian::help() {
  mb = 14 - v;
  v = 14;
}
void Victorian::use() {
  // Use an item in the user's inventory
}
void Victorian::pickUp() {
  // User interacts or picks up an item that is available
}
