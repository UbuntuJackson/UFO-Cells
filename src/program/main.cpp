
#include "ufo_global.h"
#include "program.h"
#include "../../games/dummy_test/dummy_test_game.h"
//#include "../../external/olcPGEX_SplashScreen.h"
//#define OLC_PGEX_SPLASHSCREEN

int main()
{
	Game* game = new DummyTestGame(); //If this is the global variable, then I won't need program.cpp and program.h, and we can import
										//UfoGlobal::program whatever UfoGlobal::program is, because no matter what class it is,
										//we're gonna be able to call it's methods because it inherits PGE. We will no longer
										//have one single PGE childclass. We would only need to modify ufo_global.h and maybe we don't need
										//ufo_global.cpp
										//One separate idea is to give UfoGlobal::program the type olc::PixelgameEngine but then assign it
										//an instance of DummyTestGame
										//What if Game Inherited from PGE, and DummyTestGame inherited from Game
	if (UfoGlobal::program.Construct(400, 200, 4, 4, false, true, true))
		UfoGlobal::program.SetGame(game);
		UfoGlobal::program.Start();

	delete game;
	return 0;
}
