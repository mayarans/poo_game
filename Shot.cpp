#include "Shot.hpp"

Shot::Shot(const ObjetoDeJogo &obj, int velShot, int dir, int intensidade) : velShot(velShot), dir(dir), intensidade(intensidade), ObjetoDeJogo(obj) {}

void Shot::update() {
    if (dir == 1) {
        moveUp(velShot);
    } else {
        moveDown(velShot);
    }
}
