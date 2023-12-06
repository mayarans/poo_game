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

void ShotController::createShot(int posL, int posC, int velShot, int dir) {
    newShot = new Shot(ObjetoDeJogo("Shot", Sprite("rsc_2/shot.img"), posL, posC), velShot, dir);
    newShot->ativarObj();
    shots.push_back(newShot);
}

void ShotController::ativarObj() {
   newShot->ativarObj();
}

bool ShotController::verificaColisao(const std::list<ObjetoDeJogo*> objs) {
    for (auto obj : objs) {
        for (auto shot : shots) {
            if (shot->colideCom(*obj) && (obj->getName() == "Alien" || obj->getName() == "Jellyfish" || obj->getName() == "SpaceshipEnemy")) {
                shot->desativarObj();
                obj->desativarObj();
                return true;
            }
        }

    }
    return false;
}

void ShotController::draw(SpriteBase &screen, unsigned x, unsigned y) {
    for (auto shot : shots) {
        shot->draw(screen, shot->getPosL(), shot->getPosC());
    }
}