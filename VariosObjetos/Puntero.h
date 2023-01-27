class Puntero {
	float posXC = 0.0f, posYC = 0.0f;
	float posX = 0.0f, posY = 0.0f;
	int radio = 1;
public:
	Puntero(){}
	void Dibuja();
	void Actualiza();

	// Setters y Getters
	void setPosX(float valor) { posX = valor; }
	void setPosY(float valor) { posY = valor; }

	float getPosX() { return posX; }
	float getPosY() { return posY; }

	void setRadio(int valor) { radio = valor; }
};
