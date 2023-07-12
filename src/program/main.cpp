
#include "ufo_global.h"
#include "program.h"

int main()
{
	if (UfoGlobal::program.Construct(1600, 800, 1, 1))
		UfoGlobal::program.Start();

	return 0;
}
