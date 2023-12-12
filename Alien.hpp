#ifndef ALIEN_HPP
#define ALIEN_HPP

#include "Enemy.hpp"

class Alien : public Enemy
{
public:
	Alien(const ObjetoDeJogo &obj);

	virtual ~Alien(){}

    void update();
};

#endif // ENEMY_HPP
