#include "interfaces/GameOver.hpp"

void GameOver::init()
{
    spaceship = new ObjetoDeJogo("SpaceshipExplosion", SpriteAnimado("rsc_2/explosion.anm"), 30, 30);
	objs.push_back(spaceship);

    spaceshipDeath = new Sound("./sounds/spaceshipDeath.mp3");
}

unsigned GameOver::run(SpriteBuffer &screen)
{
	std::string ent;
	
	//padrão
	draw(screen);
	system("clear");
	show(screen);

    spaceshipDeath->play();
	
	for (int i = 0 ; i < 50 ; i++)
	{
		//lendo entrada
		getline(std::cin,ent);
		if (ent == "q")
			return Fase::END_GAME;

        //padrão
        update();
        screen.clear();
        draw(screen);
        system("clear");
        show(screen);
	}

	return Fase::END_GAME; // não necessário
}

