#ifndef GAMEOVER_HPP
#define GAMEOVER_HPP

#include "../ASCII_Engine/Fase.hpp"
#include "../ASCII_Engine/Sound.hpp"

class GameOver : public Fase
{
public:
	GameOver(std::string name, const Sprite &bkg) : Fase(name,bkg) {}
	GameOver(std::string name, const SpriteAnimado &bkg) : Fase(name,bkg) {}
	virtual ~GameOver() {}
	
	virtual void init();
	virtual unsigned run(SpriteBuffer &screen);

private:
    ObjetoDeJogo *spaceship;
    Sound *spaceshipDeath;
};

#endif // GAMEOVER_HPP
