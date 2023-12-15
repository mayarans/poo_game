#include "interfaces/SpaceshipEnemy.hpp"

SpaceshipEnemy::SpaceshipEnemy(const ObjetoDeJogo &obj) : Enemy(obj) {}

void SpaceshipEnemy::update() {
    switch (getState()) {
        case EnemyState::Idle:
            moveTo(getPosL(), getPosC());
            setState(EnemyState::MovingRight);
            break;
        case EnemyState::MovingLeft:
            moveLeft(1);
            if (getPosC() == 3) {
                setState(EnemyState::MovingFront);
            } else if (getPosC() == 45) {
                setState(EnemyState::MovingFront);
            } else if (getPosC() == 0) {
                setState(EnemyState::MovingRight);
            }
            break;
        case EnemyState::MovingRight:
            moveRight(1);
            if (getPosC() == 78) {
                setState(EnemyState::MovingFront);
            } else if (getPosC() == 144) {
                setState(EnemyState::MovingFront);
            } else if (getPosC() == 192) {
                setState(EnemyState::MovingLeft);
            }
            break;
        case EnemyState::MovingFront:
            moveDown(2);
            if (getPosL() == 36) {
                setState(EnemyState::MovingBack);
            }
            break;
        case EnemyState::MovingBack:
            moveUp(2);
            if (getPosL() == 12 && getPosC() == 3) {
                setState(EnemyState::MovingLeft);
            } else if (getPosL() == 12 && getPosC() == 45) {
                setState(EnemyState::MovingLeft);
            } else if (getPosL() == 12 && getPosC() == 78) {
                setState(EnemyState::MovingRight);
            } else if (getPosL() == 12 && getPosC() == 144) {
                setState(EnemyState::MovingRight);
            }
            break;
    }

}