#include <iostream>
#include <algorithm>
#include <list>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Node.h"
using namespace std;
using namespace sf;

Node::Node(string name){
	this->name = name;
}

string Node::GetName(){
	return name;
}

void Node::SetMusic(string cancion){
	this->cancion = "canciones/" + cancion + ".ogg";
}

string Node::GetMusic() {
	return cancion;
}

void Node::SetScreen(string img){
	texture.loadFromFile("imagenes/" + img + ".jpg");
	sprite.setTexture(texture);
}

Sprite Node::GetScreen(){
	return sprite;
}
