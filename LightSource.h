#include "Vector.h"

#if defined(__APPLE__) || defined(MACOSX) 
	#include <GLUT/glut.h> 
#else
	#include <GL/glut.h> 
#endif

#ifndef _LIGHT_SOURCE_H
#define _LIGHT_SOURCE_H

class LightSource{
private:
	Vector4 _ambient;
	Vector4 _diffuse;
	Vector4 _specular;
	Vector4 _position;
	Vector3 _direction;
	double _cutOff;
	double _exponent;
	GLenum _num;
	bool _state;
public:
	LightSource(GLenum number);
	bool getState();
	bool setState(bool state);
	GLenum getNum();
	void setPosition(const Vector4& position);
	void setDirection(const Vector3& direction);
	void setCutOff(double cut_off);
	void setExponent(double exponent);
	void setAmbient(const Vector4 & ambient);
	void setDiffuse(const Vector4& diffuse);
	void setSpecular(const Vector4& specular);
	void draw(){};
};

#endif