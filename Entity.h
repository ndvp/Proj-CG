#include "Vector.h"
#ifndef _ENTITY_H
#define _ENTITY_H

class Entity{
protected:
	Vector3 _position;
public:
	virtual Vector3* getPosition();
	virtual Vector3* setPosition(double x, double y, double z);
	virtual Vector3* setPosition(const Vector3& p);
};

#endif