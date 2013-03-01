#include "raycast.h"

// Add any code you need here and in the corresponding header
// file.


// Constructor with parameters.
OrthographicCamera::OrthographicCamera(Vec3f centre, Vec3f direction, Vec3f up, float size) {
	this->_direction = direction;
	this->_direction.Normalize();
	Vec3f* newVec = new Vec3f();
	this->_up = up;
	this->_up.Normalize();
	Vec3f::Cross3(*newVec, this->_up, this->_direction);
	this->_horizontal = *newVec;
	Vec3f::Cross3(*newVec, this->_direction, this->_horizontal);
	this->_up = *newVec;
	this->_centre = centre;
	this->_size = size;
}


Ray OrthographicCamera::generateRay(Vec2f point) {
	Vec3f origin(this->_centre + 
					(this->_up * (((2*point.y() - 1)/2) * this->_size)) + (this->_horizontal * (((2 * point.x() - 1)/2) * this->_size))
					);
	return Ray(this->_direction, origin);
}
