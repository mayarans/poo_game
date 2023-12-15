#ifndef MENU_HPP
#define MENU_HPP

#include "ASCII_Engine/Fase.hpp"
#include "ASCII_Engine/Sound.hpp"

class Menu : public Fase
{
public:
    Menu(std::string name, const Sprite &bkg) : Fase(name,bkg) {}
    Menu(std::string name, const SpriteAnimado &bkg) : Fase(name,bkg) {}
    virtual ~Menu() {}

    virtual void init();
    virtual unsigned run(SpriteBuffer &screen);

private:

    ObjetoDeJogo *setinha;
    ObjetoDeJogo *menu;
    int opcao = Fase::LEVEL_COMPLETE;
};

#endif // MENU_HPP
