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
	Enemy(const ObjetoDeJogo &obj, int life=30, int velAtaque=3);
	
	virtual ~Enemy(){}
	
	bool isAlive() const;
	
	void sofrerAtaque(int ataque);
	
	virtual int atacar();

    virtual void update();

    EnemyState getState() const { return state; }
    void setState(EnemyState state) { this->state = state; }

    int getLife() const { return life; }
    void setLife(int num) { life = num; }

    int getVelAtaque() const { return velAtaque; }
    void setVelAtaque(int num) { velAtaque = num; }

    int getContAtaque() const { return contAtaque; }
    void setContAtaque(int num) { contAtaque = num; }

private:
	int life;
	int velAtaque, contAtaque;

    EnemyState state;
};

#endif // ENEMY_HPP
