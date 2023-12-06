#include "Alien.hpp"

Alien::Alien(const ObjetoDeJogo &obj, int life, int velAtaque) : Enemy(obj, life, velAtaque) {}

void Alien::update() {
    switch (getState()) {
        case EnemyState::Idle:
            moveTo(getPosL(), getPosC());
            setState(EnemyState::MovingRight);
            break;

        case EnemyState::MovingLeft:
            moveLeft(1);
            if (getPosC() == 0) {
                setState(EnemyState::MovingRight);
            }
            break;

        case EnemyState::MovingRight:
            moveRight(1);
            if (getPosC() == 154) {
                setState(EnemyState::MovingLeft);
            }
            break;
    }

}