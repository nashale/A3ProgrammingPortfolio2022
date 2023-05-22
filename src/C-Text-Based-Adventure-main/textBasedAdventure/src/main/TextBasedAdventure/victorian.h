#include <fstream>
#include <iostream>

class Victorian {
public:
  int v;
  int h;
int l;
  bool key, dagger;
  int mb;
int b;
  void enter(); // used at the beginning of the game, when the Victorian theme
                // is selected
  void moveTo(int m); // given choices of where to move at user's current time
  void moveBack();    // Just like moveTo
  void help();        // talk to the king
  void use();
  void pickUp();

};
