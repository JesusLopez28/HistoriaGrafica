#pragma once
#include <iostream>
#include <algorithm>
#include <list>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp" 
using namespace std;
using namespace sf;

class Node{
public:
	Node(string name);
	string GetName();
	void SetMusic(string cancion);
	string GetMusic();
	void SetScreen(string img);
	Sprite GetScreen();
	list<Node*> matrix;
private:
	string name;
	Texture texture;
	Sprite sprite;
	string img;
	string cancion;
};

