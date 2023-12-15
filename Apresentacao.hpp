#ifndef APRESENTACAO_HPP
#define APRESENTACAO_HPP

#include "ASCII_Engine/Fase.hpp"
#include "ASCII_Engine/Sound.hpp"

class Apresentacao : public Fase
{
public:
	Apresentacao(std::string name, const Sprite &bkg) : Fase(name,bkg) {}
	Apresentacao(std::string name, const SpriteAnimado &bkg) : Fase(name,bkg) {}
	virtual ~Apresentacao() {}
	
	virtual void init();
	virtual unsigned run(SpriteBuffer &screen);

private:
	ObjetoDeJogo *carta;
    TextSprite *carregamento;
	Sound *som;

};

#endif // APRESENTACAO_HPP
