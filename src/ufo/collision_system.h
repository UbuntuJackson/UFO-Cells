#ifndef COLLISION_SYSTEM_H
#define COLLISION_SYSTEM_H

#include <vector>
#include "circle.h"
#include "rect.h"
#include "collision_utils.h"
#include "console.h"
#include "math_misc.h"

struct RectVsRectCollisionData{
    bool is_overlapping;
};

class CollisionSystem{
public:
    CollisionSystem() = default;
    //std::vector<TilemapLayer> tilemaps_layers;
    //std::vector<BitmapLayer> bitmap_layers;
    //std::vector<GeometryLayer> geometry_layers;
    std::vector<Rect> rectangles;

    std::vector<GeometryLayer*> geometry_layers;
    std::vector<TilemapLayer*> tilemap_layers;

    bool IsOverlapping(const Rect _a, const Rect _b){
        if(RectVsRect(_a, _b)){
            return true;
        }
    }

    bool IsOverlapping(const Circle _a, const Circle _b){

    }

    void
    ApplyCollision(olc::vf2d &_position, olc::vf2d &_collision, Rect &_shape){
        for(Rect& rect : rectangles){
            
        }
    }

    template <typename T_Actor>
    RectVsRectCollisionData
    ApplyCollision(T_Actor *_actor, Rect* _shape){
        /*for(int l : _actor.layer_tags){
            for(Rect rect : geometry_layers[l].rectangles){
                if(RectVsRect(_shape, rect)){
                    Console::Out("RectVsRect!");
                }
            }
        }*/

        for(Rect& rect : rectangles){
            if(RectVsRect(*_shape, rect)){
                return RectVsRectCollisionData{true};
            }
        }
        return RectVsRectCollisionData{false};
    }
};

#endif