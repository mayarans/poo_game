#ifndef FASESTART_HPP
#define FASESTART_HPP

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
#include "ASCII_Engine/Sound.hpp"

class FaseStart : public Fase
{
public:
	FaseStart(std::string name, const Sprite &bkg) : Fase(name,bkg) {}
	FaseStart(std::string name, const SpriteAnimado &bkg) : Fase(name,bkg) {}
	virtual ~FaseStart() {}
	
	virtual void init();
	virtual unsigned run(SpriteBuffer &screen);

    int getContEnemy() const { return countEnemy; }
    void setContEnemy(int num) { countEnemy = num; }
private:
	 Spaceship *spaceship;
     TextSprite *life, *shots;
     ShotController *controller;
     int countEnemy;
     Sound *shooting, *enemyKill;
};

#endif // FASESTART_HPP
