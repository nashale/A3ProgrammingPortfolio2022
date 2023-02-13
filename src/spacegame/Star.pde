class Star {
  int x, y, diam, speed;
  PImage star;

  // Constructor
  Star() {
    x = int(random(width));
    y = int(random(height));
    diam = int(random(1, 4));
    speed = int(random(1, 4));
    star = loadImage("star.png");
  }

  void display() {
    //rock.resize(diam,diam);
    imageMode(CENTER);
    image(star, x, y);
  }

  void move() {
    if (y>height+5) {
      y = -5;
    } else {
      y += speed;
    }
  }

  boolean reachedBottom() {
    return true;
  }
}
