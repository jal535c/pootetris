#include <miniwin.h>
#include <game.h>
#include <global.h>
#include <cstdlib>		


Game::Game() 
{
	miniwin::vredimensiona(TAM*COLUMNAS, TAM*FILAS);
	srand(time(0));
	tic = 0;
	T.vacia();
	P.pieza_nueva();
	P.pinta_pieza();
	miniwin::refresca();		
}


Game::~Game() {
	miniwin::vcierra();
}


void Game::run() {
	int t = miniwin::tecla();
	while (t != miniwin::ESCAPE) {
		//copiar la actual
		Pieza copia = P;

		if (t == miniwin::NINGUNA && tic>30) {		//para controlar la velocidad de bajada
			tic=0;
			t = miniwin::ABAJO;
		}


		//mover
		if (t == miniwin::ABAJO) 
			P.orig.y++;
		else if (t == miniwin::ARRIBA) 
			P.rota_derecha();
		else if (t == miniwin::DERECHA) 
			P.orig.x++;
		else if (t == miniwin::IZQUIERDA) 
			P.orig.x--;


		//mirar si hay colision ... actualicé las posiciones, pero si hay colision vuelvo a poner las antiguas
		if (T.colision(P)) {
			P = copia;
			if (t == miniwin::ABAJO) {
				T.incrusta_pieza(P);
				int cont = T.cuenta_lineas();
				P.pieza_nueva(); 	//reciclo la variable c
			}
		}


		//repintar
		if (t != miniwin::NINGUNA) {
			miniwin::borra();
			T.pinta();
			P.pinta_pieza();
			miniwin::refresca();	
		}
				
		miniwin::espera(30);
		tic++;
		t = miniwin::tecla();
	}
}