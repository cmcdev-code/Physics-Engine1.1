#include "Vector3.h"

Vector3::Vector3() {
	this->X = 0.0f;
	this->Y = 0.0f;
	this->Z = 0.0f;
}
Vector3::Vector3(const double& X, const double& Y, const double& Z) {
	this->X = X;
	this->Y = Y;
	this->Z = Z;
}
void Vector3::setX(const double& X) {
	this->X = X;
}
void Vector3::setY(const double& Y) {
	this->Y = Y;
}
void Vector3::setZ(const double& Z) {
	this->Z = Z;
}
double Vector3::getX() const {
	return this->X;
}
double Vector3::getY() const {
	return this->Y;
}
double Vector3::getZ() const {
	return this->Z;
}
void Vector3::setXYZ(const double& X, const double& Y, const double& Z) {
	this->X = X;
	this->Y = Y;
	this->Z = Z;
}
void Vector3::getXYZ(double& X, double& Y, double& Z) {
	X = this->X;
	Y = this->Y;
	Z = this->Z;
}