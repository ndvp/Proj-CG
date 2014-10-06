#include "Cameras.h"

OrthogonalCamera::OrthogonalCamera(double left, double right, double bottom, double top, double near, double far){
	_left = left;
	_right = right;
	_bottom = bottom;
	_top = top;
	_near = near;
	_far = far;
}

void OrthogonalCamera::update(){
	glOrtho(_left, _right, _bottom, _top, _near, _far);
}

void OrthogonalCamera::computeProjectionMatrix(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}

void OrthogonalCamera::computeVisualizationMatrix(){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}