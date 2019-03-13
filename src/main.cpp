#include <miniwin.h>		//obligado poner donde este el main
#include <game.h>


int main() {
	Game* game = new Game();
	game->run();
	delete game;
	
	return 0;
}