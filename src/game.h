#ifndef __GAME_H__
#define __GAME_H__


#include <pieza.h>
#include <tablero.h>


class Game {
private:
	Pieza P;
	Tablero T;
	int tic;

public:
	Game();
	~Game();
	void run();
};


#endif