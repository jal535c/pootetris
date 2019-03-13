#ifndef __PIEZA_H__
#define __PIEZA_H__


#include <global.h>


//void cuadrado(int , int );

/*
struct Coord {
	int x, y;
};
*/

struct Pieza {
	Coord orig;			//bloque original, pieza base
	Coord perif[3];		//los 3 bloques perifericos, relativos al original
	int micolor;

	void pinta_pieza();
	void rota_derecha();
	Coord posicion(int n) const;	//le paso un cuadrado (0 central, de 1 a 3 periferico) y me devuelve su coordenada
	void pieza_nueva();				//elije pieza al azar
};


#endif