
#include "ufo_global.h"
#include "../../games/leg0/leg0.h"
//#include "../../external/olcPGEX_SplashScreen.h"
//#define OLC_PGEX_SPLASHSCREEN

int main()
{
	//UfoGlobal::game = new Leg0();
	if (UfoGlobal::game.Construct(1600, 800, 1, 1, false, true, true))
		UfoGlobal::game.Start();

	return 0;
}
