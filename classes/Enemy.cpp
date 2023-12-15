#include "interfaces/Enemy.hpp"

Enemy::Enemy(const ObjetoDeJogo &obj, int velocidade) : velocidade(velocidade), state(EnemyState::Idle), ObjetoDeJogo(obj) {}

void Enemy::update() {
    switch (state) {
        case EnemyState::Idle:
            moveTo(getPosL(), getPosC());
            state = EnemyState::MovingLeft;
            break;

        case EnemyState::MovingLeft:
            moveLeft(getVelocidade());
            if (getPosC() == 0) {
                state = EnemyState::MovingRight;
            }
            break;

        case EnemyState::MovingRight:
            moveRight(getVelocidade());
            if (getPosC() == 192) {
                state = EnemyState::MovingLeft;
            }
            break;
    }

}


