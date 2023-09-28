#include "type_registry.h"
#include "../../src/ufo/cell_actor.h"
#include <string>
#include "../../src/ufo/layer.h"
#include "../../src/ufo/layer_background.h"
#include "../../src/ufo/layer.h"
#include "../../src/ufo/layer_background.h"
#include "../../src/ufo/layer_solid.h"
#include "../../src/ufo/layer_actor.h"
#include "../../src/ufo/layer_terrain.h"
#include "../../src/ufo/actor_info.h"
#include <vector>
#include "../../external/olcPixelGameEngine.h"

TypeRegistry::TypeRegistry(){}

CellActor*
TypeRegistry::NewActor(std::string _actor, olc::vf2d _position){}