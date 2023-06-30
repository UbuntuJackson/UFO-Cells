
#include "program.h"

int main()
{
	Program demo;
	if (demo.Construct(1600, 800, 1, 1, false, true, true))
		demo.Start();

	return 0;
}
