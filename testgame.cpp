#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Config.hpp>
#include <thread>
#include <cmath>
#include <cstdlib>
#include <math.h>
#include <string>
#include <windows.h>
#include <mmsystem.h>
#include <random>
#include <time.h>
#include <sstream>
#include <stdio.h>
#include <iostream>
#include <D:/progs/testgame/Objects.h>
#pragma comment(lib,"C:\\Users\\EVGEN\\Desktop\\texturesforputinshoooter\\winmm.lib")

using namespace sf;
namespace patch
{
    template < typename T > std::string to_string(const T& n)
    {
        std::ostringstream stm;
        stm << n;
        return stm.str();
    }
}


void func()
{
    mciSendString(TEXT("play C:\\Users\\EVGEN\\Desktop\\texturesforputinshoooter\\creedence-clearwater-revival_-_fortunate-son.mp3"), NULL, 0, NULL);
}


int main()
{
    RectangleShape cr(Vector2f(239, 79));
    cr.setFillColor(Color::Black);

    Object RPG;
    RPG.a = "C:\\Users\\EVGEN\\Desktop\\texturesforputinshoooter\\rpg.png";
    RPG.init();
    RPG.sprite.setPosition(1000, 1000);

    Object Boss;
    Boss.a = "C:\\Users\\EVGEN\\Desktop\\texturesforputinshoooter\\Boss.png";
    Boss.init();
    Boss.sprite.setPosition(1000, 1000);

    Object Napalm;
    Napalm.a = "C:\\Users\\EVGEN\\Desktop\\texturesforputinshoooter\\napalm1.png";
    Napalm.init();
    Napalm.sprite.setPosition(1000, 1000);

    Object Bomb;
    Bomb.a = "C:\\Users\\EVGEN\\Desktop\\texturesforputinshoooter\\bomb1.png";
    Bomb.init();
    Bomb.sprite.setPosition(1000, 1000);

    Object Boom;
    Boom.a = "C:\\Users\\EVGEN\\Desktop\\texturesforputinshoooter\\boom1.png";
    Boom.init();
    Boom.sprite.setPosition(1000, 1000);

    Object Tree;
    Tree.a = "C:\\Users\\EVGEN\\Desktop\\texturesforputinshoooter\\Tree1.sprite.png";
    Tree.init();

    Object Tree1;
    Tree1.a = "C:\\Users\\EVGEN\\Desktop\\texturesforputinshoooter\\Tree1.sprite.png";
    Tree1.init();
    Tree1.sprite.setPosition(1000, 1000);

    Object Background;
    Background.a = "C:\\Users\\EVGEN\\Desktop\\texturesforputinshoooter\\1548706982174921911.png";
    Background.init();
    Background.sprite.setPosition(0, 0);

    Object Viet;
    Viet.a = "C:\\Users\\EVGEN\\Desktop\\texturesforputinshoooter\\guk1.png";
    Viet.init();

    Object Viet1;
    Viet1.a = "C:\\Users\\EVGEN\\Desktop\\texturesforputinshoooter\\guk1.png";
    Viet1.init();

    Object Hero;
    Hero.a = "C:\\Users\\EVGEN\\Desktop\\texturesforputinshoooter\\test1.png";
    Hero.init();

    srand(time(0));
    int rec_x = 0, rec_y = 0, c = 120, d = 50, floor_y = 300, xtp = 640, xtp1 = -840, score = 0, bh = 3;
    bool vt = 1, vt1 = 1, crash = 0, bax = 0, bex = 0, hit = 1, shot = 0;
    double ran = 0, ran1 = 0, bs = 10, l, l1, l2, angle = 0, speed = 0, rb, xs, ys, ang;
    Viet.sprite.move(500, 250);
    Viet1.sprite.move(250, 250);
    RectangleShape floor(sf::Vector2f(1000, 60));
    floor.setFillColor(Color(0, 128, 0));
    floor.move(0, 300);
    Tree.sprite.setPosition(1000, 1000);
    Font font;
    font.loadFromFile("C:\\Users\\EVGEN\\Desktop\\texturesforputinshoooter\\GenJyuuGothicX-Bold.ttf");
    Text text("", font, 20);
    Text los("", font, 80);
    los.setPosition(170, 180);
    text.move(540, 0);
    los.setFillColor(Color::Red);
    text.setFillColor(Color::Black);
    RenderWindow window(sf::VideoMode(640, 480), "Vietnamese War");
    Clock clock;
    float time;
    time = clock.getElapsedTime().asMilliseconds();
    window.setVerticalSyncEnabled(true);
    //Hero.sprite.move(0,-150);
    Thread thread(&func);
    thread.launch();
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            while (true) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                };

                std::string s = patch::to_string(score);
                text.setString("score: " + s);
                los.setString("You lose!");
                cr.setPosition(Hero.sprite.getPosition().x, Hero.sprite.getPosition().y);
                if ((bex == 0) && (bs <= 0)) {
                    l2 = rand() % 640;
                    Boss.sprite.setPosition(l2, 250);
                    bex = 1;
                }
                if ((vt == 0) && (bex == 0)) {
                    l = rand() % 640;
                    if ((l <= Hero.sprite.getPosition().x + 200) && (l >= Hero.sprite.getPosition().x)) {
                        if (l - 200 < 0)l += 200;
                        else l -= 200;
                    }
                    Viet.sprite.setPosition(l, 250);
                    vt = 1;
                    if (ran == 0) {
                        ran = rand() % 100 - 50;
                        //std::cout<<ran;
                    };

                };
                if (ran < 0) {
                    Viet.sprite.move(0, -100);
                    Tree.sprite.setPosition(l, 150);
                    ran = 0;
                }
                if ((vt1 == 0) && (bex == 0)) {
                    l1 = rand() % 640;
                    if ((l1 <= Hero.sprite.getPosition().x + 200) && (l >= Hero.sprite.getPosition().x)) {
                        if (l1 - 200 < 0)l1 += 200;
                        else l1 -= 200;
                    }
                    Viet1.sprite.setPosition(l1, 250);
                    vt1 = 1;
                    if (ran1 == 0) {
                        ran1 = rand() % 100 - 50;
                        //std::cout<<ran1;
                    };

                };
                if (ran1 < 0) {
                    Viet1.sprite.move(0, -100);
                    Tree1.sprite.setPosition(l1, 150);
                    ran1 = 0;
                }
                if (Keyboard::isKeyPressed(Keyboard::Space)) {
                    if (bax == 1) {
                        Bomb.sprite.setPosition(Hero.sprite.getPosition().x + 75, Hero.sprite.getPosition().y + 30);
                        crash = 1;
                        bax = 0;
                    }
                };
                if (Keyboard::isKeyPressed(Keyboard::Left)) {
                    //Hero.sprite.move(-3, 0);
                    Hero.sprite.rotate(-1);
                };
                if (Keyboard::isKeyPressed(Keyboard::Right)) {
                    //Hero.sprite.move(3, 0);
                    Hero.sprite.rotate(1);
                };
                if (Keyboard::isKeyPressed(Keyboard::Up)) {
                    Hero.sprite.move(0, -3);
                };
                if (Keyboard::isKeyPressed(Keyboard::Down)) {
                    Hero.sprite.move(0, 3);
                };
                if (Keyboard::isKeyPressed(Keyboard::LShift)) {
                    if (Keyboard::isKeyPressed(Keyboard::Left)) {
                        Hero.sprite.move(-10, 0);
                    };
                    if (Keyboard::isKeyPressed(Keyboard::Right)) {
                        Hero.sprite.move(10, 0);
                    };
                    if (Keyboard::isKeyPressed(Keyboard::Up)) {
                        Hero.sprite.move(0, -10);
                    };
                    if (Keyboard::isKeyPressed(Keyboard::Down)) {
                        Hero.sprite.move(0, 10);
                    };
                };
                if (Hero.sprite.getPosition().y >= 150) {
                    while (Hero.sprite.getPosition().y <= 250) {
                        Hero.sprite.move(0, 1);
                        window.draw(Background.sprite);
                        window.draw(text);
                        window.draw(Tree.sprite);
                        window.draw(Tree1.sprite);
                        window.draw(Viet.sprite);
                        window.draw(Viet1.sprite);
                        window.draw(RPG.sprite);
                        window.draw(Boss.sprite);
                        window.draw(Hero.sprite);
                        window.draw(Boom.sprite);
                        window.draw(floor);
                        window.draw(los);
                        window.display();
                    }
                    Hero.sprite.setRotation(0);
                    Boom.sprite.setPosition(Hero.sprite.getPosition().x, Hero.sprite.getPosition().y);
                    window.draw(Background.sprite);
                    window.draw(text);
                    window.draw(Tree.sprite);
                    window.draw(Tree1.sprite);
                    window.draw(Viet.sprite);
                    window.draw(Viet1.sprite);
                    window.draw(RPG.sprite);
                    window.draw(Boss.sprite);
                    window.draw(Hero.sprite);
                    window.draw(Boom.sprite);
                    window.draw(floor);
                    window.draw(los);
                    window.display();
                    Sleep(1000);
                    return 0;
                }
                if (Hero.sprite.getPosition().x > xtp)Hero.sprite.move(xtp1, 0);
                if (Hero.sprite.getPosition().x < -200)Hero.sprite.move(840, 0);
                if (shot) {
                    RPG.sprite.move(-xs / 100, -ys / 100);
                }
                if ((shot == 1) && ((RPG.sprite.getPosition().x < 0) || (RPG.sprite.getPosition().x > 640) || (RPG.sprite.getPosition().y < -30)))shot = 0;
                if ((bex == 1) && (shot == 0)) {
                    RPG.sprite.setPosition(Boss.sprite.getPosition().x, Boss.sprite.getPosition().y);
                    xs = Boss.sprite.getPosition().x - Hero.sprite.getPosition().x - 75;
                    ys = Boss.sprite.getPosition().y - Hero.sprite.getPosition().y - 25;
                    if (xs > 0) {
                        ang = atan(ys / xs) * 180 / 3.14;
                    }
                    else {
                        ang = -180 + atan(ys / xs) * 180 / 3.14;
                    }
                    RPG.sprite.setRotation(ang);
                    shot = 1;

                    //std::cout<<ang<<'\n';
                }
                if ((hit == 0) && (Bomb.sprite.getPosition().x - 32 <= Boss.sprite.getPosition().x + 103) && (Bomb.sprite.getPosition().x + 28 > Boss.sprite.getPosition().x) && (Bomb.sprite.getPosition().y >= 277)) {
                    bh--;
                    hit = 1;
                    if (bh == 0) {
                        score += 10;
                        bh = 3;
                        Boss.sprite.move(1000, 1000);
                        RPG.sprite.move(1000, 1000);
                        bex = 0;
                        bs = rand() % 1000 - 100;
                    }
                }
                if ((Napalm.sprite.getPosition().x <= Viet.sprite.getPosition().x + 59) && (Napalm.sprite.getPosition().x + 60 > Viet.sprite.getPosition().x)) {
                    Viet.sprite.move(1000, 1000);
                    Tree.sprite.setPosition(1000, 2000);
                    ran = 0;
                    score++;
                    vt = 0;
                    bs = rand() % 1000 - 100;
                }
                if ((Napalm.sprite.getPosition().x <= Viet1.sprite.getPosition().x + 59) && (Napalm.sprite.getPosition().x + 60 > Viet1.sprite.getPosition().x)) {
                    Viet1.sprite.move(1000, 1000);
                    Tree1.sprite.setPosition(1000, 2000);
                    ran1 = 0;
                    score++;
                    vt1 = 0;
                    bs = rand() % 1000 - 100;
                }
                if (Bomb.sprite.getPosition().y < 280)Bomb.sprite.move(0, 3);
                if (Bomb.sprite.getPosition().y >= 280) {
                    Napalm.sprite.setPosition(Bomb.sprite.getPosition().x - 32, 256);
                    Bomb.sprite.move(-1000, -1000);
                    bax = 1;
                    hit = 0;
                }
                angle = Hero.sprite.getRotation();
                if (angle > 270) {
                    angle -= 360;
                }
                else if ((angle > 90) && (angle < 270)) {
                    while (Hero.sprite.getPosition().y <= 250) {
                        Hero.sprite.move(0, 1);
                        window.draw(Background.sprite);
                        window.draw(text);
                        window.draw(Tree.sprite);
                        window.draw(Tree1.sprite);
                        window.draw(Viet.sprite);
                        window.draw(Viet1.sprite);
                        window.draw(RPG.sprite);
                        window.draw(Boss.sprite);
                        window.draw(Bomb.sprite);
                        window.draw(Hero.sprite);
                        window.draw(Boom.sprite);
                        window.draw(floor);
                        window.draw(los);
                        window.display();
                    }
                    Hero.sprite.setRotation(0);
                    Boom.sprite.setPosition(Hero.sprite.getPosition().x, Hero.sprite.getPosition().y);
                    window.draw(Background.sprite);
                    window.draw(text);
                    window.draw(Tree.sprite);
                    window.draw(Tree1.sprite);
                    window.draw(Viet.sprite);
                    window.draw(Viet1.sprite);
                    window.draw(RPG.sprite);
                    window.draw(Boss.sprite);
                    window.draw(Hero.sprite);
                    window.draw(Boom.sprite);
                    window.draw(floor);
                    window.draw(los);
                    window.display();
                    Sleep(1000);
                    return 0;
                }
                if (angle == 0)speed = 0;
                if (angle != 0) {
                    speed = angle / 360 * 100;
                }
                Hero.sprite.move(speed, 0);
                //std::cout<<angle<<" ";
                //window.clear();
                window.draw(Background.sprite);
                window.draw(text);
                window.draw(Tree.sprite);
                window.draw(Tree1.sprite);
                window.draw(Viet.sprite);
                window.draw(Viet1.sprite);
                window.draw(RPG.sprite);
                window.draw(Boss.sprite);
                window.draw(Bomb.sprite);
                window.draw(Napalm.sprite);
                window.draw(Hero.sprite);
                window.draw(Boom.sprite);
                window.draw(floor);
                window.display();
                int r = 100;
                if ((shot == 1) && (RPG.sprite.getPosition().y <= Hero.sprite.getPosition().y + 70) && (RPG.sprite.getPosition().x >= Hero.sprite.getPosition().x + 50) && (RPG.sprite.getPosition().x <= Hero.sprite.getPosition().x + 100)) {
                    Hero.sprite.setRotation(0);
                    RPG.sprite.setPosition(1000, 1000);
                    while (Hero.sprite.getPosition().y <= 250) {
                        Hero.sprite.move(0, 1);
                        Boom.sprite.setPosition(Hero.sprite.getPosition().x, Hero.sprite.getPosition().y);
                        window.draw(Background.sprite);
                        window.draw(text);
                        window.draw(Tree.sprite);
                        window.draw(Tree1.sprite);
                        window.draw(Viet.sprite);
                        window.draw(Viet1.sprite);
                        window.draw(RPG.sprite);
                        window.draw(Boss.sprite);
                        window.draw(Bomb.sprite);
                        window.draw(Hero.sprite);
                        window.draw(Boom.sprite);
                        window.draw(floor);
                        window.draw(los);
                        window.display();
                    }
                    Hero.sprite.setRotation(0);
                    Boom.sprite.setPosition(Hero.sprite.getPosition().x, Hero.sprite.getPosition().y);
                    window.draw(Background.sprite);
                    window.draw(text);
                    window.draw(Tree.sprite);
                    window.draw(Tree1.sprite);
                    window.draw(Viet.sprite);
                    window.draw(Viet1.sprite);
                    window.draw(RPG.sprite);
                    window.draw(Boss.sprite);
                    window.draw(Hero.sprite);
                    window.draw(Boom.sprite);
                    window.draw(floor);
                    window.draw(los);
                    window.display();
                    Sleep(1000);
                    return 0;
                    /*for (int i = 0; i < 360; i++)
                    {
                        double rad = (double)i / 180 * 3.14;
                        double x = r * cos(rad);
                        double y = r * sin(rad);
                        x = int(x) + Hero.sprite.getPosition().x + 100;
                        y = int(y) + Hero.sprite.getPosition().y + 100;
                        for (int a = 0; a <= c; a++) {
                            for (int b = 0; b <= d; b++) {
                                rec_x = a + 300;
                                rec_y = b + 30;
                                if ((x>=RPG.sprite.getPosition().x)&&(x<=RPG.sprite.getPosition().x+50)&&(y>=RPG.sprite.getPosition().y+100)&&(y<=RPG.sprite.getPosition().y+200)) {
                                    RPG.sprite.move(1000,1000);
                                    shot=0;
                                    while(Hero.sprite.getPosition().y<=250){
                            Hero.sprite.move(0,1);
                            window.draw(Background.sprite);
                            window.draw(text);
                            window.draw(Tree.sprite);
                            window.draw(Tree1.sprite);
                            window.draw(Viet.sprite);
                            window.draw(Viet1.sprite);
                            window.draw(RPG.sprite);
                            window.draw(Boss.sprite);
                            window.draw(Bomb.sprite);
                            window.draw(cr);
                            window.draw(Hero.sprite);
                            window.draw(Boom.sprite);
                            window.draw(floor);
                            window.draw(los);
                            window.display();
                        }
                        Hero.sprite.setRotation(0);
                        Boom.sprite.setPosition(Hero.sprite.getPosition().x,Hero.sprite.getPosition().y);
                        window.draw(Background.sprite);
                        window.draw(text);
                        window.draw(Tree.sprite);
                        window.draw(Tree1.sprite);
                        window.draw(Viet.sprite);
                        window.draw(Viet1.sprite);
                        window.draw(RPG.sprite);
                        window.draw(Boss.sprite);
                        window.draw(cr);
                        window.draw(Hero.sprite);
                        window.draw(Boom.sprite);
                        window.draw(floor);
                        window.draw(los);
                        window.display();
                        Sleep(1000);
                        return 0;
                                };
                            }
                        };
                    };*/
                };

            };
        }
    }
}
