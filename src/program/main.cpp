
#include "ufo_global.h"
#include "program.h"

int main()
{
	if (UfoGlobal::program.Construct(1600, 800, 1, 1, false, true, true))
		UfoGlobal::program.Start();

	return 0;
}
