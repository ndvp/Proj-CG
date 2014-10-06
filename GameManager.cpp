#include "GameManager.h"
#include<iostream>

float xmin = -10., xmax = 10., ymin = -10., ymax = 10., zmin = -10.0, zmax = 10.0;

void GameManager::display() {
	for each (GameObject *g in _game_objects){
		g->draw();
	}
}

void GameManager::addObject(GameObject *g){
	_game_objects.push_front(g);
}

void GameManager::addCamera(Camera *c){
	_cameras.push_front(c);
}

void GameManager::init(){
	_frog = new Frog();
	addObject(_frog);
	addObject(new Riverside());
	addObject(new Roadside());
	addObject(new River());
	addObject(new Road());

	addCamera(new OrthogonalCamera(xmin, xmax, ymin, ymax, zmin, zmax));
}

int GameManager::getState(){
	return _state;
}

void GameManager::setState(int state){
	_state = state;
}

void GameManager::update(double delta_t){
	int actTime = glutGet(GLUT_ELAPSED_TIME);
	switch (int state = getState()){
		case LEFT:
			_frog->setSpeed(-SPEED, 0, 0);
			break;
		case RIGHT:
			_frog->setSpeed(SPEED, 0, 0);
			break;
		case UP:
			_frog->setSpeed(0, SPEED, 0);
			break;
		case DOWN:
			_frog->setSpeed(0, -SPEED, 0);
			break;
		case STOP:
			_frog->setSpeed(0, 0, 0);
			break;
	}

	std::cout << "FrogPos: (" << _frog->getPosition()->getX() << ", " << _frog->getPosition()->getY() << ", " << _frog->getPosition()->getZ() << ")\n";

	for each (GameObject *g in _game_objects){
		g->update(delta_t);
		_oldTime = actTime;
	}
}

double GameManager::getOldTime(){
	return _oldTime;
}