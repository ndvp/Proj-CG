#ifndef _VECTOR_H
#define _VECTOR_H

class Vector3{
protected:
	double _x;
	double _y;
	double _z;
public:
	Vector3(){}
	Vector3(double x, double y, double z);
	double getX();
	double getY();
	double getZ();
	void set(double x, double y, double z);
	Vector3 operator=(const Vector3& vec);
	Vector3 operator*(double num);
	Vector3 operator+(const Vector3& vec);
	Vector3 operator-(const Vector3& vec);
};

class Vector4 : public Vector3{
private:
	double _w;
public:
	Vector4();
	Vector4(double x, double y, double z, double w);
	double getW();
	void set(double x, double y, double z, double w);
	Vector4 operator=(const Vector4& vec);
	Vector4 operator*(double num);
	Vector4 operator+(const Vector4& vec);
	Vector4 operator-(const Vector4& vec);
};

#endif