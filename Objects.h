#if defined(__APPLE__) || defined(MACOSX) 
	#include <GLUT/glut.h> 
#else
	#include <GL/glut.h> 
#endif
#include "Entity.h"

#ifndef _OBJECTS_H
#define _OBJECTS_H

#define SPEED 0.2
#define SapoX 0.0
#define SapoY -7.0
#define SapoZ 1.0
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

class GameObject : public Entity{
public:
	char id;
	virtual void draw(){}
	virtual void update(double delta_t){};
};

class StaticObject : public GameObject{
	public:
		StaticObject() { }
		~StaticObject() { }
};

class DynamicObject : public GameObject{
	protected:
		Vector3 _speed;
	public:
		DynamicObject(){}
		~DynamicObject(){}
		void update(double delta_t);
		void setSpeed(const Vector3& speed);
		void setSpeed(double x, double y, double z);
		Vector3 getSpeed();
};

class River : public StaticObject{
public:
	void draw();
};

class Riverside : public StaticObject{
public:
	void draw();
};

class Road : public StaticObject{
public:
	void draw();
};

class Roadside : public StaticObject{
public:
	void draw();
};

class Bus : public DynamicObject{
public:
	void draw();
};

class Car : public DynamicObject{
public:
	void draw();
};


class Frog : public DynamicObject{
	void drawBackRightLeg();
	void drawBackLeftLeg();
	void drawFrontLegs();
	void draw();
	void update();

public:
	Frog();
};

class TimberLog : public DynamicObject{
	void draw();
};

class Turtle : public DynamicObject{

};
#endif