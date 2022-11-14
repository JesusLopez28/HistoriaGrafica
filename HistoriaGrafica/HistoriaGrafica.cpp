#include <iostream>
#include <algorithm>
#include <list>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Node.h"
#include "Game.h"
using namespace std;
using namespace sf;

int main(){
    Game* adventure;
    adventure = new Game(600, 600, "Aventura grafica");
    return 0;
}
