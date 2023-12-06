#include "Enemy.hpp"

Enemy::Enemy(const ObjetoDeJogo &obj, int life, int velAtaque) : state(EnemyState::Idle), ObjetoDeJogo(obj), life(life), velAtaque(velAtaque), contAtaque(velAtaque) {}

bool Enemy::isAlive() const { return life != 0; }

void Enemy::sofrerAtaque(int ataque) {
    life = (life - ataque >= 0)?(life - ataque):0;
}

int Enemy::atacar() {
    if (--contAtaque == 0) {
        contAtaque = velAtaque;
        return 10;
    }
    return 0;
}

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


