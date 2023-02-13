// Nash Hale | 28 Nov 2022 | SpaceGame
import processing.sound.*;
SoundFile laser, explosion, pickupPowerUP;
SpaceShip s1;
Timer rockTimer, laserTimer, powerUpTimer, rockTimerLevel2, rockTimerLevel3, rockTimerLevel4;
ArrayList<Rock> rocks = new ArrayList<Rock>();
ArrayList<PowerUp> powerUps = new ArrayList<PowerUp>();
ArrayList<Laser> lasers = new ArrayList<Laser>();
Star[] stars = new Star[100];
int score, level, rockCount, rocksPassed, ammo, dmg;
boolean play;

void setup() {
  size(800, 800);
  laser = new SoundFile(this, "laser.wav");
  explosion = new SoundFile(this, "explode.wav");
  pickupPowerUP = new SoundFile(this, "powerup.wav");
  s1 = new SpaceShip();
  rockTimer = new Timer(800);
  rockTimer.start();
  rockTimerLevel2 = new Timer(600);
  rockTimerLevel2.start();
  rockTimerLevel3 = new Timer(500);
  rockTimerLevel3.start();
  rockTimerLevel4 = new Timer(250);
  rockTimerLevel4.start();
  laserTimer = new Timer(150);
  laserTimer.start();
  powerUpTimer = new Timer(10000);
  powerUpTimer.start();
  for (int i = 0; i<stars.length; i++) {
    stars[i] = new Star();
  }
  score = 0;
  level = 1;
  rockCount = 0;
  play = false;
  dmg = 85;
  rocksPassed = 0;
}

void draw() {
  if (!play) {
    startScreen();
  } else {
    background(0);

    // Rendering Stars
    for (int i= 0; i<stars.length; i++) {
      stars[i].display();
      stars[i].move();
    }
    infoPanel();
    noCursor();

    // Distributing PowerUps
    if (powerUpTimer.isFinished()) {
      powerUps.add(new PowerUp());
      powerUpTimer.start();
    }

    // Distributing Rocks
    if (rockTimer.isFinished()) {
      rocks.add(new Rock());
      rockTimer.start();
      println("Rocks Size: " + rocks.size());
    }

    // Rendering PowerUps and Detecting Ship Collision
    for (int i = 0; i < powerUps.size(); i++) {
      PowerUp pu = powerUps.get(i);
      if (pu.intersect(s1)) {
        if (pu.type == 'H' && s1.health<100) {
          s1.health+=100;
        } else if (pu.type == 'A') {
          s1.ammo+=250;
        } else if (pu.type == 'T' && s1.turretCount<6) {
          s1.turretCount++;
        }
        // todo: add sound
        // todo: add animation
        // todo: visual effect on the ship
        pickupPowerUP.stop();
        pickupPowerUP.play();
        powerUps.remove(pu);
      }
      if (pu.reachedBottom()) {
        powerUps.remove(pu);
      } else {
        pu.display();
        pu.move();
      }
    }

    // Rendering Rocks and Detecting Ship Collision
    for (int i = 0; i < rocks.size(); i++) {
      Rock r = rocks.get(i);
      if (s1.intersect(r)) {
        s1.health -= 10;
        if (score>0) {
          score-=10;
        } else if (score<=0) {
          score+=0;
        }
        // todo: add sound of explosion
        // todo: add animation of explosion
        // todo: visual effect on the ship
        rocks.remove(r);
      }
      if (r.reachedBottom()) {
        rocks.remove(r);
        rocksPassed++;
      } else {
        r.display();
        r.move();
      }
    }

    // Laser render
    for (int j = 0; j < rocks.size(); j++) {
      Rock r = rocks.get(j);
      for (int m = 0; m < lasers.size(); m++) {
        Laser l = lasers.get(m);
        if (l.intersect(r)) {
          // Todo: add sound to collision
          // Todo: add animation of explosion
          explosion.stop();
          explosion.play();
          lasers.remove(l);
          r.diam -= 50;
          if (r.diam<20) {
            rocks.remove(r);
          }
          score+=10;
        }
      }
    }

    for (int i = 0; i < lasers.size(); i++) {
      Laser l = lasers.get(i);
      if (l.reachedTop()) {
        lasers.remove(l);
        println("Laser Size: " + lasers.size());
      } else {
        l.display();
        l.move();
      }
    }

    // Render Spaceship
    s1.display();
    s1.move(mouseX, mouseY);

    if (s1.health<1 || rocksPassed > 14) {
      gameOver();
    }

    if (score<=250) {
      level = 1;
      if (rockTimer.isFinished()) {
        rocks.add(new Rock());
        rockTimer.start();
        //println("Rocks Size: " + rocks.size());
      }
    } else if (score <=500) {
      level = 2;
      if (rockTimerLevel2.isFinished() && level == 2) {
        rocks.add(new Rock());
        rockTimerLevel2.start();
        println("Rock timer is set to level 2" + rockTimer);
      }
    } else if (score<=750) {
      level = 3;
      if (rockTimerLevel3.isFinished() && level == 3) {
        rocks.add(new Rock());
        rockTimerLevel3.start();
        println("Rock timer is set to level 2" + rockTimer);
      }
    } else if (score>1000) {
      level = 4;
      if (rockTimerLevel4.isFinished() && level == 4) {
        rocks.add(new Rock());
        rockTimerLevel4.start();
        println("Rock timer is set to level 2" + rockTimer);
      }
    }
  }
}

// Add Laser based on event
void mouseReleased() {
  if (play) {
    laser.stop();
    laser.play();
    if (laserTimer.isFinished()) {
      handleEvent();
    }
  }
}

void handleEvent() {
  if (s1.fire() && s1.turretCount == 1) {
    lasers.add(new Laser(s1.x, s1.y));
    println("Laser Size:" + lasers.size());
  } else if (s1.fire() && s1.turretCount == 2) {
    lasers.add(new Laser(s1.x-20, s1.y));
    lasers.add(new Laser(s1.x+20, s1.y));
  } else if (s1.fire() && s1.turretCount == 3) {
    lasers.add(new Laser(s1.x-20, s1.y));
    lasers.add(new Laser(s1.x, s1.y));
    lasers.add(new Laser(s1.x+20, s1.y));
  } else if (s1.fire() && s1.turretCount == 4) {
    lasers.add(new Laser(s1.x-20, s1.y));
    lasers.add(new Laser(s1.x-10, s1.y));
    lasers.add(new Laser(s1.x+10, s1.y));
    lasers.add(new Laser(s1.x+20, s1.y));
  } else if (s1.fire() && s1.turretCount == 5) {
    lasers.add(new Laser(s1.x-20, s1.y));
    lasers.add(new Laser(s1.x-10, s1.y));
    lasers.add(new Laser(s1.x, s1.y));
    lasers.add(new Laser(s1.x+10, s1.y));
    lasers.add(new Laser(s1.x+20, s1.y));
  }
}
void keyReleased() {
  if (key == ' ') {
    if (play) {
      laser.stop();
      laser.play();
      if (laserTimer.isFinished()) {
        handleEvent();
      }
    }
  }
}
void infoPanel() {
  fill(128, 127);
  rectMode(CENTER);
  rect(width/2, 25, width, 50);
  fill(#FFDA03);
  textSize(28);
  textAlign(CENTER);
  text("Level: " + level + " | Health: " + s1.health + " | Rocks Passed " + rocksPassed + " | Score: " + score + " | Ammo: " + s1.ammo, width/2, 40);
}

void startScreen () {
  background(0);
  fill(255);
  textAlign(CENTER);
  textSize(30);
  text("Click or press any key to start...", width/2, height/2);
  if (mousePressed || keyPressed) {
    play = true;
  }
}

void gameOver() {
  background(0);
  fill(255);
  textAlign(CENTER);
  textSize(30);
  text("Game Over!" + "\n Score: " + score + "\n Highest Level Reached: " + level, width/2, height/2);
  play = false;
  noLoop();
}
