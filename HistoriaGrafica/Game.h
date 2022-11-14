#pragma once
#include <iostream>
#include <algorithm>
#include <list>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Node.h"
using namespace std;
using namespace sf;

class Game{
public:
	Game(int width, int height, string title);
	void GameLoop();
	void Draw();
	void Fill();
	Node* Vivir = new Node("Vivir");
	Node* Morir = new Node("Morir");
	Node* Nacer = new Node("Nacer");
	Node* Lujuria = new Node("Lujuria");
	Node* Abstenerse = new Node("Abstenerse");
	Node* Gula = new Node("Gula");
	Node* Evitar = new Node("Evitar");
	Node* Avaricia = new Node("Avaricia");
	Node* Generosidad = new Node("Generosidad");
	Node* Ira = new Node("Ira");
	Node* Calma = new Node("Calma");
	Node* Herejia = new Node("Herejia");
	Node* Ortodoxia = new Node("Ortodoxia");
	Node* Violencia = new Node("Violencia");
	Node* Paz = new Node("Paz");
	Node* Mentira = new Node("Mentira");
	Node* Verdad = new Node("Verdad");
	Node* Traicion = new Node("Traicion");
	Node* Cielo = new Node("Cielo");
	Node* Fin = new Node("Fin");
private:
	RenderWindow* window;
	int fps;
};

