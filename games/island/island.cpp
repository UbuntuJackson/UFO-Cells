#include "island.h"
#include "../../src/ufo/cellmap.h"

Island::Island() : Game(), camera{Camera(this)}, map{CellMap(this)}, play{State(this)}, load{State(this)}, menu{State(this)}{

}