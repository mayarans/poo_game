#include "interfaces/Apresentacao.hpp"
#include "../ASCII_Engine/Sound.hpp"

void Apresentacao::init()
{
    carta = new ObjetoDeJogo("Carta", Sprite("rsc_2/letter.img"), 13, 50);
    objs.push_back(carta);

    objs.push_back(new ObjetoDeJogo("Carregamento", TextSprite("#"), 49, 70));
    SpriteBase *tmp = const_cast<SpriteBase *> (objs.back()->getSprite());
    carregamento = dynamic_cast<TextSprite *> (tmp);
    som = new Sound("./sounds/presentation.mp3");
}

unsigned Apresentacao::run(SpriteBuffer &screen) {
    som->play();
    std::string ent;

    //padrão
    draw(screen);
    system("clear");
    show(screen);

    int contagem = 2;
    for (int i = 0; i < 50; i++) {
        //lendo entrada
        getline(std::cin, ent);
        if (ent == "q") {
            som->pause();
            return Fase::END_GAME;
        }

        carregamento->setText(std::string(contagem, '#'));
        contagem++;


        update();
        screen.clear();
        draw(screen);
        system("clear");

        show(screen);
    }
    som->pause();
    return Fase::LEVEL_COMPLETE;
}
