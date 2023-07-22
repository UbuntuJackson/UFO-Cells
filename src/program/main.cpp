
#include "ufo_global.h"
#include "program.h"
#include "../../games/dummy_test/dummy_test_game.h"
//#include "../../external/olcPGEX_SplashScreen.h"
//#define OLC_PGEX_SPLASHSCREEN

int main()
{
	Game* game = new DummyTestGame();
	if (UfoGlobal::program.Construct(1600, 800, 1, 1, false, true, true))
		UfoGlobal::program.SetGame(game);
		UfoGlobal::program.Start();

	delete game;
	return 0;
}
