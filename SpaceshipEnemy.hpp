#ifndef SPACESHIP_ENEMY_HPP
#define SPACESHIP_ENEMY_HPP

#include "Enemy.hpp"

class SpaceshipEnemy : public Enemy
{
public:
	SpaceshipEnemy(const ObjetoDeJogo &obj, int life=30, int velAtaque=3);
	
	virtual ~SpaceshipEnemy(){}
	
	void update();

};

#endif // ENEMY_HPP
