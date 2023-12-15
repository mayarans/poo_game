#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "ASCII_Engine/ObjetoDeJogo.hpp"

enum class EnemyState {
    Idle,
    MovingLeft,
    MovingRight,
    MovingFront,
    MovingBack,
};

class Enemy : public ObjetoDeJogo
{
public:
	Enemy(const ObjetoDeJogo &obj, int velocidade = 1);
	
	virtual ~Enemy(){}
	
	bool isAlive() const;

    virtual void update();

    EnemyState getState() const { return state; }
    void setState(EnemyState state) { this->state = state; }

    int getVelocidade() const { return velocidade; }

private:

    EnemyState state;
    int velocidade;
};

#endif // ENEMY_HPP
