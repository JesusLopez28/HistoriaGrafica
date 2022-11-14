#pragma once
#include <iostream>
#include <algorithm>
#include <list>
#include <fstream>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Node.h"
#include "Game.h"

using namespace std;
using namespace sf;


Game::Game(int width, int height, string title){
	Fill();
	fps = 60;
	window = new RenderWindow(VideoMode(width, height), title);
	window->setFramerateLimit(fps);
	GameLoop();
}

void Game::GameLoop(){
	Texture texture;
	Sprite sprite;
	texture.loadFromFile("imagenes/ini.jpg");
	sprite.setTexture(texture);
	Music musica;
	musica.openFromFile("canciones/in.ogg");
	musica.setLoop(true);
	while (window->isOpen()) {
		musica.play();
		Event event;
		while (window->pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window->close();
		}
		window->clear();
		window->draw(sprite);
		window->display();
		system("cls");
		cout << "----------Proyecto Parcial 3 POO----------" << endl;
		cout << "Jesus Alejandro Lopez Rosales-22110104-2|O\n\n" << endl;
		system("pause");
		system("cls");
		musica.stop();
		Draw();
	}
}

void Game::Draw(){
	unsigned int opc;
	string election;
	Texture texture;
	Sprite sprite;
	texture.loadFromFile("imagenes/fin.jpg");
	sprite.setTexture(texture);
	Node* actual = new Node("aux");
	Node* inicial = new Node("aux");
	actual = Vivir;
	inicial = Vivir;
	Music sonido;
	while (!actual->matrix.empty()){
		sonido.openFromFile(actual->GetMusic());
		sonido.setLoop(true);
		sonido.play();
		window->clear();
		window->draw(actual->GetScreen());
		window->display();
		system("cls");
		cout << "Que camino deseas elegir?" << endl;
		for (auto x : actual->matrix) {
			if (x->GetName() == "Fin") {
				system("cls");
				cout << "Que camino deseas elegir?" << endl;
				cout << "Fin" << endl;
			}else cout << "-" << x->GetName() << endl;
		}cout << endl;
		cout << "Escribe tu eleccion: ";
		cin >> election;
		for_each(actual->matrix.begin(), actual->matrix.end(), [&actual, election](Node* siguiente) {
			if (siguiente->GetName() == election) actual = siguiente;
			});	
		
		window->clear();
	}
	system("cls");
	cout << "Deseas volver a jugar?" << endl;
	cout << "0.-No" << endl;
	cout << "1.-Si" << endl;
	cout << "Elige una opcion: ";
	cin >> opc;
	sonido.stop();
	if (opc == 1) actual = inicial;
	else {
		sonido.openFromFile("canciones/fi.ogg");
		sonido.setLoop(true);
		sonido.play();
		window->clear();
		window->draw(sprite);
		window->display();
		system("cls");
		cout << "FIN DEL JUEGO" << endl;
		system("pause");
		sonido.stop();
		window->close();
	}
}

void Game::Fill(){
	Vivir->SetScreen("vid");Morir->SetScreen("mor");Nacer->SetScreen("nac");Lujuria->SetScreen("luj");Abstenerse->SetScreen("abs");Gula->SetScreen("gul");Evitar->SetScreen("evi");Avaricia->SetScreen("ava");Generosidad->SetScreen("gen");Ira->SetScreen("ira");Calma->SetScreen("cal");Herejia->SetScreen("her");Ortodoxia->SetScreen("ort");Violencia->SetScreen("vio");Paz->SetScreen("paz");Mentira->SetScreen("men");Verdad->SetScreen("ver");Traicion->SetScreen("tra");Cielo->SetScreen("cie");Fin->SetScreen("fin");
	Vivir->SetMusic("vi");Morir->SetMusic("mo");Nacer->SetMusic("na");Lujuria->SetMusic("lu");Abstenerse->SetMusic("ab");Gula->SetMusic("gu");Evitar->SetMusic("ev");Avaricia->SetMusic("av");Generosidad->SetMusic("ge");Ira->SetMusic("ir");Calma->SetMusic("ca");Herejia->SetMusic("he");Ortodoxia->SetMusic("or");Violencia->SetMusic("ia");Paz->SetMusic("pa");Mentira->SetMusic("me");Verdad->SetMusic("ve");Traicion->SetMusic("tr");Cielo->SetMusic("ci");Fin->SetMusic("fi");
	Vivir->matrix = {Nacer,Morir};Morir->matrix = {Fin,Fin};Nacer->matrix = {Abstenerse,Lujuria};Lujuria->matrix = {Fin,Fin};Abstenerse->matrix = {Evitar,Gula};Gula->matrix = { Fin,Fin};Evitar->matrix = {Generosidad,Avaricia};Avaricia->matrix = {Fin,Fin};Generosidad->matrix = {Calma,Ira};Ira->matrix = {Fin,Fin};Calma->matrix = {Ortodoxia,Herejia};Herejia->matrix = {Fin,Fin};Ortodoxia->matrix = {Paz,Violencia};Violencia->matrix = {Fin,Fin};Paz->matrix = {Verdad,Mentira};Mentira->matrix = {Fin,Fin};Verdad->matrix = {Cielo,Traicion};Traicion->matrix = {Fin,Fin};Cielo->matrix = {Fin,Fin};Fin->matrix = {};
/*string name, imagen, musica, seguir, final;
ifstream txt;
txt.open("Datos.txt", ios::in);
while (!txt.eof()) {
	txt >> name >> imagen >> musica >> seguir >> final;
	imagen = "imagenes/" + imagen + ".jpg";
	musica = musica + ".ogg";
	Node* nodo = new Node(name);
	nodo->SetScreen(imagen);
	nodo->SetMusic(musica);
	Node* sigue = new Node(seguir);
	Node* fin = new Node(final);
	nodo->matrix = { sigue, fin };
}*/
}
