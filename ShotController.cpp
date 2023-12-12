#include "ShotController.hpp"

ShotController::ShotController(const ObjetoDeJogo &obj) : ObjetoDeJogo(obj){
}

ShotController::~ShotController() {
    for (auto shot : shots) {
        delete shot;
    }
}

void ShotController::update() {
    for (auto shot : shots) {
        if (shot->getDir() == 1) {
            shot->moveUp(shot->getVelShot());
        } else {
            shot->moveDown(shot->getVelShot());
        }
    }
}

void ShotController::createShot(int posL, int posC, int velShot, int dir, int intensidade) {
    newShot = new Shot(ObjetoDeJogo("Shot", Sprite("rsc_2/shot.img"), posL, posC), velShot, dir, intensidade);
    newShot->ativarObj();
    shots.push_back(newShot);
}

int ShotController::verificaColisao(const std::list<ObjetoDeJogo*> objs) {
    for (auto obj : objs) {
        for (auto shot : shots) {
            if (shot->getDir() != 1 && (shot->colideCom(*obj) && obj->getName() == "Spaceship")) {
                shot->desativarObj();
                Spaceship *spaceship = dynamic_cast<Spaceship *> (obj);
                spaceship->sofrerAtaque(shot->getIntensidade());
                return 0;
            } else if (shot->getDir() == 1 && (shot->colideCom(*obj) && (obj->getName() == "Alien" || obj->getName() == "Jellyfish" || obj->getName() == "SpaceshipEnemy"))) {
                shot->desativarObj();
                obj->desativarObj();
                return 1;
            } else if (shot->getDir() == 1 && (shot->colideCom(*obj) && obj->getName() == "Barreira")) {
                shot->desativarObj();
                obj->desativarObj();
                return 2;
            }
        }

    }
    return 2;
}

void ShotController::draw(SpriteBase &screen, unsigned x, unsigned y) {
    for (auto shot : shots) {
        shot->draw(screen, shot->getPosL(), shot->getPosC());
    }
}