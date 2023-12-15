#include "interfaces/FaseLevel1.hpp"
#include <ctime>
#include <cstdlib>

void FaseLevel1::init() {
    spaceship = new Spaceship(ObjetoDeJogo("Spaceship", Sprite("rsc_2/spaceship.img"), 42, 70), 30, 2);
    objs.push_back(spaceship);

    countEnemy = 0;
    int pos = 0;
    for (int i = 0; i < 91; i+=10) {
        countEnemy += 1;
        alien[pos] = new Alien (ObjetoDeJogo("Alien", Sprite("rsc_2/alien.img"), 0, i), 2);
        objs.push_back(alien[pos++]);
    }

    pos = 0;
    for (int i = 40; i < 111; i+=10) {
        countEnemy += 1;
        jellyfish[pos] = new Jellyfish (ObjetoDeJogo("Jellyfish", Sprite("rsc_2/jellyfish.img"), 8, i));
        objs.push_back(jellyfish[pos++]);
    }

    objs.push_back(new ObjetoDeJogo("Life", TextSprite("##########"), 49, 140));
    SpriteBase *tmp = const_cast<SpriteBase *> (objs.back()->getSprite());
    life = dynamic_cast<TextSprite *> (tmp);

    objs.push_back(new ObjetoDeJogo("Shots", TextSprite("0/30"), 48, 140));
    SpriteBase *tmp2 = const_cast<SpriteBase *> (objs.back()->getSprite());
    shots = dynamic_cast<TextSprite *> (tmp2);

    controller = new ShotController(ObjetoDeJogo("ShotController", Sprite("rsc_2/shot.img"), 0, 0));
    objs.push_back(controller);

    srand(time(NULL));

    objs.push_back(new ObjetoDeJogo("Barreira", TextSprite("############"), 20, 2));
    objs.push_back(new ObjetoDeJogo("Barreira", TextSprite("############"), 15, 30));
    objs.push_back(new ObjetoDeJogo("Barreira", TextSprite("############"), 27, 90));
    objs.push_back(new ObjetoDeJogo("Barreira", TextSprite("############"), 18, 70));
    objs.push_back(new ObjetoDeJogo("Barreira", TextSprite("############"), 30, 130));
    objs.push_back(new ObjetoDeJogo("Barreira", TextSprite("############"), 30, 130));
    objs.push_back(new ObjetoDeJogo("Barreira", TextSprite("############"), 18, 160));
    objs.push_back(new ObjetoDeJogo("Barreira", TextSprite("############"), 25, 185));

    enemyKill = new Sound("./sounds/kill.mp3");
    shooting = new Sound("./sounds/shot.mp3");
}

unsigned FaseLevel1::run(SpriteBuffer &screen) {
    std::string ent;

    //padrão
    draw(screen);
    system("clear");
    show(screen);

    int cont = 0;
    int colisao;
    while (true) {
        //lendo entrada
        system("stty raw");
        ent = getchar();
        system("stty cooked");
        if (ent == "q") {
            system("stty cooked");
            return Fase::END_GAME;
        } else if (ent == "a" && spaceship->getPosC() > 1) {
            spaceship->moveLeft(3);
        } else if (ent == "d" && spaceship->getPosC() < 192) {
            spaceship->moveRight(3);
        } else if (ent == "x" && spaceship->getQuantShots() < spaceship->getTotalShots() ) {
            shooting->play();
            controller->createShot(spaceship->getPosL() - 2, spaceship->getPosC() + 5, spaceship->getVelShot(), 1);
            spaceship->incrementQuantShots();
            shots->setText(std::to_string(spaceship->getQuantShots()) + "/" + std::to_string(spaceship->getTotalShots()));
        }

        cont++;
        if (cont == 20) {
            int i = rand() % 4;
            if (alien[i]->isActive()) {
                controller->createShot(alien[i]->getPosL() + 5, alien[i]->getPosC() + 2, 1, -1);
            }
            cont = 0;
        }

        colisao = controller->verificaColisao(objs);
        if (colisao == 1) {
            countEnemy--;
            enemyKill->play();
        } else if (colisao == 0) {
            life->setText(std::string(spaceship->getLife()/10,'#'));
        }

        update();
        screen.clear();
        draw(screen);
        system("clear");

        if (countEnemy == 0) {
            return Fase::LEVEL_COMPLETE;
        } else if ((spaceship->getQuantShots() == spaceship->getTotalShots() && countEnemy > 0) || (!spaceship->isAlive())) {
            return Fase::GAME_OVER;
        }

        show(screen);
    }
}
