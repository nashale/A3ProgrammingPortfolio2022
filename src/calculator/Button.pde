class Button {
  // Member variables
  int x, y, w, h;
  char val;
  color c1, c2;
  boolean on;

  // Constructor
  Button(int x, int y, int w, int h, char val) {
    this.x = x;
    this.y = y;
    this.w = w;
    this.h = h;
    this.val = val;

    c1 = color(145);
    c2 = color(125);
    on = false;
  }

  void display() {
    if (on) {
      fill(c2);
    } else {
      fill(c1);
    }

    noStroke();
    rectMode(CENTER);
    rect(x, y, w, h, 5);
    fill(0);
    textSize(20);

    if (val == 'C') {
      textSize(15);
      text("clear", x-10, y+22);
    } else if (val == '=') {
      textSize(15);
      text("enter", x, y+57);
    } else if (val == 's') {
      text("x²", x, y+5);
    } else if (val == 'r') {
      text("√", x, y+5);
    } else if (val == 'q') {
      text("π", x, y+2);
    } else if (val == 't') {
      text("%", x, y+5);
    } else {
      textAlign(CENTER);
      text(val, x, y+10);
    }
  }

  void hover(int mx, int my) {
    on = (mx > x-w/2 && mx < x+w/2 && my > y-h/2 && my < y+h/2);
  }
}
