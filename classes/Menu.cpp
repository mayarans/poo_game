#include "interfaces/Menu.hpp"

void Menu::init() {
    menu = new ObjetoDeJogo("Menu", Sprite("./rsc_2/menu.img"), 15, 65);
    setinha = new ObjetoDeJogo("Setinha", Sprite("./rsc_2/arrow.img"), 20, 100);
    objs.push_back(menu);
    objs.push_back(setinha);
}

unsigned Menu::run(SpriteBuffer &screen) {
    std::string entrada;
    while (true) {
        draw(screen);
        system("clear");
        show(screen);

        system("stty raw");
        entrada = getchar();
        system("stty cooked");

        if (entrada == "q") {
            system("stty cooked");
            return Fase::END_GAME;
        } else if (entrada == "w") { // mover seta para cima
            setinha->moveTo(20, 100);
            opcao = Fase::LEVEL_COMPLETE;
        } else if (entrada == "s") { // mover seta para baixo
            setinha->moveTo(26, 100);
            opcao = Fase::END_GAME;
        } else if (entrada == "x") // selecionar
            return opcao;

        update();
        screen.clear();
    }
}