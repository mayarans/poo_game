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
	Enemy(const ObjetoDeJogo &obj);
	
	virtual ~Enemy(){}
	
	bool isAlive() const;

    virtual void update();

    EnemyState getState() const { return state; }
    void setState(EnemyState state) { this->state = state; }

private:

    EnemyState state;
};

#endif // ENEMY_HPP
