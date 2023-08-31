
//#include "ufo_global.h"
#include "../../games/dummy_test/dummy_test_game.h"
//#include "../../external/olcPGEX_SplashScreen.h"
//#define OLC_PGEX_SPLASHSCREEN

int main()
{
	DummyTestGame game;
	//UfoGlobal::squirrel_interface.game = &game;
	if (game.Construct(1600, 800, 1, 1, false, true, true))
		game.Start();

	return 0;
}
