class PowerUp {
  int x, y, diam, speed;
  char type;

  // Constructor
  PowerUp() {
    x = int(random(width));
    y = -50;
    diam = int(random(35, 50));
    speed = int(random(2, 12));
    int rand = int(random(3));
    if (rand == 0) {
      type = 'A';
    } else if (rand == 1) {
      type = 'H';
    } else {
      type = 'T';
    }
    //rock = loadImage("rock4.png");
  }

  void display() {
    fill(random(255),random(255),random(255));
    rect(x,y,diam,diam, 10);
    fill(0);
    textSize(22);
    text(type, x, y);
    //rock.resize(diam, diam);
    //imageMode(CENTER);
    //image(rock, x, y);
  }

  void move() {
    y += speed;
  }

  boolean reachedBottom() {
    if (y>height+100) {
      return true;
    } else {
      return false;
    }
  }

  boolean intersect(SpaceShip ship) {
    float d = dist(x, y, ship.x, ship.y);
    if (d<30) {
      return true;
    } else {
      return false;
    }
  }
}
