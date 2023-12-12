#ifndef JELLYFISH_HPP
#define JELLYFISH_HPP

#include "ASCII_Engine/ObjetoDeJogo.hpp"
#include "Enemy.hpp"

class Jellyfish : public Enemy
{
public:
	Jellyfish(const ObjetoDeJogo &obj) : Enemy(obj) {}
	
	virtual ~Jellyfish() {}
};

#endif
