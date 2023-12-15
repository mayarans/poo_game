#ifndef SHOT_CONTROLLER_HPP
#define SHOT_CONTROLLER_HPP

#include "../ASCII_Engine/ObjetoDeJogo.hpp"
#include "Shot.hpp"
#include "Spaceship.hpp"
#include <list>

class ShotController : public ObjetoDeJogo {
public:
    ShotController(const ObjetoDeJogo &obj);

    virtual ~ShotController();

    void update();

    void createShot(int posL, int posC, int velShot, int dir, int intensidade = 10);

    int verificaColisao(const std::list<ObjetoDeJogo*> objs);

    void draw(SpriteBase &screen, unsigned x, unsigned y);

    bool shotsAtivos();

private:
    std::list<Shot*> shots;
    Shot *newShot;

};

#endif // SHOT_CONTROLLER_HPP
