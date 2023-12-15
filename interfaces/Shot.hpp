#ifndef SHOT_HPP
#define SHOT_HPP

#include "../ASCII_Engine/ObjetoDeJogo.hpp"

class Shot : public ObjetoDeJogo {
public:
    Shot(const ObjetoDeJogo &obj, int velShot, int dir, int intensidade = 10) ;

    virtual ~Shot() {}

    void update();

    int getVelShot() const { return velShot; }
    void setVelShot(int num) { velShot = num; }

    int getDir() const { return dir; }
    void setDir(int num) { dir = num; }

    int getIntensidade() const { return intensidade; }


private:
    int velShot;
    int dir;
    int intensidade;

};

#endif // HERO_HPP
