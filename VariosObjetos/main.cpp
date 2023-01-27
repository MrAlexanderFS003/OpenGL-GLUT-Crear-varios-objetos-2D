/*
	Hecho por Max Flores Saldaña , Usando la programación orientada a Objetos en C++.
	Si desea ver la documentacion de GLUT: https://www.opengl.org/resources/libraries/glut/spec3/spec3.html
*/

/// CODIGO REUTILIZADO DE https://github.com/MrAlexanderFS003/OpenGL-GLUT-Movimiento-de-la-figura-con-raton

#include "Cuadrado.h"
#include "Puntero.h"
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector> // Esta libreria nos ayudara a crear varios objetos de la clase que hallamos creado
#include <iostream>
using namespace std;

// Variables que usaremos para calcular la posicion de raton y el tamaño de la ventana
#define ANCHO 800
#define ALTO 600

//Objetos
Puntero punt;
Cuadrado cuad;
vector<Cuadrado>gen;//vector<Clase>Nombre del vector de objetos

//Variables usadas para almacenar los calculos obtenidos
float objX = 0.0f, objY = 0.0f, MobjX = 0.0f, MobjY = 0.0f;
int valor = 0,cont = 0;

void Iniciar() {
	glClearColor(0, 0, 0, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-50, 50, -50, 50);
}

void Dibuja() {
	glClear(GL_COLOR_BUFFER_BIT);

	punt.Dibuja();

	for (int i = 0; i < gen.size(); i++) {
		gen[i].Dibuja(); // Usando el tamaño del vector de objetos, dibujamos los objetos que este contenga almacenado
	}
	glutSwapBuffers();
}

void Actualiza() {
	glutPostRedisplay();
}

//Cambiar color del punto
void Teclado(unsigned char tecla, int x, int y) {
	switch (tecla) {
	case '1': // Rojo
		cuad.RGB(255,0,0);
		gen.push_back(cuad);
		break;
	case '2': // Anaranjado 
		cuad.RGB(255, 195, 0);
		gen.push_back(cuad);
		break;
	case '3': // Blanco
		cuad.RGB(253, 254, 254);
		gen.push_back(cuad);
		break;
	case '4': // Azul/Celeste
		cuad.RGB(93, 173, 226);
		gen.push_back(cuad);
		break;
	case '5': // Verde oscuro
		cuad.RGB(82, 190, 128);
		gen.push_back(cuad);
		break;
	//Cambios de Tamaño Punto/Cuadrado
	case 'j':
		punt.setRadio(1);
		cuad.setTam(10);
		gen.push_back(cuad);
		break;
	case 'k':
		punt.setRadio(3);
		cuad.setTam(15);
		gen.push_back(cuad);
		break;
	case 'l':
		punt.setRadio(5);
		cuad.setTam(20);
		gen.push_back(cuad);
		break;
	default:
		break;
	}
}

//Posicion del raton
void Raton(int btn, int state, int x, int y) {
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		objX = (x - (ANCHO / 2)) * 100 / ANCHO;
		objY = ((ALTO / 2) - y) * 100 / ALTO;
		cuad.setPosX(objX); // Objetenos la posicion en X del raton
		cuad.setPosY(objY); // Objetenos la posicion en Y del raton
		gen.push_back(cuad); // Guardamos los objetos creados 

		//Posicion del raton al Puntero
		punt.setPosX(objX);
		punt.setPosY(objY);

		MobjX = objX;
		MobjY = objY;
		valor = state;
	}

	if (btn == GLUT_RIGHT_BUTTON && state == GLUT_UP) {
		gen.clear(); //Al Precionar el bton derecho del raton limpiara el vector de objetos/ Borra la pantalla
	}
}

//Movimiento de la figura en base al raton
void MoverRaton(int x, int y) {
	if (valor) {
		cuad.setPosX(MobjX);
		cuad.setPosY(MobjY);
	}
	MobjX = (x - (ANCHO / 2)) * 100 / ANCHO;
	MobjY = ((ALTO / 2) - y) * 100 / ALTO;
	// Ahora por cada vez que el raton se mueve en X,Y guardaremos los
	// objetos que se vayan creando 
	cuad.setPosX(MobjX);
	cuad.setPosY(MobjY);
	gen.push_back(cuad);

	//Puntero que sigue el raton
	punt.setPosX(MobjX);
	punt.setPosY(MobjY);
}

int main() {
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(ANCHO, ALTO);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("GENERACION DE OBJETOS");

	Iniciar();
	glutDisplayFunc(Dibuja);
	glutKeyboardFunc(Teclado);
	glutMouseFunc(Raton); // Posicion del raton
	glutMotionFunc(MoverRaton); // Movimiento del raton
	glutIdleFunc(Actualiza);
	glutMainLoop();
	return 0;
}