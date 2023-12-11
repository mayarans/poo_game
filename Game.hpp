#ifndef GAME_HPP
#define GAME_HPP

#include "Apresentacao.hpp"
#include "FaseLevel1.hpp"
#include "FaseLevel2.hpp"
#include "FaseLevel3.hpp"
#include "FaseStart.hpp"
#include "FaseFinal.hpp"
#include "FaseLoser.hpp"
#include "ASCII_Engine/Sprite.hpp"
#include "ASCII_Engine/SpriteAnimado.hpp"

class Game {
public:
    Game() {}
    ~Game() {}

    static void run() {
        SpriteBuffer buffer(250, 50);

        int faseAtual = 0;
        Apresentacao apresentacao("Apresentacao", SpriteAnimado("rsc_2/background.anm"));
        FaseStart start("FaseStart", SpriteAnimado("rsc_2/background.anm"));
        FaseLevel1 fase1("Fase1", SpriteAnimado("rsc_2/background.anm"));
        FaseLevel2 fase2("Fase2", SpriteAnimado("rsc_2/background.anm"));
        FaseLevel3 fase3("Fase3", SpriteAnimado("rsc_2/background.anm"));
        FaseFinal faseFinal("FaseFinal", SpriteAnimado("rsc_2/backgroundWinner.anm"));
        FaseLoser faseLoser("FaseLoser", SpriteAnimado("rsc_2/backgroundLoser.anm"));

        std::vector<Fase *> fases;
        fases.push_back(&apresentacao);
        fases.push_back(&start);
        fases.push_back(&fase1);
        fases.push_back(&fase2);
        fases.push_back(&fase3);
        fases.push_back(&faseFinal);


        Fase *fase;
        while (true) {
            fase = fases[faseAtual++];
            fase->init();
            int resultado = fase->run(buffer);
            switch (resultado) {
                case Fase::LEVEL_COMPLETE:
                    break;
                case Fase::GAME_OVER:
                    faseLoser.init();
                    faseLoser.run(buffer);
                    std::cout << "GAME OVER" << std::endl;
                    break;
                case Fase::END_GAME:
                    std::cout << "Saindo..." << std::endl;
                    break;
            }
            if (resultado == Fase::END_GAME || resultado == Fase::GAME_OVER)
                break;
        }
    };
};
#endif // GAME_HPP
