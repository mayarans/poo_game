#ifndef SPACESHIP_ENEMY_HPP
#define SPACESHIP_ENEMY_HPP

#include "Enemy.hpp"

class SpaceshipEnemy : public Enemy
{
public:
	SpaceshipEnemy(const ObjetoDeJogo &obj);
	
	virtual ~SpaceshipEnemy(){}
	
	void update();

};

#endif
