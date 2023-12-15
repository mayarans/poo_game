#include "ItemController.hpp"

ItemController::ItemController(const ObjetoDeJogo &obj) : ObjetoDeJogo(obj){
}

ItemController::~ItemController() {
    for (auto item : itens) {
        delete item;
    }
}

void ItemController::update() {
    for (auto item : itens) {
        item->moveDown();
    }
}

void ItemController::createItem(int posL, int posC, int tipo) {
    if (tipo < 8) {
        tipo = 1;
    } else if (tipo == 8) {
        tipo = 0;
    } else {
        tipo = 2;
    }
    switch (tipo) {
        case 0:
            newItem = new Item(ObjetoDeJogo("Item", Sprite("./rsc/life.img"), posL + 3, posC),
                            "life");
            break;
        case 1:
            newItem = new Item(ObjetoDeJogo("Item", Sprite("./rsc/bomb.img"), posL + 3, posC),
                               "bomba");
            break;
        case 2:
            newItem = new Item(ObjetoDeJogo("Item", Sprite("./rsc/itemShot.img"), posL + 3, posC),
                            "municao");
            break;
    }
    newItem->ativarObj();
    itens.push_back(newItem);
}

int ItemController::verificaColisao(const Spaceship &spaceship) {
    for (auto item: itens) {
        if (item->getTipo() == "life" && item->colideCom(spaceship)) {
            item->desativarObj();
            return 0;
        } else if (item->getTipo() == "bomba" && item->colideCom(spaceship)) {
            item->desativarObj();
            return 1;
        } else if (item->getTipo() == "municao" && item->colideCom(spaceship)) {
            item->desativarObj();
            return 2;
        }

    }
    return 3;
}

void ItemController::draw(SpriteBase &screen, unsigned x, unsigned y) {
    for (auto item : itens) {
        item->draw(screen, item->getPosL(), item->getPosC());
    }
}