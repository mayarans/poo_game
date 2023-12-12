#include "Apresentacao.hpp"
#include "ASCII_Engine/Sound.hpp"
#include <thread>

void Apresentacao::init()
{
    carta = new ObjetoDeJogo("Carta", Sprite("rsc_2/carta.img"), 13, 30);
    objs.push_back(carta);

    objs.push_back(new ObjetoDeJogo("Carregamento", TextSprite("#"), 49, 50));
    SpriteBase *tmp = const_cast<SpriteBase *> (objs.back()->getSprite());
    carregamento = dynamic_cast<TextSprite *> (tmp);
}

unsigned Apresentacao::run(SpriteBuffer &screen) {
    std::string ent;

    //padrão
    draw(screen);
    system("clear");
    show(screen);

    int contagem = 2;
    for (int i = 0; i < 50; i++) {
        //lendo entrada
        getline(std::cin, ent);
        if (ent == "q")
            return Fase::END_GAME;

        carregamento->setText(std::string(contagem, '#'));
        contagem++;


        update();
        screen.clear();
        draw(screen);
        system("clear");

        show(screen);
    }
    return Fase::LEVEL_COMPLETE;
}
