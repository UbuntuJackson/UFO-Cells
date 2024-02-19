#ifndef COLLISION_SYSTEM_H
#define COLLISION_SYSTEM_H

#include <vector>
#include "circle.h"
#include "rect.h"
#include "collision_utils.h"
#include "console.h"

class CollisionSystem{

    //std::vector<TilemapLayer> tilemaps_layers;
    //std::vector<BitmapLayer> bitmap_layers;
    //std::vector<GeometryLayer> geometry_layers;
    std::vector<Rect> rectangles;

    template <typename T_Actor>
    void
    ApplyCollision(T_Actor &_actor){
        ApplyCollision(_actor, _actor.shape);
        
    }

    /*template <typename T_Actor>
    void
    ApplyCollision(T_Actor &_actor, ufo::Decal* _shape){

    }*/

    template <typename T_Actor>
    void
    ApplyCollision(T_Actor &_actor, Circle* _shape){

    }

    template <typename T_Actor>
    void
    ApplyCollision(T_Actor &_actor, Rect* _shape){
        /*for(int l : _actor.layer_tags){
            for(Rect rect : geometry_layers[l].rectangles){
                if(RectVsRect(_shape, rect)){
                    Console::Out("RectVsRect!");
                }
            }
        }*/

        for(Rect rect : rectangles){
            if(RectVsRect(_shape, rect)){
                Console::Out("RectVsRect!");
            }
        }
    }
};

#endif