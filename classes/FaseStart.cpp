#include "../interfaces/FaseStart.hpp"

void FaseStart::init() {
    spaceship = new Spaceship(ObjetoDeJogo("Spaceship", Sprite("../rsc/spaceship.img"), 42, 70), 25, 2);
    objs.push_back(spaceship);

    countEnemy = 0;
    for (int i = 0; i < 81; i+=10) {
        countEnemy += 1;
        if (countEnemy % 2 == 0)
            objs.push_back(new Alien (ObjetoDeJogo("Alien", Sprite("../rsc/alien.img"), 0, i)));
        else
            objs.push_back(new Alien (ObjetoDeJogo("Alien", Sprite("../rsc/alien.img"), 0, i), 2));
    }

    for (int i = 80; i < 141; i+=10) {
        countEnemy += 1;
        objs.push_back(new Jellyfish (ObjetoDeJogo("Jellyfish", Sprite("../rsc/jellyfish.img"), 8, i)));
    }

    objs.push_back(new ObjetoDeJogo("Life", TextSprite("##########"), 49, 140));
    SpriteBase *tmp = const_cast<SpriteBase *> (objs.back()->getSprite());
    life = dynamic_cast<TextSprite *> (tmp);

    objs.push_back(new ObjetoDeJogo("Shots", TextSprite("0/25"), 48, 140));
    SpriteBase *tmp2 = const_cast<SpriteBase *> (objs.back()->getSprite());
    shots = dynamic_cast<TextSprite *> (tmp2);

    controller = new ShotController(ObjetoDeJogo("ShotController", Sprite("../rsc/shot.img"), 0, 0));
    objs.push_back(controller);

    objs.push_back(new ObjetoDeJogo("Barreira", TextSprite("############"), 20, 2));
    objs.push_back(new ObjetoDeJogo("Barreira", TextSprite("############"), 15, 30));
    objs.push_back(new ObjetoDeJogo("Barreira", TextSprite("############"), 27, 90));
    objs.push_back(new ObjetoDeJogo("Barreira", TextSprite("############"), 18, 70));
    objs.push_back(new ObjetoDeJogo("Barreira", TextSprite("############"), 30, 130));
    objs.push_back(new ObjetoDeJogo("Barreira", TextSprite("############"), 30, 130));
    objs.push_back(new ObjetoDeJogo("Barreira", TextSprite("############"), 18, 160));
    objs.push_back(new ObjetoDeJogo("Barreira", TextSprite("############"), 25, 185));

    shooting = new Sound("../sounds/shot.mp3");
    enemyKill = new Sound("../sounds/kill.mp3");
}

unsigned FaseStart::run(SpriteBuffer &screen) {
    std::string ent;

    //padrão
    draw(screen);
    system("clear");
    show(screen);

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

        if (controller->verificaColisao(objs) == 1) {
            countEnemy--;
            enemyKill->play();
        }

        update();
        screen.clear();
        draw(screen);
        system("clear");

        if (countEnemy == 0) {
            return Fase::LEVEL_COMPLETE;
        } else if (spaceship->getQuantShots() == spaceship->getTotalShots() && !controller->shotsAtivos() && countEnemy > 0) {
            return Fase::GAME_OVER;
        }
        show(screen);
    }
}