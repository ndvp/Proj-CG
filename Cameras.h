#if defined(__APPLE__) || defined(MACOSX) 
	#include <GLUT/glut.h> 
#else
	#include <GL/glut.h> 
#endif

#include "Vector.h"
#include "Entity.h"

#ifndef _CAMERAS_H
#define _CAMERAS_H

class Camera : public Entity{
protected:
	Vector3 _up;
	Vector3 _at;
	double _near;
	double _far;
public:
	Camera(){}
	Camera(double near, double far){}
	~Camera(){}
	virtual void update(){}
	virtual void computeProjectionMatrix(){}
	virtual void computeVisualizationMatrix(){}
};

class PerspectiveCamera: public Camera{
	private:
		double _fovy;
		double _aspect;
	public:
		PerspectiveCamera(double fovy, double aspect, double zNear, double zFar) { }
		~PerspectiveCamera() { }
		
};

class OrthogonalCamera : public Camera{
	private:
		double _left;
		double _right;
		double _bottom;
		double _top;
	public:
		OrthogonalCamera(double left, double right, double bottom, double top, double near, double far);
		void computeProjectionMatrix();
		void computeVisualizationMatrix();
		void update();

};
#endif