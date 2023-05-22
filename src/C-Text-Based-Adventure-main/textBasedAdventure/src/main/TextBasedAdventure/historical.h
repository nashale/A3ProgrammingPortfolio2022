#include <fstream>
#include <iostream>

class Historical {
public:
  int f;
  int h;
  int v = 0;
  int mb;
  void enter(); // used at the beginning of the game, when the Victorian theme
                // is selected
  void moveTo(int m); // given choices of where to move at user's current time
  void moveBack();    // Just like moveTo
  void talk();        // talk to the king
  void help();
  void pickUp();
  void use();
};
