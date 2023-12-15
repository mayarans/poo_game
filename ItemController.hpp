#ifndef ITEM_CONTROLLER_HPP
#define ITEM_CONTROLLER_HPP

#include "ASCII_Engine/ObjetoDeJogo.hpp"
#include "Item.hpp"
#include "Spaceship.hpp"
#include "Jellyfish.hpp"
#include <list>

class ItemController : public ObjetoDeJogo {
public:
    ItemController(const ObjetoDeJogo &obj);

    virtual ~ItemController();

    void update();

    void createItem(int posL, int posC, int tipo);

    int verificaColisao(const Spaceship &spaceship);

    void draw(SpriteBase &screen, unsigned x, unsigned y);


private:
    std::list<Item*> itens;
    Item *newItem;
};

#endif
