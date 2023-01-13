#include "particle.h"
#include <SFML/Graphics.hpp>

#define WINDOWSIZE 2560, 1440
particle::particle(){
	mass           = 0.0f;
	temp		   = 0.0f;
	radius         = 1.0f;
	coefficentRest = 0.0;
	setAcceleration(0.0f, 0.0f, 0.0f);
	setVelocity(0.0f, 0.0f, 0.0f);
	setPosition(0.0f, 0.0f, 0.0f);
}

particle::particle
	(	double Xp, double Yp, double Zp,
		double Xv, double Yv, double Zv, 
		double Xa, double Ya, double Za,
		long double mass, long double temp, 
		double radius, double coefficentRest
	)
{
		setPosition(Xp, Yp, Zp);
		setVelocity(Xv, Yv, Zv);
		setAcceleration(Xa, Ya, Za);
		this->mass = mass;
		this->temp = temp;
		this->radius = radius;
		this->circle.setRadius(radius);
		this->setCircleCenterOrigin(WINDOWSIZE);
		this->coefficentRest = coefficentRest;
}

void particle::setMass(const long double &mass){
	this->mass = mass;
}
long double particle::getMass() const{
	return this->mass;
}

void particle::setTemp(const long double &temp){
	this->temp = temp;
}

long double particle::getTemp() const{
	return this->temp;
}

void particle::setRadius(const double& radius){
	this->radius = radius;
}
double particle::getRadius() const{
	return this->radius;
}

void particle::setPosition(const double & X,const double &Y,const double& Z){
	this->position.setXYZ(X, Y, Z);
}

void particle::getPosition(double& X, double& Y, double& Z){
	this->position.getXYZ(X, Y, Z);
}

void particle::setVelocity(const double& X, const double& Y,const double& Z){
	this->velocity.setXYZ(X, Y, Z);
}

void particle::getVelocity(double& X, double& Y, double& Z){
	this->velocity.getXYZ(X, Y, Z);
}

void particle::setAcceleration(const double &X,const double &Y,const double &Z){
	this->acceleration.setXYZ(X, Y, Z);
}

void particle::getAcceleration(double& X, double& Y, double& Z){
	this->acceleration.getXYZ(X, Y, Z);
}

void particle::setXposition(const double &X){
	this->position.setX(X);
}

void particle::setYposition(const double &Y){
	this->position.setY(Y);

}

void particle::setZposition(const double &Z){
	this->position.setZ(Z);
}

double particle::getXposition() const{
	return this->position.getX();
}

double particle::getYposition() const{
	return this->position.getY();
}

double particle::getZposition() const{
	return this->position.getZ();
}

void particle::setXvelocity(const double& X){
	this->velocity.setX(X);
}

void particle::setYvelocity(const double& Y){
	this->velocity.setY(Y);
}

void particle::setZvelocity(const double& Z){
	this->velocity.setZ(Z);
}

double particle::getXvelocity() const{
	return this->velocity.getX();
}

double particle::getYvelocity() const{
	return this->velocity.getY();
}

double particle::getZvelocity() const{
	return this->velocity.getZ();
}

void particle::setXacceleration(const double& X) {
	this->acceleration.setX(X);
}

void particle::setYacceleration(const double& Y) {
	this->acceleration.setY(Y);
}

void particle::setZacceleration(const double& Z){
	this->acceleration.setZ(Z);
}

double particle::getXacceleration() const{
	return this->acceleration.getX();
}

double particle::getYacceleration() const {
	return this->acceleration.getY();
}

double particle::getZacceleartion() const {
	return this->acceleration.getZ();
}
void particle::setCircleCenterOrigin(const double & windowX, const double & windowY) {
	circle.setOrigin(getRadius(), getRadius());
	circle.setPosition(transformPoint(getXposition(), getYposition(), windowX, windowY));
}

void particle::setcoefficentRest(const double& coefficentRest) {
	this->coefficentRest = coefficentRest;
}
double particle::getCoefficentRest() const {
	return this->coefficentRest;
}

sf::Vector2f particle::transformPoint(float x, float y, const float & windowWidth,const float& windowHeight){
	y = -y;

	x = (x / 2.0f) * windowWidth;
	y = (y / 2.0f) * windowHeight;

	x += (windowWidth / 2.0f);
	y += (windowHeight / 2.0f);

	return sf::Vector2f(x, y);
}