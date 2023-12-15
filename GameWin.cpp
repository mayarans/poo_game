#include "GameWin.hpp"

void GameWin::init()
{
    spaceship = new ObjetoDeJogo("SpaceshipWinner", SpriteAnimado("./rsc/spaceshipWinner.anm"), 55, 80);
	objs.push_back(spaceship);
    alreadyWinSound = new Sound("./sounds/soundWinner.mp3");
}

unsigned GameWin::run(SpriteBuffer &screen)
{
	std::string ent;
	
	//padrão
	draw(screen);
	system("clear");
	show(screen);

    alreadyWinSound->play();
	
	for (int i = 0 ; i < 50 ; i++)
	{
		//lendo entrada
		getline(std::cin,ent);
		if (ent == "q")
			return Fase::END_GAME;

        spaceship->moveUp(1);
        screen.clear();


        //padrão
        update();
        screen.clear();
        draw(screen);
        system("clear");
        show(screen);
	}
	
	return Fase::END_GAME; // não necessário
}

