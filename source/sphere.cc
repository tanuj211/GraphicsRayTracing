#include "raycast.h"

// Add any code you need here and in the corresponding header
// file.


Sphere::Sphere()
{

}



Sphere::Sphere(Vec3f centre, float radius, Vec3f color) {
  this->_centre = centre;
  this->_radius = radius;
  this->_color = color;
}


bool Sphere::intersect(const Ray &r, Hit &h) {
  Vec3f d = r->getDirection();
  Vec3f p0 = r->getOrigin();
  Vec3f ps = this->_centre;
  deltaP = p0 - ps;
  float r = this->_radius;
  float dDotDeltaP = d.Dot3(deltaP);
  float modDeltaP = deltaP.Length();

  float discriminant = pow(dDotDeltaP, 2) - pow(modDeltaP, 2) + pow(r,2);
  float shortest = 0;
  if (discriminant >= 0) {
    float mew1 = -(dDotDeltaP) + sqrt(discriminant);
    Vec3f solution1 = r.pointAtParameter(mew1);
    shortest = solution1.Length();
    if (discriminant > 0) {
      float mew2 = -(dDotDeltaP) - sqrt(discriminant);
      Vec3f solution2 = r.pointAtParameter(mew2);
      if (solution2.Length() < shortest) {
        shortest = solution2.Length();
      }
    }
    if(h->getT > shortest) {
      h->set(shortest, this->color);
    }
    return true;
  } else {
    return false;
  }
}
