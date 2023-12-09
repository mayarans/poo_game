#ifndef ITEM_HPP
#define ITEM_HPP

#include "ASCII_Engine/ObjetoDeJogo.hpp"

class Item : public ObjetoDeJogo {
public:
    Item(const ObjetoDeJogo &obj, std::string tipo, int velItem = 1) : tipo(tipo), velItem(velItem), ObjetoDeJogo(obj) {}

    virtual ~Item() {}

    int atacar();

    int getVelItem() const { return velItem; }

    std::string getTipo() const { return tipo; }

private:
    std::string descricao;
    std::string tipo;
    int velItem;

};

#endif
