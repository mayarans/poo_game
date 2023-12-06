#ifndef FASELEVEL1_HPP
#define FASELEVEL1_HPP

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

class FaseLevel1 : public Fase
{
public:
    FaseLevel1(std::string name, const Sprite &bkg) : Fase(name,bkg) {}
    FaseLevel1(std::string name, const SpriteAnimado &bkg) : Fase(name,bkg) {}
    virtual ~FaseLevel1() {}

    virtual void init();
    virtual unsigned run(SpriteBuffer &screen);

    int getContEnemy() const { return countEnemy; }
    void setContEnemy(int num) { countEnemy = num; }
private:
    Spaceship *spaceship;
    Shot *shot[10];
    Alien *alien[4];
    Enemy *jellyfish[3];
    TextSprite *life, *shots;
    ShotController *controller;
    int countEnemy;
//
//	enum {RIDING, PRACING, END};

};

#endif // FASESTART_HPP




//#ifndef FASELEVEL1_HPP
//#define FASELEVEL1_HPP
//
//#include "ASCII_Engine/Fase.hpp"
//#include <string>
//#include <list>
//
//#include "Enemy.hpp"
//
//class FaseLevel1 : public Fase
//{
//public:
//	FaseLevel1(std::string name, const Sprite &bkg) : Fase(name,bkg) {}
//	FaseLevel1(std::string name, const SpriteAnimado &bkg) : Fase(name,bkg) {}
//	virtual ~FaseLevel1() {}
//
//
//	virtual void init();
//	virtual unsigned run(SpriteBuffer &screen);
//
//	bool colideComBloco() const;
//
//private:
//	Enemy *guardas[2];
//	ObjetoDeJogo *tapetePorta;
//	ObjetoDeJogo *portao;
//	ObjetoDeJogo *chave;
//	ObjetoDeJogo *miniChave;
//	ObjetoDeJogo *princesa;
//
//	TextSprite *life;
//
//	std::list<ObjetoDeJogo*> colisoes;
//};
//
//#endif // FASELEVEL1_HPP
