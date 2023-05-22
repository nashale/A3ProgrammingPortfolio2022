#include "historical.h"
#include <fstream>
#include <iostream>

void Historical::moveTo(int m) {
  // set variable to greater to move forward in script
if ((v >=2 && v<= 4) || (v == 7) || (v == 9)){
  m += 1;
}
  v += m;
  mb = m;
}
void Historical::moveBack() { v -= mb; }
void Historical::help() {
  mb = 12 - v;
  v = 12;
}

void Historical::pickUp() {
  // User interacts or picks up an item that is available
}
