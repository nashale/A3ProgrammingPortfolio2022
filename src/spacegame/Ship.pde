class SpaceShip {
  int x, y, w, ammo, turretCount, health;
  PImage ship;

  // Constructor
  SpaceShip() {
    x = mouseX;
    y = mouseY;
    w = 90;
    ammo = 1000;
    turretCount = 1;
    health = 100;
    ship = loadImage("ship3.png");
  }

  void display() {
    imageMode(CENTER);
    ship.resize(100, 100);
    noCursor();
    image(ship, x, y);
  }

  void move(int tempx, int tempy) {
    x = tempx;
    y = tempy;
  }

  boolean fire() {
    if (ammo>0) {
      ammo--;
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
