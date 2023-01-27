#include "Puntero.h"
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

void Puntero::Dibuja() {
	glPushMatrix();
	glColor3ub(255, 255, 255);
	glTranslatef(posX, posY, 0);
	glBegin(GL_LINE_STRIP);
	for (float i = 0; i < 20; i += 0.1f) {
		posXC = radio * cos(i);
		posYC = radio * sin(i);
		glVertex2f(posXC, posYC);
	}
	glEnd();
	glPopMatrix();
}

void Puntero::Actualiza() {
	glutPostRedisplay();
}