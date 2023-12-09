#ifndef SPACESHIP_HPP
#define SPACESHIP_HPP

#include "ASCII_Engine/ObjetoDeJogo.hpp"

class Spaceship : public ObjetoDeJogo {
public:
    Spaceship(const ObjetoDeJogo &obj, int totalShots, int velShot, int life = 100) : quantShots(0),
                                                                                      totalShots(totalShots),
                                                                                      velShot(velShot), life(life),
                                                                                      ObjetoDeJogo(obj) {}


    virtual ~Spaceship() {}

    bool isAlive() const { return life != 0; }

    int getLife() const { return life; }

    void sofrerAtaque(int ataque) { life = (life - ataque >= 0) ? (life - ataque) : 0; }

    int atacar() const { return 10; }

    int getQuantShots() const { return quantShots; }

    int getVelShot() const { return velShot; }

    void setVelShot(int num) { velShot = num; }

    void incrementQuantShots() { quantShots++; }

    void recebeItemShot() { totalShots++; }

    void recebeItemLife() { life += 10; }

    void recebeItemNocivo() { life -= 10; }

    int getTotalShots() const { return totalShots; }


private:
    int life;
    int quantShots;
    int velShot;
    int totalShots;
};

#endif // SPACESHIP_HPP
