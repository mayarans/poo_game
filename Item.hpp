#ifndef ITEM_HPP
#define ITEM_HPP

#include "ASCII_Engine/ObjetoDeJogo.hpp"

class Item : public ObjetoDeJogo {
public:
    Item(const ObjetoDeJogo &obj, std::string tipo) : tipo(tipo), ObjetoDeJogo(obj) {}

    virtual ~Item() {}

    std::string getTipo() const { return tipo; }

private:
    std::string tipo;

};

#endif
