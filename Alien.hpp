#ifndef ALIEN_HPP
#define ALIEN_HPP

#include "Enemy.hpp"

class Alien : public Enemy
{
public:
	Alien(const ObjetoDeJogo &obj, int velocidade = 1);

	virtual ~Alien(){}

    void update();
};

#endif // ALIEN_HPP
