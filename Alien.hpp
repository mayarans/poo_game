#ifndef ALIEN_HPP
#define ALIEN_HPP

#include "Enemy.hpp"

class Alien : public Enemy
{
public:
	Alien(const ObjetoDeJogo &obj, int life=30, int velAtaque=3);

	virtual ~Alien(){}

    void update();

//	bool isAlive() const { return life != 0; }
//
//	void sofrerAtaque(int ataque) {
//		life = (life - ataque >= 0)?(life - ataque):0;
//	}
//
//	int atacar() {
//		if (--contAtaque == 0) {
//			contAtaque = velAtaque;
//			return 10;
//		}
//		return 0;
//	}

};

#endif // ENEMY_HPP
