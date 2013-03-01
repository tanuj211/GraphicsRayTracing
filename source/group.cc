#include "raycast.h"

// Constructor for a group of n objects.
Group::Group(int n) {

  this->_object = new Object3D*[n];
  this->_count  = n;
  for(int i = 0; i < n; ++i) {
    this->_object[i] = NULL;
  }
}

// Destructor.
Group::~Group() {

  if (this->_object == NULL) {
    return;
  }

  for (int i = 0; i < this->_count; i++) {
    if (this->_object[i] != NULL) {
      delete this->_object[i];
    }
  }
  delete[] this->_object;
}

// Insert an object into the array.
// YOUR CODE HERE.
void Group::addObject(int index, Object3D *obj) {
  // if (index > this->_count) {
  //   index = this->_count + 1;
  // }
  //cout << "Inside addObject" << endl;
  //this->_count++;
  //Object3D **newObject = new Object3D*[this->_count+1];
  //for(int i = 0; i < this->_count; i++) {
  this->_object[index] = obj;
  //}
  // for(int i = 0; i < this->_count; i++) {
  //   if (i <= index) {
  //     if (i == index) {
  //       newObject[i] = obj;
  //     } else {
  //       newObject[i] = this->_object[i];
  //     }
  //   }
  //   newObject[i] = this->_object[i-1];
  // }
  //cout << "Leaving addObject" << endl;
  //this->_object = newObject;
}

// YOUR CODE HERE.
bool Group::intersect(const Ray &r, Hit &h) {
  for (int i = 0; i < this->_count; i++) {
    //cout << "In iteration " << i << this->_count << endl;
    this->_object[i]->intersect(r, h);
  }
  return true;
}
