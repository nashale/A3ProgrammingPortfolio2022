class Laser {
  int x, y, w, h, speed;
  color c1;
  //PImage laser;

  // Constructor
  Laser(int x, int y) {
    this.x = x;
    this.y = y;
    w = 4;
    h = 12;
    speed = 10;
    c1 = color(#FC00B1);
    //laser = loadImage("laser.png");
  }

  void display() {
    noStroke();
    fill(c1);
    rect(x, y, w, h);
  }

  void move() {
    y -= speed;
  }

  boolean reachedTop() {
    if (y<-50) {
      return true;
    } else {
      return false;
    }
  }

  boolean intersect(Rock rock) {
    float d = dist(x, y, rock.x, rock.y);
    if (d<50) {
      return true;
    } else {
      return false;
    }
  }
}
