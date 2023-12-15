#ifndef FASELEVEL2_HPP
#define FASELEVEL2_HPP

#include "../ASCII_Engine/Fase.hpp"
#include "../ASCII_Engine/Sound.hpp"
#include "Spaceship.hpp"
#include "Enemy.hpp"
#include "ShotController.hpp"
#include "Jellyfish.hpp"
#include "Alien.hpp"
#include "SpaceshipEnemy.hpp"
#include "Shot.hpp"
#include "Alien.hpp"
#include "Jellyfish.hpp"
#include "ItemController.hpp"

class FaseLevel2 : public Fase
{
public:
    FaseLevel2(std::string name, const Sprite &bkg) : Fase(name,bkg) {}
    FaseLevel2(std::string name, const SpriteAnimado &bkg) : Fase(name,bkg) {}
    virtual ~FaseLevel2() {}

    virtual void init();
    virtual unsigned run(SpriteBuffer &screen);

    int getContEnemy() const { return countEnemy; }
    void setContEnemy(int num) { countEnemy = num; }
private:
    Spaceship *spaceship;
    Alien *alien[10];
    Enemy *jellyfish[8];
    TextSprite *life, *shots;
    ShotController *controller;
    ItemController *itemController;
    int countEnemy;
    Sound *shooting, *enemyKill, *catchItemSound, *catchBombSound;
};

#endif // FASELEVEL2_HPP
