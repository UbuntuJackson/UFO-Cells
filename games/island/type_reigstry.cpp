#include "type_registry.h"
#include "../../src/ufo/cell_actor.h"
#include <string>
#include "../../src/ufo/layer.h"
#include "island.h"
#include "../../src/ufo/layer_background.h"
#include "../../src/ufo/layer.h"
#include "../../src/ufo/layer_background.h"
#include "../../src/ufo/layer_solid.h"
#include "../../src/ufo/layer_actor.h"
#include "../../src/ufo/layer_terrain.h"


CellActor*
TypeRegistry::NewActor(std::string _actor){
    
}

Layer*
TypeRegistry::NewLayer(std::string _layer, std::string _name, std::string _type, std::string _path){
    if(_layer == "background"){
        return new LayerBackground(&(game->camera), &(game->map),_name, _type, _path);
    }
    if(_layer == "collision"){
        
        return new LayerSolid(&(game->camera), &(game->map),_name, _type, _path);
    }
    if(_layer == "terrain"){
        return new LayerTerrain(&(game->camera), &(game->map),_name, _type, _path);
    }
}

Layer*
TypeRegistry::NewLayer(std::string _layer, std::string _name, std::string _type, ActorInfo _actor_info){
    if(_layer == "actor"){
        return new LayerActor(&(game->camera), &(game->map),_name, _type, _actor_info);
    }
}