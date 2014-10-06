#include<stdlib.h>
#include<list>
#include <deque>

#include "LightSource.h"
#include "Cameras.h"
#include "Objects.h"

#if defined(__APPLE__) || defined(MACOSX) 
	#include <GLUT/glut.h> 
#else
	#include <GL/glut.h> 
#endif

#ifndef _GAME_H
#define _GAME_H

class GameManager{
	private:
		std::deque<GameObject*> _game_objects;
		std::deque<LightSource*> _light_sources;
		std::deque<Camera*> _cameras;
		int _state;
		Frog* _frog;
		double _oldTime;
	public:
		void display();
		void reshape(GLsizei w, GLsizei h);
		void keyPressed();
		void onTimer();
		void idle();
		void update(double delta_t);
		void init();
		void addObject(GameObject *g);
		void addLight(LightSource *l);
		void addCamera(Camera *c);
		int getState();
		void setState(int i);
		double getOldTime();
};

#endif