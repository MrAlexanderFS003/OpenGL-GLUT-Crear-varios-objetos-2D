# LIBRERIA VECTOR

Este Libreria nos va ayudar a poder crear varios objetos de una clase, dicha clase puede ser la que usted le convenga, puede ser un modelo (.obj, .md2, etc), figuras
geométricas (hechos con primitivas), entre otros. Para su uso solo se a considerado dos cosas , la creacion y la insercion, en otras palabras cuando creamos un cambio ya 
sea pasando valores atraves de los getters y setters, tenemos que almacenarlo en el vector de objetos. Por ejemplo:

```C++
#include "Ejemplo.h"
#include <vector>
#include <iostream>
using namespace std;

Ejemplo ejm;
//vector<Clase>Nombre del vector
vector<Ejemplo>GenEjm;

void Actualiza(){
  //Cambiamos la posicion del objeto
  ejm.setPosX(10);
  ejm.setPosY(30);
  //Almacenamos este objeto con la posicion modificada en el vector "GenEjm"
  GenEjm.push_back(ejm); // Agrega un elemento al final del vector.
}

void Dibuja(){
  // Para dibujar los objetos que estan almacenados en el vector
  // Usaremos un bucle "for" y también "GenEjm.size()" que vendria ser el tamaño del vector, entonces :
  for(int i = 0; i < GenEjm.size(); i++){
    GenEjm[i].Dibuja(); //De esta forma Dibujaremos cada Objeto almacenado del vector
  }
}
```

------------

# CONTROLES 
> Raton 🐁 :
- Click Izquierdo (Pinta).
- Click Derecho (Limpia Pantalla/Borrar todo).
> Teclado (Minuscula) ⌨️ :
- Colores 🎨
  - Tecla [1] (Color rojo) 🟥.
  - Tecla [2] (Color Anaranjado) 🟧.
  - Tecla [3] (Color Blanco) ⬜.
  - Tecla [4] (Color Azul/Celeste) 🟦.
  - Tecla [5] (Color Verde oscuro) 🟩.
- Tamaño (Tamaño del radio del circulo/Puntero, tamaño del cuadrado) 
  - Tecla [j] (radio: 1, tamaño Cuadrado: 10).
  - Tecla [k] (radio: 3, tamaño Cuadrado: 15).
  - Tecla [m] (radio: 5, tamaño Cuadrado: 20).
------------

# Paint Básico

Para no ir tan rápido, observemos el main.cpp y pongamos en comentario los siguiente "glutMotionFunc(MoverRaton);"
```C++
int main() {
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(ANCHO, ALTO);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("GENERACION DE OBJETOS");

	Iniciar();
	glutDisplayFunc(Dibuja);
	glutKeyboardFunc(Teclado);
	glutMouseFunc(Raton); // Posicion del raton
	//glutMotionFunc(MoverRaton); // Movimiento del raton
	glutIdleFunc(Actualiza);
	glutMainLoop();
	return 0;
}
```

Entonces el programa quedaria de esta forma:

![1er](https://user-images.githubusercontent.com/96871746/215227490-4632dee0-b700-4ae1-ae73-640e1df2aa88.gif)

Quitando lo anterior tendriamos lo siguiente :

![2do](https://user-images.githubusercontent.com/96871746/215229996-c32798d4-3be2-4ebb-b561-e132b891a885.gif)

# PROYECTO BASE EN EJECUCIÓN

![Paint](https://user-images.githubusercontent.com/96871746/215229810-6f0cd14d-4f3d-4e37-9dab-16928aaf61c5.gif)
