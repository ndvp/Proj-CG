#include"Objects.h"

void DynamicObject::setSpeed(double x, double y, double z) {
	_speed.set(x, y, z);
}

Vector3 DynamicObject::getSpeed() {
	return _speed;
}

void DynamicObject::update(double delta_t){
	setPosition(_position + _speed*delta_t);
}

Frog::Frog(){
	_position.set(SapoX, SapoY, SapoZ);
}

void Frog::draw()
{	
	glPushMatrix();
	glTranslatef(getPosition()->getX() , getPosition()->getY(), getPosition()->getZ());
	glScalef(0.1, 0.1, 0.1);
	

	glPushMatrix();

	glColor3f(0.0, 103. / 256., 0.0);

	glutSolidSphere(5, 10, 10);

	glPopMatrix();


	drawBackRightLeg();
	drawBackLeftLeg();
	drawFrontLegs();

	glPopMatrix();
}


void Frog::drawBackRightLeg()
{
	glPushMatrix();

	glTranslatef(5, -3, 0);
	glRotatef(-35, 0, 0, 1);
	glScalef(5, 2, 2);
	glutSolidCube(1);

	glPopMatrix();


	glPushMatrix();

	glTranslatef(7.3, -6.3, 0);
	glRotatef(-75, 0, 0, 1);
	glScalef(5, 2, 2);
	glutSolidCube(1);

	glPopMatrix();

}



void Frog::drawBackLeftLeg()
{

	glPushMatrix();
	glRotatef(180, 0, 1, 0);

	drawBackRightLeg();

	glPopMatrix();

}

void Frog::drawFrontLegs()
{
	glPushMatrix();

	glRotatef(180, 1, 0, 0);

	drawBackLeftLeg();
	drawBackRightLeg();

	glPopMatrix();


}

void River::draw(){
	glPushMatrix();
	glColor3f(0.0, 0.0, 1.0);

	glTranslatef(0.0, 3.5, 0.0);
	glScalef(25.0, 7.0, 0.0);

	glutSolidCube(1.0);

	glPopMatrix();
}

void Riverside::draw(){

	glPushMatrix();
	glColor3f(0.0, 200. / 256., 0.0);

	glTranslatef(0.0, 7.0, 0.0);
	glScalef(25.0, 1.0, 0.0);

	glutSolidCube(1.0);

	glPopMatrix();


	glPushMatrix();
	glColor3f(0.0, 200. / 256., 0.0);

	glTranslatef(-11.75, 6.0, 0.0);
	glScalef(1.5, 2.0, 0.0);

	glutSolidCube(1.0);

	glPopMatrix();


	glPushMatrix();
	glColor3f(0.0, 200. / 256., 0.0);

	glTranslatef(-7.5, 6.0, 0.0);
	glScalef(3.0, 2.0, 0.0);

	glutSolidCube(1.0);

	glPopMatrix();


	glPushMatrix();
	glColor3f(0.0, 200. / 256., 0.0);

	glTranslatef(-2.5, 6.0, 0.0);
	glScalef(3.0, 2.0, 0.0);

	glutSolidCube(1.0);

	glPopMatrix();



	glPushMatrix();
	glColor3f(0.0, 200. / 256., 0.0);

	glTranslatef(2.5, 6.0, 0.0);
	glScalef(3.0, 2.0, 0.0);

	glutSolidCube(1.0);

	glPopMatrix();



	glPushMatrix();
	glColor3f(0.0, 200. / 256., 0.0);

	glTranslatef(7.5, 6.0, 0.0);
	glScalef(3.0, 2.0, 0.0);

	glutSolidCube(1.0);

	glPopMatrix();



	glPushMatrix();
	glColor3f(0.0, 200. / 256., 0.0);

	glTranslatef(11.75, 6.0, 0.0);
	glScalef(1.5, 2.0, 0.0);

	glutSolidCube(1.0);

	glPopMatrix();

}

void Road::draw(){
	glPushMatrix();
	glColor3f(224. / 256., 224. / 256., 224. / 256.);

	glTranslatef(0.0, -4.0, 0.0);
	glScalef(25.0, 6.0, 0.0);

	glutSolidCube(1.0);

	glPopMatrix();
}

void Roadside::draw(){
	glPushMatrix();

	glColor3f(153. / 256., 76. / 256., 0.0);

	glTranslatef(0, -0.5, 0);
	glScalef(25, 1, 0);
	glutSolidCube(1.0);

	glPopMatrix();

	glPushMatrix();

	glTranslatef(0, -7.0, 0);
	glScalef(25, 1, 0);
	glutSolidCube(1.0);

	glPopMatrix();


}

void TimberLog::draw(){
	glPushMatrix();

	glColor3f(153. / 256., 76. / 256., 0.0);

	glTranslatef(0, 3, 0);
	glScalef(15, 1, 0);
	glutSolidCube(1.0);

	glPopMatrix();
}