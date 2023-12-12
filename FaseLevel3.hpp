#ifndef FASELEVEL3_HPP
#define FASELEVEL3_HPP

#include "ASCII_Engine/Fase.hpp"
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

class FaseLevel3 : public Fase
{
public:
    FaseLevel3(std::string name, const Sprite &bkg) : Fase(name,bkg) {}
    FaseLevel3(std::string name, const SpriteAnimado &bkg) : Fase(name,bkg) {}
    virtual ~FaseLevel3() {}

    virtual void init();
    virtual unsigned run(SpriteBuffer &screen);

    int getContEnemy() const { return countEnemy; }
    void setContEnemy(int num) { countEnemy = num; }
private:
    Spaceship *spaceship;
    Shot *shot[10];
    Alien *alien[12];
    Enemy *jellyfish[10];
    SpaceshipEnemy *spaceshipEnemy[3];
    TextSprite *life, *shots;
    ShotController *controller;
    ItemController *itemController;
    int countEnemy;

};

#endif // FASELEVEL3_HPP
