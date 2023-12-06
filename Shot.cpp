#include "Shot.hpp"

Shot::Shot(const ObjetoDeJogo &obj, int velShot, int dir) : velShot(velShot), dir(dir), ObjetoDeJogo(obj) {}

void Shot::update() {
    if (dir == 1) {
        moveUp(velShot);
    } else {
        moveDown(velShot);
    }
}
