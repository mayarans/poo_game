#ifndef GAMEWIN_HPP
#define GAMEWIN_HPP

#include "../ASCII_Engine/Fase.hpp"
#include "../ASCII_Engine/Sound.hpp"

class GameWin : public Fase
{
public:
    GameWin(std::string name, const Sprite &bkg) : Fase(name,bkg) {}
	GameWin(std::string name, const SpriteAnimado &bkg) : Fase(name,bkg) {}
	virtual ~GameWin() {}
	
	virtual void init();
	virtual unsigned run(SpriteBuffer &screen);

private:
    ObjetoDeJogo *spaceship;
    Sound *alreadyWinSound;
};

#endif // GAMEWIN_HPP
