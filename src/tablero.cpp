#include <tablero.h>
#include <pieza.h>
#include <miniwin.h>


void Tablero::vacia() {		//rellena todo el tablero de negro
	for (int i=0; i<COLUMNAS; i++)
		for (int j=0; j<FILAS; j++)
			Tam[i][j] = miniwin::NEGRO;		//negro = 0 = casilla vacia
}


void Tablero::pinta() {		//es como refresca. Yo tengo en T los colores, pero ahora tengo k pintar
	for (int i=0; i<COLUMNAS; i++) { 
		for (int j=0; j<FILAS; j++) {
			miniwin::color(Tam[i][j]);
			cuadrado(i,j);		
		}
	}
}


void Tablero::incrusta_pieza(const Pieza& P) {		//mete las coordenadas de la pieza en el tablero
	for (int i=0; i<4; i++) {
		Coord c = P.posicion(i);
		Tam[c.x][c.y] = P.micolor;
	}
}


bool Tablero::colision(const Pieza& P) {		//me indica si hay colision
	for (int i=0; i<4; i++) {
		Coord c = P.posicion(i);

		//comprobar limites
		if (c.x < 0 || c.x >= COLUMNAS)
			return true;

		if (c.y < 0 || c.y >= FILAS)
			return true;

		//mirar basurilla
		if (Tam[c.x][c.y] != miniwin::NEGRO)
			return true;
	}

	return false;
}


bool Tablero::fila_llena(int fila) {		//para saber si hay una fila completa
	for (int i=0; i< COLUMNAS; i++) {
		if (Tam[i][fila] == miniwin::NEGRO) 
			return false;
	}
	return true;
}


void Tablero::colapsa(int fila) {		//cuando hay linea, la basurilla debe bajar
	for (int j=fila; j>0; j--) {
		for (int i=0; i<COLUMNAS; i++) {
			Tam[i][j] = Tam[i][j-1];					//debo poner en la k estoy lo k halla en la anterior
		}
	}

	//vaciar la de arriba, ponerla negra
	for (int i=0; i<COLUMNAS; i++) {
		Tam[i][0] = miniwin::NEGRO;
	}
}


int Tablero::cuenta_lineas() {		//y si hago 2 lineas a la vez? debo quitar todas las lineas k haga
	int fila = FILAS-1, cont=0;
	while (fila>=0) {
		if (fila_llena(fila)) {
			colapsa(fila);
			cont++;
		} else {
			fila--;
		}
	}
	return cont;		//el contador es para k me den mas puntos si hago varias lineas
}