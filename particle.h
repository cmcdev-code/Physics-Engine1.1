#pragma once
#include <SFML/Graphics.hpp>
#include "Vector3.h"



class particle {
	public:	
		
		//constructors
		particle();
		
		particle(	
					double Xp, double Yp, double Zp, 
					double Xv, double Yv, double Zv, 
				    double Xa, double Ya, double Za,
					long double mass, long double temp, 
					double radius,double coefficentRest=0
				);
		//Sets and gets mass
		void setMass(const long double& mass);
		long double getMass() const;

		//sets and gets the temp
		void setTemp(const long double& temp);
		long double getTemp() const;

		//sets and gets radius 
		void setRadius(const double& radius);
		double getRadius() const;

		//sets the position
		void setPosition(const double& X,const double &Y, const double & Z);
		void getPosition(double& X, double& Y, double& Z);

		//sets velocity
		void setVelocity(const double& X,const double& Y,const double& Z);
		void getVelocity(double& X, double& Y, double& Z);

		//sets acceleration
		void setAcceleration(const double & X, const double &Y,const double& Z);
		void getAcceleration(double& X, double& Y, double& Z);

		//sets the positions
		void setXposition(const double& X);
		void setYposition(const double& Y);
		void setZposition(const double& Z);

		//gets the positipons
		double getXposition() const;
		double getYposition() const;
		double getZposition() const;

		//stes velocity
		void setXvelocity(const double& X);
		void setYvelocity(const double& Y);
		void setZvelocity(const double& Z);

		//gets the velocity 
		double getXvelocity() const;
		double getYvelocity() const;
		double getZvelocity() const;

		//sets acceleration
		void setXacceleration(const double& X);
		void setYacceleration(const double& Y);
		void setZacceleration(const double& Z);

		double getXacceleration() const;
		double getYacceleration() const;
		double getZacceleartion() const;

		//setts and gets coeffiecent of Rest
		void setcoefficentRest(const double& coefficentRest);
		double getCoefficentRest() const;


		sf::Vector2f transformPoint(float x, float y,const float& windowWidth,const float& windowHeight);

	
		void setCircleCenterOrigin(const double & windowX,const double& windowY);

		sf::CircleShape circle;

		

	private:
		long double mass;
		long double temp;
		double coefficentRest;
		double radius;
		Vector3<double> position;
		Vector3<double> velocity;
		Vector3<double> acceleration;
};