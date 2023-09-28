#include "custom_type_registry.h"
#include "../../src/ufo/cell_actor.h"
#include <string>
#include "../../src/ufo/layer.h"
#include "island.h"
#include "../../src/ufo/layer_background.h"
#include "../../src/ufo/layer.h"
#include "../../src/ufo/layer_solid.h"
#include "../../src/ufo/layer_actor.h"
#include "../../src/ufo/layer_terrain.h"
#include "../../src/ufo/actor_info.h"
#include <vector>
#include "optimised_dummy.h"
#include "../../external/olcPixelGameEngine.h"

CustomTypeRegistry::CustomTypeRegistry(Island* _game): game{_game}{}

CellActor*
CustomTypeRegistry::NewActor(std::string _actor, olc::vf2d _position){
    if(_actor == "Dummy"){
        return new OptimisedDummy(_position, game);
    }
}