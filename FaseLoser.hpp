#ifndef FASELOSER_HPP
#define FASELOSER_HPP

#include "ASCII_Engine/Fase.hpp"

class FaseLoser : public Fase
{
public:
	FaseLoser(std::string name, const Sprite &bkg) : Fase(name,bkg) {}
	FaseLoser(std::string name, const SpriteAnimado &bkg) : Fase(name,bkg) {}
	virtual ~FaseLoser() {}
	
	virtual void init();
	virtual unsigned run(SpriteBuffer &screen);

private:
    ObjetoDeJogo *spaceship;
};

#endif // FASELOSER_HPP
