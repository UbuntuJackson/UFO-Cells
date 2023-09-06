
//#include "ufo_global.h"
#include "../../games/leg0/leg0.h"
//#include "../../external/olcPGEX_SplashScreen.h"
//#define OLC_PGEX_SPLASHSCREEN

int main()
{
	Leg0 game;
	//UfoGlobal::squirrel_interface.game = &game;
	if (game.Construct(1600, 800, 1, 1, false, true, true))
		game.Start();

	return 0;
}
