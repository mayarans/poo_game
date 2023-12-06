#ifndef GAME_HPP
#define GAME_HPP

#include "FaseLevel1.hpp"
#include "FaseStart.hpp"
#include "FaseFinal.hpp"
#include "ASCII_Engine/Sprite.hpp"
#include "ASCII_Engine/SpriteAnimado.hpp"

class Game
{
public:
	Game(){}
	~Game(){}
	
	static void run()
	{
		SpriteBuffer buffer(250,50);
	
		FaseStart start("FaseStart",SpriteAnimado("rsc_2/background.anm"));
		FaseLevel1 fase1("Fase1",SpriteAnimado("rsc_2/background.anm"));
//		FaseFinal faseFinal("Fase1",Sprite("rsc/title1Gothic.img"));
		
		start.init();
		start.run(buffer);
		
		buffer.clear();
//		fase1.init();
//		int ret1 = fase1.run(buffer);
        int resStart = start.run(buffer);
		if ( resStart == Fase::LEVEL_COMPLETE){
			buffer.clear();
            fase1.init();
            int resLevel1 = fase1.run(buffer);
            if (resLevel1 == Fase::LEVEL_COMPLETE) {
                buffer.clear();
//                FaseFinal faseFinal("Fase1", Sprite("rsc/title1Gothic.img"));
//                faseFinal.init();
//                faseFinal.run(buffer);
            }
//			start.init();
//			start.run(buffer);
		}
		else
			std::cout << "GAME OVER" << std::endl;
//
		std::cout << "Saindo..." << std::endl;
	}

};

#endif // GAME_HPP
