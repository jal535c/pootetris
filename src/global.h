#ifndef __GLOBAL_H__
#define __GLOBAL_H__


const int TAM=25;	//tamaño de cada cuadrado, 25 pixeles

const int FILAS=20;		//tamaño del tablero en cuadrados, 
const int COLUMNAS=10;	//el tablero es un array que tiene en cada posicion el color, negro=0=vacio


void cuadrado(int , int );		//funcion usada por Pieza y Tablero. La funcion rota_derecha_c solo la usa Pieza


struct Coord {
	int x, y;
};


const Coord perifs[7][3] = {		//coordenadas de los bloques perifericos
	{ {1,0}, {0,1}, {1,1} },		//cuadrado, azul
	{ {1,0}, {-1,1}, {0,1} },		//s, cian
	{ {0,1}, {1,1}, {-1,0} },		//2, naranja
	{ {0,1}, {0,-1}, {1,1} },		//L, magenta
	{ {0,1}, {0,-1}, {-1,1} },		//Lr, amarillo
	{ {-1,0}, {1,0}, {0,1} },		//T, verde
	{ {0,1}, {0,-1}, {0,2} },		//palo, rojo
};


#endif