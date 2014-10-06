#include<iostream>
#include "GameManager.h"

#define ASPECT_RATIO (16./9.)

GameManager *game;

void keyHandler(unsigned char key, int x, int y){
	switch (key){

		case 'o':
		case 'O': game->setState(LEFT); break;

		case 'p':
		case 'P': game->setState(RIGHT); break;

		case 'q':
		case 'Q': game->setState(UP); break;

		case 'a':
		case 'A': game->setState(DOWN); break;

		default: game->setState(STOP); break;
	}
}

void myTimer(int ms)
{
	game->update(glutGet(GLUT_ELAPSED_TIME) - game->getOldTime());
	glutPostRedisplay();
	glutTimerFunc(ms, myTimer, ms);
}

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 0.0);

	//glEnable(GL_DEPTH_TEST);
	//glEnable(GL_LIGHTING);
	//glEnable(GL_NORMALIZE);

	game->display();
	glFlush();
}

void myReshape(int w, int h)
{

	float xmin = -10., xmax = 10., ymin = -10., ymax = 10., zmin = -10.0, zmax = 10.0;

	float ratio = (xmax - xmin) / (ymax - ymin);
	float aspect = (float)w / h;

	glViewport(0, 0, w, h);

	Camera *c = new OrthogonalCamera(xmin, xmax, ymin, ymax, zmin, zmax);

	c->computeProjectionMatrix();
	c->computeVisualizationMatrix();
	c->update();

	if (ratio < aspect)
		glScalef(ratio / aspect, 1., 1.);
	else
		glScalef(1., aspect / ratio, 1.);

}

int main(int argc, char *argv[])
{

	game = new GameManager();
	game->init();

	glutInit(&argc, argv);
	glutInitWindowSize(800, 450);
	glutInitWindowPosition(10, 10);

	glutCreateWindow("Frogger");
	
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myReshape);

	glutKeyboardFunc(keyHandler);
	glutTimerFunc(30, myTimer, 30);              // ~33 FPS


	glutMainLoop();

	return 0;

}