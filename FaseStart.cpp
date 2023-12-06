#include "FaseStart.hpp"

void FaseStart::init() {
    spaceship = new Spaceship(ObjetoDeJogo("Spaceship", Sprite("rsc_2/spaceship.img"), 42, 70), 15, 1);
    objs.push_back(spaceship);

    countEnemy = 0;
    for (int i = 70; i < 81; i+=10) {
        countEnemy += 1;
        objs.push_back(new Alien (ObjetoDeJogo("Alien", Sprite("rsc_2/alien.img"), 0, i)));
    }

    for (int i = 80; i < 91; i+=10) {
        countEnemy += 1;
        objs.push_back(new Jellyfish (ObjetoDeJogo("Jellyfish", Sprite("rsc_2/jellyfish.img"), 8, i)));
    }

    objs.push_back(new ObjetoDeJogo("Life", TextSprite("####################"), 49, 140));
    SpriteBase *tmp = const_cast<SpriteBase *> (objs.back()->getSprite());
    life = dynamic_cast<TextSprite *> (tmp);

    objs.push_back(new ObjetoDeJogo("Shots", TextSprite("OOOOOOOOOO"), 48, 140));
    SpriteBase *tmp2 = const_cast<SpriteBase *> (objs.back()->getSprite());
    shots = dynamic_cast<TextSprite *> (tmp2);

    controller = new ShotController(ObjetoDeJogo("ShotController", Sprite("rsc_2/shot.img"), 0, 0));
    objs.push_back(controller);
}

unsigned FaseStart::run(SpriteBuffer &screen) {
    std::string ent;

    //padrão
    draw(screen);
    system("clear");
    show(screen);

//	int state = RIDING;
//	int countPracing = 0;

    while (true) {
        //lendo entrada
        system("stty raw");
        ent = getchar();
//        getline(std::cin, ent);
        system("stty cooked");
        if (ent == "q") {
            system("stty cooked");
            return Fase::END_GAME;
        } else if (ent == "a" && spaceship->getPosC() > 1) {
            spaceship->moveLeft(3);
        } else if (ent == "d" && spaceship->getPosC() < 154) {
            spaceship->moveRight(3);
        } else if (ent == "x" && spaceship->getQuantShots() > 0) {
            controller->createShot(spaceship->getPosL() - 2, spaceship->getPosC() + 5, spaceship->getVelShot(), 1);
            spaceship->decrementQuantShots();
        }

        if (controller->verificaColisao(objs)) {
            countEnemy--;
        }

        update();
        screen.clear();
        draw(screen);
        system("clear");

        if (countEnemy == 0) {
            return Fase::LEVEL_COMPLETE;
        } else if (spaceship->getQuantShots() == 0 && countEnemy > 0) {
            return Fase::GAME_OVER;
        }


        show(screen);

//        bg.update();
//        spaceship.update();

    }
//
//		switch(state){
//			case RIDING:
//				if (heroMove1->getPosC() <= 60)
//					heroMove1->moveRight();
//				else
//				{
//					heroMove1->desativarObj();
//					heroMove2->ativarObj();
//					state = PRACING;
//				}
//				break;
//			case PRACING:
//				if(countPracing++ == 24){
//					heroMove2->desativarObj();
//					heroMove1->ativarObj();
//					state = END;
//				}
//				break;
//			case END:
//				if(heroMove1->getPosC() < 90){
//					heroMove1->moveRight();
//				}
//				else
//					return Fase::LEVEL_COMPLETE;
//				break;
//		}

    //padrão
    update();
    draw(screen);
    system("clear");
    show(screen);
//	}

//    return Fase::END_GAME; // não necessário
}
