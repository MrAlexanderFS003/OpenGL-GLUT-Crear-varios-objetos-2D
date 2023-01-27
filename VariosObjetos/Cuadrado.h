class Cuadrado {
	float posX = 0.0f, posY = 0.0f;
	float r = 82.0f, g = 190.0f, b = 128.0f;
	int tam = 10;
public:
	Cuadrado(){}
	void Dibuja();
	void Actualiza();

	// Setters y Getters
	void setPosX(float valor) { posX = valor; }
	void setPosY(float valor) { posY = valor; }

	float getPosX() { return posX; }
	float getPosY() { return posY; }

	void setR( float valor) { r = valor; }
	void setG( float valor) { g = valor; }
	void setB( float valor) { b = valor; }

	void RGB(float rojo, float verde, float azul) { r = rojo; g = verde; b = azul; }

	void setTam(int valor) { tam = valor; }
};