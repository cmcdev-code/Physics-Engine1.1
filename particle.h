#pragma once
#include <SFML/Graphics.hpp>



class particle {
	public:	
		

		particle();
		
		particle(double Xp, double Yp, double Zp, double Xv, double Yv, double Zv, double
			Xa, double Ya, double Za,long double mass, long double temp, double radius);

	

		void setMass(long double mass);
		long double getMass() const;

		void setTemp(long double temp);
		long double getTemp() const;

		void setRadius(double radius);
		double getRadius() const;

		void setPosition(double X, double Y, double Z);
		void getPosition(double& X, double& Y, double& Z);

		void setVelocity(double X, double Y, double Z);
		void getVelocity(double& X, double& Y, double& Z);

		void setAcceleration(double X, double Y, double Z);
		void getAcceleration(double& X, double& Y, double& Z);

		void setXposition(double X);
		void setYposition(double Y);
		void setZposition(double Z);

		double getXposition() const;
		double getYposition() const;
		double getZposition() const;

		void setXvelocity(double X);
		void setYvelocity(double Y);
		void setZvelocity(double Z);

		double getXvelocity() const;
		double getYvelocity() const;
		double getZvelocity() const;

		void setXacceleration(double X);
		void setYacceleration(double Y);
		void setZacceleration(double Z);

		double getXacceleration() const;
		double getYacceleration() const;
		double getZacceleartion() const;


	private:
		long double mass;
		long double temp;
		double radius;
		double position[3];
		double velocity[3];
		double acceleration[3];
		
};