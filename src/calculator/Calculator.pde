// Nash Hale | Nov 2022 | Calculator Project
Button[] numButtons = new Button[10];
Button[] opButtons = new Button[12];
String dVal = "0";
boolean left = true;
float l, r, result;
char op = ' ';


void setup() {
  size(370, 600);
  numButtons[0] = new Button(150, 560, 130, 60, '0');
  numButtons[1] = new Button(115, 490, 60, 60, '1');
  numButtons[2] = new Button(185, 490, 60, 60, '2');
  numButtons[3] = new Button(255, 490, 60, 60, '3');
  numButtons[4] = new Button(115, 420, 60, 60, '4');
  numButtons[5] = new Button(185, 420, 60, 60, '5');
  numButtons[6] = new Button(255, 420, 60, 60, '6');
  numButtons[7] = new Button(115, 350, 60, 60, '7');
  numButtons[8] = new Button(185, 350, 60, 60, '8');
  numButtons[9] = new Button(255, 350, 60, 60, '9');
  opButtons[0] = new Button(42, 560, 60, 60, 'q');
  opButtons[1] = new Button(42, 490, 60, 60, 'r');
  opButtons[2] = new Button(42, 420, 60, 60, 's');
  opButtons[3] = new Button(42, 350, 60, 60, 't');
  opButtons[4] = new Button(42, 280, 60, 60, 'C');
  opButtons[5] = new Button(115, 280, 60, 60, '±');
  opButtons[6] = new Button(185, 280, 60, 60, '÷');
  opButtons[7] = new Button(255, 280, 60, 60, '*');
  opButtons[8] = new Button(325, 280, 60, 60, '-');
  opButtons[9] = new Button(325, 385, 60, 130, '+');
  opButtons[10] = new Button(325, 525, 60, 130, '=');
  opButtons[11] = new Button(255, 560, 60, 60, '.');
}

void draw() {
  background(178);
  for (int i=0; i<numButtons.length; i++) {
    numButtons[i].display();
    numButtons[i].hover(mouseX, mouseY);
  }
  for (int i=0; i<opButtons.length; i++) {
    opButtons[i].display();
    opButtons[i].hover(mouseX, mouseY);
  }
  updateDisplay();
}

void keyPressed() {
  println("key:" + key);
  println("keyCode:" + keyCode);
  if (keyCode == 49 || keyCode == 97) {
    handleEvent("1", true);
  } else if (keyCode == 12) {
    handleEvent("C", false);
  } else if (keyCode == 8) {
    handleEvent("C", false);
  } else if (keyCode == 46 || keyCode == 110) {
    handleEvent(".", false);
  } else if (keyCode == 50 || keyCode == 98) {
    handleEvent("2", true);
  } else if (keyCode == 51 || keyCode == 99) {
    handleEvent("3", true);
  } else if (keyCode == 52 || keyCode == 100) {
    handleEvent("4", true);
  } else if (keyCode == 53 || keyCode == 101) {
    handleEvent("5", true);
  } else if (keyCode == 54 || keyCode == 102) {
    handleEvent("6", true);
  } else if (keyCode == 55 || keyCode == 103) {
    handleEvent("7", true);
  } else if (keyCode == 56 || keyCode == 104) {
    handleEvent("8", true);
  } else if (keyCode == 57 || keyCode == 105) {
    handleEvent("9", true);
  } else if (keyCode == 48 || keyCode == 96) {
    handleEvent("0", true);
  } else if (keyCode == 107) {
    handleEvent("+", false);
  } else if (keyCode == 10) {
    handleEvent("=", false);
  } else if (keyCode == 106) {
    handleEvent("*", false);
  } else if (keyCode == 109 || keyCode == 45) {
    handleEvent("-", false);
  } else if (keyCode == 111 || keyCode == 47) {
    handleEvent("÷", false);
  }
}

void handleEvent(String val, boolean num) {
  if (num && dVal.length() < 21) {
    if (dVal.equals("0")) {
      dVal = val;
    } else {
      dVal += val;
    }
    if (left) {
      l = float(dVal);
    } else {
      r = float(dVal);
    }
  } else if (val.equals("C")) {
    dVal = "0";
    left = true;
    l = 0;
    r = 0;
    result = 0;
    op = ' ';
  } else if (val.equals(".")) {
    if (!dVal.contains(".")) {
      dVal += ".";
    }
  } else if (val.equals("+")) {
    op = '+';
    dVal = "0";
    left = false;
  } else if (val.equals("=")) {
    performCalculation();
  } else if (val.equals("-")) {
    op = '-';
    dVal = "0";
    left = false;
  } else if (val.equals("*")) {
    op = '*';
    dVal = "0";
    left = false;
  } else if (val.equals("÷")) {
    op = '÷';
    dVal = "0";
    left = false;
  }
}

void mouseReleased() {
  for (int i=0; i<numButtons.length; i++) {
    if (numButtons[i].on) {
      handleEvent(str(numButtons[i].val), true);
    }
  }

  for (int i=0; i<opButtons.length; i++) {
    if (opButtons[i].on && opButtons[i].val == 'C') {
      handleEvent(str(opButtons[i].val), false);
    } else if (opButtons[i].on && opButtons[i].val == '+') {
      handleEvent("+",false);
    } else if (opButtons[i].on && opButtons[i].val == '-') {
      handleEvent("-",false);
    } else if (opButtons[i].on && opButtons[i].val == '÷') {
      handleEvent("÷",false);
    } else if (opButtons[i].on && opButtons[i].val == '*') {
      handleEvent("*",false);
    } else if (opButtons[i].on && opButtons[i].val == '±') {
      if (left) {
        l = l*-1;
        dVal = str(l);
      } else {
        r = r*-1;
        dVal = str(r);
      }
    } else if (opButtons[i].on && opButtons[i].val == '=') {
      performCalculation();
    } else if (opButtons[i].on && opButtons[i].val == 's') {
      if (left) {
        l = sq(l);
        dVal = str(l);
      } else {
        r = sq(r);
        dVal = str(r);
      }
    } else if (opButtons[i].on && opButtons[i].val == 'r') {
      if (left) {
        l = sqrt(l);
        dVal = str(l);
      } else {
        r = sqrt(r);
        dVal = str(r);
      }
    } else if (opButtons[i].on && opButtons[i].val == 'q') {
      if (left) {
        l = PI;
        dVal = str(l);
      } else {
        r = PI;
        dVal = str(r);
      }
    } else if (opButtons[i].on && opButtons[i].val == 't') {
      op = 't';
      performCalculation();
    } else if (opButtons[i].on && opButtons[i].val == '.') {
      handleEvent(".", false);
    }
  }
  println("l:" + l + " r:" + r + " op:" + op + " result:" + result + " left:" + left);
}

void updateDisplay() {
  fill(100);
  rectMode(CORNER);
  rect(12, 18, width-28, 215, 8);
  fill(255);
  textAlign(RIGHT);
  textSize(45);
  if (dVal.length() < 10) {
    textSize(45);
  } else if (dVal.length() < 11) {
    textSize(43);
  } else if (dVal.length() < 12) {
    textSize(41);
  } else if (dVal.length() < 13) {
    textSize(39);
  } else if (dVal.length() < 14) {
    textSize(37);
  } else if (dVal.length() < 15) {
    textSize(35);
  } else if (dVal.length() < 16) {
    textSize(33);
  } else if (dVal.length() < 17) {
    textSize(31);
  } else if (dVal.length() < 18) {
    textSize(29);
  } else if (dVal.length() < 19) {
    textSize(27);
  } else if (dVal.length() < 20) {
    textSize(25);
  } else if (dVal.length() < 21) {
    textSize(23);
  } else if (dVal.length() < 22) {
    textSize(21);
  } else if (dVal.length() < 23) {
    textSize(19);
  } else {
    textSize(17);
  }
  text(dVal, width-50, 200);
}

void performCalculation() {
  if (op == '+') {
    result = l + r;
  } else if (op == '-') {
    result = l - r;
  } else if (op == '*') {
    result = l * r;
  } else if (op == '÷') {
    result = l / r;
  } else if (op =='t') {
    result = l / 100;
  }
  dVal = str(result);
  l = result;
  left = true;
}
