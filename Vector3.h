#pragma once
class Vector3
{
	public:
		Vector3();
		Vector3(const double& X, const double& Y, const double& Z);

		void setX(const double& X);
		void setY(const double& Y);
		void setZ(const double& Z);

		double getX() const;
		double getY() const;
		double getZ() const;

		void setXYZ(const double& X, const double& Y, const double& Z);
		void getXYZ(double& X, double& Y, double& Z);

	private:
		double X;
		double Y;
		double Z;


};

