#ifndef TILEMAP_LAYER_H
#define TILEMAP_LAYER_H
#include "json_interface.h"
#include "collision_system.h"
enum BuiltInShapes{
    ONE_BY_ONE,
    HALF_TOP,
    HALF_DOWN,
    HALF_RIGHT,
    HALF_LEFT,
    THIN_TOP,
    THIN_BOTTOM,
    THIN_RIGHT,
    THIN_LEFT,
    SLOPE_NORTH_WEST,
    SLOPE_SOUTH_WEST,
    SLOPE_NORTH_EAST,
    SLOPE_SOUTH_EAST,
    SLOPE_NORTH_WEST_HALF_BOTTOM,
    SLOPE_SOUTH_WEST_HALF_TOP,
    SLOPE_NORTH_EAST_HALF_BOTTOM,
    SLOPE_SOUTH_EAST_HALF_TOP,
    SLOPE_NORTH_WEST_HALF_RIGHT,
    SLOPE_SOUTH_WEST_HALF_LEFT,
    SLOPE_NORTH_EAST_HALF_RIGHT,
    SLOPE_SOUTH_EAST_HALF_LEFT,
    SEMI_SOLID_DYDX0,
    SEMI_SOLID_TILT_POSITIVE_1,
    SEMI_SOLID_TILT_NEGATIVE_1,
    SEMI_SOLID_TILT_POSITIVE_1_DIV_2,
    SEMI_SOLID_TILT_NEGATIVE_1_DIV_2,
    SEMI_SOLID_TILT_POSITIVE_2,
    SEMI_SOLID_TILT_NEGATIVE_2
};

class TilemapLayer{
    std::vector<int> tilemap_data;

    TilemapLayer(ujson::JsonNode _node);
    void Update();
    void Draw(Camera* _camera);

};

void GenerateShape(int _x, int _y, int _tile_size_s_x_s, int _shape, CollisionSystem* _collision_system){
    float sx = _x * _tile_size_s_x_s;
    float sy = _y * _tile_size_s_x_s;
    switch(_shape){
        case ONE_BY_ONE:
            _collision_system->active_rectangles.push_back(Rect(sx, sy, _tile_size_s_x_s, _tile_size_s_x_s));
            break;
        case HALF_TOP:
            _collision_system->active_rectangles.push_back(Rect(sx, sy, _tile_size_s_x_s, _tile_size_s_x_s*0.5f));
            break;
        case HALF_DOWN:
            _collision_system->active_rectangles.push_back(Rect(sx, sy+_tile_size_s_x_s*0.5f, _tile_size_s_x_s, _tile_size_s_x_s*0.5f));
            break;
    }
}

#endif