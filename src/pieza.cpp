#include <pieza.h>
#include <cstdlib>
#include <miniwin.h>
//#include <global.h>

/*
const Coord perifs[7][3] = {		//coordenadas de los bloques perifericos
	{ {1,0}, {0,1}, {1,1} },		//cuadrado, azul
	{ {1,0}, {-1,1}, {0,1} },		//s, cian
	{ {0,1}, {1,1}, {-1,0} },		//2, naranja
	{ {0,1}, {0,-1}, {1,1} },		//L, magenta
	{ {0,1}, {0,-1}, {-1,1} },		//Lr, amarillo
	{ {-1,0}, {1,0}, {0,1} },		//T, verde
	{ {0,1}, {0,-1}, {0,2} },		//palo, rojo
};
*/

void cuadrado(int x, int y) {
	miniwin::rectangulo_lleno(1+x*TAM, 1+y*TAM, x*TAM+TAM, y*TAM+TAM);	//+1 es para ver la separacion entre los 4 cuadrados
}


Coord Pieza::posicion(int n) const {
	Coord ret = { orig.x, orig.y };		//le asigno el cuadrado referencia
	if (n!=0) {
		ret.x += perif[n-1].x;
		ret.y += perif[n-1].y;
	}
	return ret;
}

void Pieza::pinta_pieza() {		//pone color y pinta 4 cuadrados
	miniwin::color(micolor);
	for (int i=0; i<4; i++) {
		Coord c = posicion(i);
		cuadrado(c.x, c.y);
	}
}


Coord rota_derecha_c(const Coord& c) {		//para rotar intercambia x e y, y cambia signo a x: x = -y, y = x
	Coord ret = { -c.y, c.x };
	return ret;
}


void Pieza::rota_derecha() {			//polimorfismo: depende del parametro usa una u otra
	for (int i = 0; i < 3; i++) {
		perif[i] = rota_derecha_c(perif[i]);
	}
}

void Pieza::pieza_nueva() {
	orig.x = 5; 
	orig.y = 3;

	micolor = 1 + rand()%6;

	//pieza al azar
	int r = rand() %7;		//elijo una fila de mi matriz perifs
	for (int i=0; i<3; i++) {
		perif[i] = perifs[r][i];
	}
}