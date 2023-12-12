#include "Enemy.hpp"

Enemy::Enemy(const ObjetoDeJogo &obj) : state(EnemyState::Idle), ObjetoDeJogo(obj) {}

void Enemy::update() {
    switch (state) {
        case EnemyState::Idle:
            moveTo(getPosL(), getPosC());
            state = EnemyState::MovingLeft;
            break;

        case EnemyState::MovingLeft:
            moveLeft(1);
            if (getPosC() == 0) {
                state = EnemyState::MovingRight;
            }
            break;

        case EnemyState::MovingRight:
            moveRight(1);
            if (getPosC() == 154) {
                state = EnemyState::MovingLeft;
            }
            break;
    }

}


