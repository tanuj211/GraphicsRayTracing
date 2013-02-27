#include "raycast.h"

// Add any code you need here and in the corresponding header
// file.


// Constructor with parameters.
OrthographicCamera::OrthographicCamera(Vec3f centre, Vec3f direction, Vec3f up, float size) {
	this->_direction = direction.Normalize();
	Vec3f newVec = new Vec3f();
	cross3(newVec, up.Normalize(), this->_direction);
	this->_horizontal = newVec;
	cross3(newVec, this->_horizontal, this->_direction);
	this->up = newVec;
	this->_centre = centre;
	this->_size = size;
}


Ray OrthographicCamera::generateRay(Vec2f point) {

}
