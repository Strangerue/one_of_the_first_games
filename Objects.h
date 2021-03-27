#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Config.hpp>
#include <windows.h>
#include <string>

using namespace sf;

class Object
{
    public:
        String a;
        Image img;
        Texture texture;
        Sprite sprite;
        void init() {
            img.loadFromFile(a);
            texture.loadFromImage(img);
            sprite.setTexture(texture);
        }
};

