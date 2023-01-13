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
	this->position[0] = X;
	this->position[1] = Y;
	this->position[2] = Z;
}

void particle::getPosition(double& X, double& Y, double& Z){
	X = this->position[0];
	Y = this->position[1];
	Z = this->position[2];
}

void particle::setVelocity(const double& X, const double& Y,const double& Z){
	this->velocity[0] = X;
	this->velocity[1] = Y;
	this->velocity[2] = Z;
}

void particle::getVelocity(double& X, double& Y, double& Z){
	X = this->velocity[0];
	Y = this->velocity[1];
	Z = this->velocity[2];
}

void particle::setAcceleration(const double &X,const double &Y,const double &Z){
	this->acceleration[0] = X;
	this->acceleration[1] = Y;
	this->acceleration[2] = Z;
}

void particle::getAcceleration(double& X, double& Y, double& Z){
	X = this->acceleration[0];
	Y = this->acceleration[1];
	Z = this->acceleration[2];
}

void particle::setXposition(const double &X){
	this->position[0] = X;
}

void particle::setYposition(const double &Y){
	this->position[1] = Y;

}

void particle::setZposition(const double &Z){
	this->position[2] = Z;
}

double particle::getXposition() const{
	return this->position[0];
}

double particle::getYposition() const{
	return this->position[1];
}

double particle::getZposition() const{
	return this->position[2];
}

void particle::setXvelocity(const double& X){
	this->velocity[0] = X;
}

void particle::setYvelocity(const double& Y){
	this->velocity[1] = Y;
}

void particle::setZvelocity(const double& Z){
	this->velocity[2] = Z;
}

double particle::getXvelocity() const{
	return this->velocity[0];
}

double particle::getYvelocity() const{
	return this->velocity[1];
}

double particle::getZvelocity() const{
	return this->velocity[2];
}

void particle::setXacceleration(const double& X) {
	this->acceleration[0] = X;
}

void particle::setYacceleration(const double& Y) {
	this->acceleration[1] = Y;
}

void particle::setZacceleration(const double& Z){
	this->acceleration[2] = Z;
}

double particle::getXacceleration() const{
	return this->acceleration[0];
}

double particle::getYacceleration() const {
	return this->acceleration[1];
}

double particle::getZacceleartion() const {
	return this->acceleration[2];
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