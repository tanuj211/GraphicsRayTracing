// Orthographic camera class.

// Add any code you need here and in the corresponding .cc file.

#ifndef ORTHOGRAPHIC_CAMERA_H_
#define ORTHOGRAPHIC_CAMERA_H_

#include "raycast.h"

class OrthographicCamera : public Camera{
	Vec3f _centre;
	Vec3f _direction;
	Vec3f _up;
	Vec3f _horizontal;
	float size;

public:

  // Constructor.
  OrthographicCamera(Vec3f centre, Vec3f direction, Vec3f up, float size);

  // Concrete implementation of pure virtual function in the
  // parent class.
  virtual Ray generateRay(Vec2f point);

};

#endif /* ORTHOGRAPHIC_CAMERA_H_ */
