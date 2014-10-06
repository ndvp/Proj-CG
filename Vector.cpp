#include "Vector.h"

Vector3::Vector3(double x, double y, double z) {
	_x = x;
	_y = y;
	_z = z;
}

double Vector3::getX() {
	return _x;
}
double Vector3::getY() {
	return _y;
}
double Vector3::getZ() {
	return _z;
}

void Vector3::set(double x, double y, double z) {
	_x = x;
	_y = y;
	_z = z;
}

Vector3 Vector3::operator=(const Vector3& vec) {
	Vector3 v = vec;
	_x = v.getX();
	_y = v.getY();
	_z = v.getZ();
	return *this;
}

Vector3 Vector3::operator*(double num){
	_x *= num;
	_y *= num;
	_z *= num;
	return *this;
}

Vector3 Vector3::operator+(const Vector3& vec) {
	Vector3 v = vec;
	_x += v.getX();
	_y += v.getY();
	_z += v.getZ();
	return *this;
}

Vector3 Vector3::operator-(const Vector3& vec) {
	Vector3 v = vec;
	_x -= v.getX();
	_y -= v.getY();
	_z -= v.getZ();
	return *this;
}

