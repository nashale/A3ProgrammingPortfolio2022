#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Box {
   public:
      double length;         // Length of a box
      double breadth;        // Breadth of a box
      double height;         // Height of a box

      // Member functions declaration
      double getVolume(void);
      double getSurfaceArea(void);
      void setLength( double len );
      void setBreadth( double bre );
      void setHeight( double hei );
};

class Pyramid {
   public:
      double length;         // Length of a box
      double breadth;        // Breadth of a box
      double height;         // Height of a box

      // Member functions declaration
      double getVolume(void);
      double getSurfaceArea(void);
      void setLength( double len );
      void setBreadth( double bre );
      void setHeight( double hei );
};

class Sphere {
   public:
      double radius;         // Length of a box

      // Member functions declaration
      double getVolume(void);
      double getSurfaceArea(void);
      void setRadius( double rad );
};

// Member functions definitions
double Box::getVolume(void) {
   return length * breadth * height;
}

double Box::getSurfaceArea(void) {
  return (length * breadth*2) + (breadth * height * 2) + (length * height * 2);
}

double Pyramid::getVolume(void) {
   return ((length * breadth * height)/3);
}

double Pyramid::getSurfaceArea(void) {
  return (length*breadth)+ (length * (sqrt(((breadth/2)*(breadth/2))+(height * height)))) + (breadth*(sqrt((length/2)*(length/2) + (height * height))));
}

double Sphere::getVolume(void) {
   return (1.333333333333)*(M_PI)*(radius*radius*radius);
}

double Sphere::getSurfaceArea(void) {
  return 4*M_PI*(radius*radius);
}

void Sphere::setRadius(double rad) {
  radius = rad;
}

void Box::setLength( double len ) {
   length = len;
}
void Box::setBreadth( double bre ) {
   breadth = bre;
}
void Box::setHeight( double hei ) {
   height = hei;
}

void Pyramid::setLength( double len ) {
   length = len;
}
void Pyramid::setBreadth( double bre ) {
   breadth = bre;
}
void Pyramid::setHeight( double hei ) {
   height = hei;
}

// Main function for the program
int main() {
   Box Box1;
  Sphere Sphere1;
  Pyramid Pyramid1;
   double volume = 0.0; // Store the volume of a box here
  double surfaceArea = 0.0;
  double in, in2, in3, in4;
  string set;
  
   // volume of box
  cout << "Welcome to shape Maker! Lets find the volume and surface area for a few shapes...\n To build a box type box, to build a sphere type sphere, and to build a Pyramid type pyramid: " <<endl;
  cin >> set;
  if (set == "box") {
    cout << "Great! Let's start with a box. Please enter the length of a box: \n" <<endl;
    cin >> in2;
    cout << "Please enter the height of a box: \n" <<endl;
    cin >> in3;
    cout << "Please enter the breadth of a box: \n" <<endl;
    cin >> in4;
    Box1.setLength(in2); 
    Box1.setBreadth(in4); 
    Box1.setHeight(in3);
    volume = Box1.getVolume();
    surfaceArea = Box1.getSurfaceArea();
    cout << "The volume for your box: " << volume << "\nThe surface area for your box: " << surfaceArea << endl;
  } else if (set == "sphere") {
    cout << "Great! Let's start with a sphere. Please enter the radius of a sphere: \n" <<endl;
    cin >> in2;
    Sphere1.setRadius(in2); 
    volume = Sphere1.getVolume();
    surfaceArea = Sphere1.getSurfaceArea();
    cout << "The volume for your sphere: " << volume << "\nThe surface area for your sphere: " << surfaceArea << endl;
  } else if (set == "pyramid") {
    cout << "Great! Let's start with a pyramid. Please enter the length of a pyramid: \n" <<endl;
    cin >> in2;
    cout << "Please enter the height of a pyramid: \n" <<endl;
    cin >> in3;
    cout << "Please enter the breadth of a pyramid: \n" <<endl;
    cin >> in4;
    Pyramid1.setLength(in2); 
    Pyramid1.setBreadth(in4); 
    Pyramid1.setHeight(in3);
    volume = Pyramid1.getVolume();
    surfaceArea = Pyramid1.getSurfaceArea();
    cout << "The volume for your pyramid: " << volume << "\nThe surface area for your pyramid: " << surfaceArea << endl;
  }

   return 0;
}