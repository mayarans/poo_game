#include "FaseFinal.hpp"

void FaseFinal::init()
{
    spaceship = new ObjetoDeJogo("SpaceshipWinner", SpriteAnimado("rsc_2/spaceshipWinner.anm"), 55, 80);

	objs.push_back(spaceship);
}

unsigned FaseFinal::run(SpriteBuffer &screen)
{
	std::string ent;
	
	//padrão
	draw(screen);
	system("clear");
	show(screen);
	
	
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

