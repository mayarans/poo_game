#include "interfaces/Alien.hpp"

Alien::Alien(const ObjetoDeJogo &obj, int velocidade) : Enemy(obj, velocidade) {}

void Alien::update() {
    switch (getState()) {
        case EnemyState::Idle:
            moveTo(getPosL(), getPosC());
            setState(EnemyState::MovingRight);
            break;

        case EnemyState::MovingLeft:
            moveLeft(getVelocidade());
            if (getPosC() == 0) {
                setState(EnemyState::MovingRight);
            }
            break;

        case EnemyState::MovingRight:
            moveRight(getVelocidade());
            if (getPosC() == 192) {
                setState(EnemyState::MovingLeft);
            }
            break;
    }

}