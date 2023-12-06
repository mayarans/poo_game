#ifndef JELLYFISH_HPP
#define JELLYFISH_HPP

#include "ASCII_Engine/ObjetoDeJogo.hpp"

class Jellyfish : public Enemy
{
public:
	Jellyfish(const ObjetoDeJogo &obj, int life=30, int velAtaque=3) : Enemy(obj, life, velAtaque) {}
	
	virtual ~Jellyfish(){}


};

#endif // ENEMY_HPP
