#include "island.h"
#include "../../src/ufo/cellmap.h"
#include "../../src/ufo/ufo_load.h"
#include "custom_type_registry.h"

Island::Island() : Game(), camera{Camera(this)}, map{CellMap(this)}, play{State(this)}, menu{State(this)}{
    registry = new CustomTypeRegistry(this);
    load = UfoLoad(this, registry);
    game_state = &load;
    load.Set("../games/island/res/map/windmill/windmill.json", &map);
}

void
Island::LoadResources(){
    asset_manager.LoadDecal("../games/island/res/masks/pill_small.png", "decPin");
    asset_manager.LoadDecal("../games/island/res/masks/purple.png", "decPurple");
    asset_manager.LoadDecal("../res/misc/new_logo_centred_ufo_cells.png", "load");
    asset_manager.LoadDecal("../games/island/res/map/zen/dynamic_solid_1.png", "dynamic_solid");
}