#ifndef SHOT_CONTROLLER_HPP
#define SHOT_CONTROLLER_HPP

#include "ASCII_Engine/ObjetoDeJogo.hpp"
#include "Shot.hpp"
#include <list>

class ShotController : public ObjetoDeJogo {
public:
    ShotController(const ObjetoDeJogo &obj);

    virtual ~ShotController();

    void update();

    void createShot(int posL, int posC, int velShot, int dir);

    void ativarObj();

    bool verificaColisao(const std::list<ObjetoDeJogo*> objs);

    void draw(SpriteBase &screen, unsigned x, unsigned y);


private:
    std::list<Shot*> shots;
    Shot *newShot;

};

#endif // HERO_HPP