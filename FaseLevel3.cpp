#include "FaseLevel3.hpp"
#include <ctime>
#include <cstdlib>

void FaseLevel3::init() {
    spaceship = new Spaceship(ObjetoDeJogo("Spaceship", Sprite("rsc_2/spaceship.img"), 42, 70), 40, 1);
    objs.push_back(spaceship);

    countEnemy = 0;
    int pos = 0;
    for (int i = 70; i < 101; i += 10) {
        countEnemy += 1;
        alien[pos] = new Alien(ObjetoDeJogo("Alien", Sprite("rsc_2/alien.img"), 0, i));
        objs.push_back(alien[pos++]);
    }

    pos = 0;
    for (int i = 80; i < 101; i += 10) {
        countEnemy += 1;
        jellyfish[pos] = new Jellyfish(ObjetoDeJogo("Jellyfish", Sprite("rsc_2/jellyfish.img"), 8, i));
        objs.push_back(jellyfish[pos++]);
    }

    pos = 0;
    for (int i = 0; i < 71; i += 70) {
        countEnemy += 1;
        spaceshipEnemy[pos] = new SpaceshipEnemy(ObjetoDeJogo("SpaceshipEnemy", Sprite("rsc_2/spaceshipEnemy.img"), 12, i));
        objs.push_back(spaceshipEnemy[pos++]);
    }

    objs.push_back(new ObjetoDeJogo("Life", TextSprite("##########"), 49, 140));
    SpriteBase *tmp = const_cast<SpriteBase *> (objs.back()->getSprite());
    life = dynamic_cast<TextSprite *> (tmp);

    objs.push_back(new ObjetoDeJogo("Shots", TextSprite("0/40"), 48, 140));
    SpriteBase *tmp2 = const_cast<SpriteBase *> (objs.back()->getSprite());
    shots = dynamic_cast<TextSprite *> (tmp2);

    controller = new ShotController(ObjetoDeJogo("ShotController", Sprite("rsc_2/shot.img"), 0, 0));
    objs.push_back(controller);

    itemController = new ItemController(ObjetoDeJogo("ItemController", Sprite(""), 0, 0));
    objs.push_back(itemController);

    srand(time(NULL));
}

unsigned FaseLevel3::run(SpriteBuffer &screen) {
    std::string ent;

    //padrão
    draw(screen);
    system("clear");
    show(screen);

    int cont = 0;
    int colisao;
    int cont2 = 0;
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
        } else if (ent == "x" && spaceship->getQuantShots() < spaceship->getTotalShots()) {
            controller->createShot(spaceship->getPosL() - 2, spaceship->getPosC() + 5, spaceship->getVelShot(), 1);
            spaceship->incrementQuantShots();
            shots->setText(
                    std::to_string(spaceship->getQuantShots()) + "/" + std::to_string(spaceship->getTotalShots()));
        }

        cont++;
        if (cont >= 20) {
            int i = rand() % 4;
            if (alien[i]->isActive()) {
                controller->createShot(alien[i]->getPosL() + 5, alien[i]->getPosC() + 2, 1, -1);
                cont = 0;
            }
        }

        colisao = controller->verificaColisao(objs);
        if (colisao == 1) {
            countEnemy--;
        } else if (colisao == 0) {
            life->setText(std::string(spaceship->getLife() / 10, '#'));
        }

        cont2++;
        if (cont2 >= 60) {
            int i = rand() % 3;
            int j = rand() % 3;
            if (jellyfish[i]->isActive()) {
                itemController->createItem(jellyfish[i]->getPosL() + 5, jellyfish[i]->getPosC() + 2, 1, j);
                cont2 = 0;
            }
        }

        colisao = itemController->verificaColisao(*spaceship);
        if (colisao == 0) {
            spaceship->recebeItemLife();
            life->setText(std::string(spaceship->getLife() / 10, '#'));
        } else if (colisao == 1) {
            spaceship->recebeItemNocivo();
            life->setText(std::string(spaceship->getLife() / 10, '#'));
        } else if (colisao == 2) {
            spaceship->recebeItemShot();
            shots->setText(std::to_string(spaceship->getQuantShots()) + "/" + std::to_string(spaceship->getTotalShots()));
        }

        update();
        screen.clear();
        draw(screen);
        system("clear");

        if (countEnemy == 0) {
            return Fase::LEVEL_COMPLETE;
        } else if ((spaceship->getQuantShots() == spaceship->getTotalShots() && countEnemy > 0) ||
                   (!spaceship->isAlive())) {
            return Fase::GAME_OVER;
        }

        show(screen);
    }

}
