#include "futuristic.h"
#include <fstream>
#include <iostream>

void Futuristic::moveTo(int m) {
  // set variable to greater to move forward in script

  if (v == 7 ) {
    m+=1;
    v += m;
  } else if (v == 4 || v == 6 || v == 8 || v == 9 || v == 10 || v == 11) {
    v += m;
  } else { 
    v += m;
  }
  mb = m;
}
void Futuristic::moveBack() { v -= mb; }
void Futuristic::help() {
  mb = 14 - v;
  v = 14;
}

void Futuristic::pickUp() {
  // User interacts or picks up an item that is available
}
