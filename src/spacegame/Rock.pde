class Rock {
  int x, y, diam, speed;
  PImage rock, rock2;

  // Constructor
  Rock() {
    x = int(random(width));
    y = -50;
    diam = int(random(50, 80));
    speed = int(random(2, 12));
    rock = loadImage("rock4.png");
  }

  void display() {
    rock.resize(diam, diam);
    imageMode(CENTER);
    image(rock, x, y);
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

  //boolean intersect(Laser laser) {
  //  float d = dist(x, y, laser.x, laser.y);
  //  if (d<50) {
  //    return true;
  //  } else {
  //    return false;
  //  }
  //}
}
