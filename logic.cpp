#include "logic.h"
#include <cmath>;
#include "iostream"

//#define gravity 0.000000000066743
//#define gravity -0.000000000066743
//#define gravity  0.00000066743
#define gravity -0.00000066743

#define time 0.1


long double getMagnitudeOfVelocity(particle	&p1) {
	return pow(p1.getXvelocity() * p1.getXvelocity() + p1.getYvelocity() * p1.getYvelocity() + p1.getZvelocity() * p1.getZvelocity(), .5);
}

double Logic::getDistanceBetweenParticle(particle& P1, particle& P2) 
{
	double distance =std::pow(
		(P1.getXposition() - P2.getXposition()) * (P1.getXposition() - P2.getXposition())
		+ (P1.getYposition() - P2.getYposition()) * (P1.getYposition() - P2.getYposition())
		+ ((P1.getZposition() - P2.getZposition()) * (P1.getZposition() - P2.getZposition())), 0.5);
	
	if (isnan(distance)) {
		return 0.0001;
	}
	return distance;
}

double Logic::getForceFromGravity(particle& P1, particle& P2) 
{
	return -gravity * P1.getMass() * P2.getMass() / getDistanceBetweenParticle(P1, P2);
}

double Logic::getForceFromGravity_X(particle& P1, particle& P2) 
{
	//calculating unit vector just for the x 
	double MagnitudeOFVector = (getDistanceBetweenParticle(P1, P2));
	if (MagnitudeOFVector <= ((P1.getRadius() + P2.getRadius()) / 1000) ){
		return 0;
	}//.75/exp((x*5)^2*(y*5)^2)
	//.75/exp(pow(P1.getXposition()*5,2)*pow(P1.getYposition())
	return    (getForceFromGravity(P1, P2) * (P1.getXposition() - P2.getXposition())) / (MagnitudeOFVector * MagnitudeOFVector);
}
double Logic::getForceFromGravity_Y(particle& P1, particle& P2) 
{
	double MagnitudeOFVector = (getDistanceBetweenParticle(P1, P2));
	if (MagnitudeOFVector <= ((P1.getRadius() + P2.getRadius()) / 1000)) {
		return 0;
	}
	return   (getForceFromGravity(P1, P2) * (P1.getYposition() - P2.getYposition())) / (MagnitudeOFVector * MagnitudeOFVector);
}
double Logic::getForceFromGravity_Z(particle& P1, particle& P2) 
{
	double MagnitudeOFVector = (getDistanceBetweenParticle(P1, P2));
	if (MagnitudeOFVector <= ((P1.getRadius() + P2.getRadius()) / 1000)) {
		return 0;
	}
	return (getForceFromGravity(P1, P2) * (P1.getZposition() - P2.getZposition())) / (MagnitudeOFVector * MagnitudeOFVector);
}


void Logic::changePosition(particle& P1,const double & X,const  double & Y,const double & Z) 
{
	P1.setPosition(P1.getXposition() + X, P1.getYposition() + Y, P1.getZposition() + Z);
}
void Logic::changeVelocity(particle& P1, const double& X, const  double& Y, const double& Z)
{
	P1.setVelocity(P1.getXvelocity() + X, P1.getYvelocity() + Y, P1.getZvelocity() + Z);
}
void Logic::changeAccleration(particle& P1, const double& X, const  double& Y, const double& Z) {

	P1.setAcceleration( X,  Y,  Z);
}
void Logic::updatePosition(particle& P1) 
{
	double x, y, z;
	P1.getPosition(x, y, z);


	P1.setPosition
		(
		P1.getXposition() + P1.getXvelocity()* time,
		P1.getYposition() + P1.getYvelocity() * time,
		P1.getZposition() + P1.getZvelocity() * time
		);
}
void Logic::updateVelocity(particle& P1)
{
	double x, y, z;
	P1.getPosition(x, y, z);
	if (x >= 28.01 or x <= -28.01 or y <= -28.01 or y >= 28.01) {
		P1.setPosition(0, 0, 0);
		
	}

	else if (x + P1.getXvelocity() <= -28) {
		long double angle = asin(((P1.getXvelocity()) / getMagnitudeOfVelocity(P1)));


		double cosineOfAngle = cos(angle);
		double sineOfAngel = sin(angle);

		P1.setVelocity
		(
			.98*P1.getXvelocity() * sineOfAngel + P1.getXacceleration() * time
			,
			.98 * P1.getYvelocity() * cosineOfAngle + P1.getYacceleration() * time,
			.98 * P1.getZvelocity() + P1.getZvelocity() * time

		);
		}
		else if (x + P1.getXvelocity() >= 28) {
			long double angle = asin(((P1.getXvelocity()) / getMagnitudeOfVelocity(P1)));


			double cosineOfAngle = -cos(angle);
			double sineOfAngel = sin(angle);

			P1.setVelocity
			(
				.98 * P1.getXvelocity() *-sineOfAngel + P1.getXacceleration() * time
				,
				.98 * P1.getYvelocity() * cosineOfAngle + P1.getYacceleration() * time,
				.98 * P1.getZvelocity() + P1.getZvelocity() * time

			);
	} 
	else if (y + P1.getYvelocity() >= 28 or y + P1.getYvelocity() <= -28) {
		long double angle = acos(((P1.getXvelocity()) / getMagnitudeOfVelocity(P1)));


		double cosineOfAngle = cos(angle);
		double sineOfAngel = sin(angle);

		P1.setVelocity
		(
			.98 * P1.getXvelocity() * sineOfAngel + P1.getXacceleration() * time
			,
			.98 * P1.getYvelocity() * cosineOfAngle + P1.getYacceleration() * time,
			.98 * P1.getZvelocity() + P1.getZvelocity() * time

		);
	}
	else
	 {
		P1.setVelocity
		(
			P1.getXvelocity() + P1.getXacceleration() * time,
			P1.getYvelocity() + P1.getYacceleration() * time,
			P1.getZvelocity() + P1.getZacceleartion() * time

		);
	}

}

sf::Color Logic::getGradientColor(const particle& P1) 
{
	double x = (28 + P1.getXposition()) / 56;
	double y = (28 + P1.getYposition()) / 56;

	double hue = y * 360;
	
	sf::Color color = hsvToRGB(hue, x, 1.0);
	return color;
}

//From https://alejandrohitti.com/2015/06/29/rgb-hsv-color-conversions/
sf::Color Logic::hsvToRGB(const double hue, const double saturation, const double value)
{
	// Achromatic (gray)
	if (saturation == 0)
	{
		return sf::Color(255, 255, 255);
	}

	// Conversion values
	double tempH = hue;
	tempH /= 60.0f;
	int i = (int)std::floor(tempH);
	double f = tempH - i;
	int p = value * (1.0 - saturation);
	int q = value * (1.0 - saturation * f);
	int t = value * (1.0 - saturation * (1.0 - f));
	p *= 255;
	q *= 255;
	t *= 255;

	// There are 6 cases, one for every 60 degrees
	switch (i)
	{
	case 0:
		return sf::Color(255, t, p);
	case 1:
		return sf::Color(q, 255, p);
	case 2:
		return sf::Color(p, 255, t);
	case 3:
		return sf::Color(p, q, 255);
	case 4:
		return sf::Color(t, p, 255);
	default:
		return sf::Color(255, p, q);
	}
}