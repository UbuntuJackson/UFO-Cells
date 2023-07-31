#include "dummy.h"
#include "../../external/olcPixelGameEngine.h"
#include "../../src/ufo/cell_actor.h"
#include "../../src/program/program.h"
#include <cmath>
#include "../../src/program/ufo_global.h"
#include <iostream>
#include <fstream>
#include "dummy_test_layer_actor.h"
#include "../../src/ufo/file_utils.h"
#include "../../external/cJSON.h"

Dummy::Dummy(olc::vf2d _position) : CellActor(_position){
    UfoGlobal::program.camera.SetStateFollowPlatfomer(this);
    mask = "decPin";
    mask_decal = UfoGlobal::program.asset_manager.GetDecal(mask);
    input_frame = 0;
    if(!UfoGlobal::program.record_input) ParseInputJson();
}

Dummy::~Dummy(){
    if(UfoGlobal::program.record_input) WriteInputJson(); //Destructor should have been called as you enter MainMenu
    std::cout << "destructor_called" << std::endl;
}

void
Dummy::Update(){

    if(UfoGlobal::program.record_input){
        player_input_recorded.push_back(KeyInput{
            UfoGlobal::program.GetKey(olc::Key::RIGHT).bHeld,
            UfoGlobal::program.GetKey(olc::Key::LEFT).bHeld,
            UfoGlobal::program.GetKey(olc::Key::Z).bPressed
        });
        player_input_play.push_back(KeyInput{
            false, //right_held
            false, //left_held
            false //z_pressed
        });
    }
    else{
        if(input_frame+1 > player_input_play.size()){
            player_input_play.push_back(KeyInput{
                false, //right_held
                false, //left_held
                false //z_pressed
            });
        }
    }

    DummyTestLayerActor* act_layer;

    for(auto layer : UfoGlobal::program.cell_map.layers){
        if(layer->name == "dynamic_solids"){
            act_layer = dynamic_cast<DummyTestLayerActor*>(layer);
            if(act_layer == nullptr){
                std::cout << "dummy.cpp cast failed" << std::endl;
            }
        }
    }

    // INPUT X-AXIS
    if(UfoGlobal::program.GetKey(olc::Key::RIGHT).bHeld || player_input_play[input_frame].right_held) velocity.x += 0.5f;
    if(UfoGlobal::program.GetKey(olc::Key::LEFT).bHeld || player_input_play[input_frame].left_held) velocity.x -= 0.5f;

    former_position = position;

    for(auto act : act_layer->actors){
        olc::vf2d act_new_position = act->position;
        act_new_position.x = act->position.x + act->velocity.x;

        if(IsOverlappingOtherDecal(mask_decal, position, UfoGlobal::program.asset_manager.GetDecal(act->mask), act_new_position)){
            int a = 0;
            if(act->velocity.x < 0.0f){ //next frame
                position.x = std::floor(position.x);
                while(IsOverlappingOtherDecal(mask_decal, position, UfoGlobal::program.asset_manager.GetDecal(act->mask), act_new_position)){
                    position.x -= 1.0f;
                }
            }
            if(act->velocity.x > 0.0f){ //next frame
                position.x = std::ceil(position.x);
                while(IsOverlappingOtherDecal(mask_decal, position, UfoGlobal::program.asset_manager.GetDecal(act->mask), act_new_position)){
                    position.x += 1.0f;
                }
            }
            
            velocity.x = 0.0f;
        }
    }

    position.x += velocity.x;
    velocity.x *= 0.85f;

    //HEIGHT ADJUSTMENT OVERLAP
    AdjustUpSlope();
    // COLLISION ADJUSTMENT X-AXIS
    AdjustCollisionX();
    //ThisVsDynamicSolid
    for(auto act : act_layer->actors){
        olc::vf2d act_new_position = act->position;
        act_new_position.x = act->position.x + act->velocity.x;

        if(IsOverlappingOtherDecal(mask_decal, position, UfoGlobal::program.asset_manager.GetDecal(act->mask), act_new_position)){
            int a = 0;
            if(velocity.x > 0.0f){ //next frame
                position.x = std::floor(position.x);
                while(IsOverlappingOtherDecal(mask_decal, position, UfoGlobal::program.asset_manager.GetDecal(act->mask), act_new_position)){
                    position.x -= 1.0f;
                }
            }
            if(velocity.x < 0.0f){
                position.x = std::ceil(position.x);
                while(IsOverlappingOtherDecal(mask_decal, position, UfoGlobal::program.asset_manager.GetDecal(act->mask), act_new_position)){
                    position.x += 1.0f;
                }
            }
            velocity.x = 0.0f;
        }
    }

    // ADJUSTMENT ALONG Y-AXIS
    is_already_in_semi_solid = false;
    is_already_in_semi_solid = IsOverlapping(mask_decal, solid_layer, position, olc::RED);

    //if(UfoGlobal::program.GetKey(olc::Key::UP).bHeld) velocity.y -= 0.5f;
    //if(UfoGlobal::program.GetKey(olc::Key::DOWN).bHeld) velocity.y += 0.5f;

    //Checking before we intend to move along the Y-Axis

    for(auto act : act_layer->actors){
        olc::vf2d act_new_position = act->position;
        act_new_position = act->position + act->velocity;

        if(IsOverlappingOtherDecal(mask_decal, position, UfoGlobal::program.asset_manager.GetDecal(act->mask), act_new_position)){
            if(act->velocity.y < 0.0f){
                position.y = std::floor(position.y);
                while(IsOverlappingOtherDecal(mask_decal, position, UfoGlobal::program.asset_manager.GetDecal(act->mask), act_new_position)){
                    position.y -= 1.0f;
                }
            }
            if(act->velocity.y > 0.0f){
                position.y = std::floor(position.y);
                while(IsOverlappingOtherDecal(mask_decal, position, UfoGlobal::program.asset_manager.GetDecal(act->mask), act_new_position)){
                    position.y += 1.0f;
                }
            }
            if(velocity.y > 0.0f) is_grounded = true;
            velocity.y = 0.0f;
        }
    }

    if((UfoGlobal::program.GetKey(olc::Key::Z).bPressed || player_input_play[input_frame].z_pressed == true) && (was_grounded || is_grounded)){
        velocity.y = -10.0f;
    } //I would consider putting this right after the OnEnteredCollisionY() call, which would also mean that was_grounded = is_grounded needs to be put after that

    was_grounded = is_grounded;

    velocity.y += 0.7f;
    is_grounded = false;
    position.y += velocity.y;
    velocity.y *= 0.99f;

    AdjustCollisionY();

    for(auto act : act_layer->actors){
        olc::vf2d act_new_position = act->position;
        act_new_position = act->position + act->velocity;

        if(IsOverlappingOtherDecal(mask_decal, position, UfoGlobal::program.asset_manager.GetDecal(act->mask), act_new_position)){
            if(velocity.y > 0.0f){
                position.y = std::floor(position.y);
                while(IsOverlappingOtherDecal(mask_decal, position, UfoGlobal::program.asset_manager.GetDecal(act->mask), act_new_position)){
                    position.y -= 1.0f;
                }
            }
            if(velocity.y < 0.0f){
                position.y = std::floor(position.y);
                while(IsOverlappingOtherDecal(mask_decal, position, UfoGlobal::program.asset_manager.GetDecal(act->mask), act_new_position)){
                    position.y += 1.0f;
                }
            }
            if(velocity.y > 0.0f) is_grounded = true;
            velocity.y = 0.0f;
            if(is_grounded) position.x += act->velocity.x;
        }
    }

    AdjustDownSlope();

    input_frame++;
}

void
Dummy::AdjustCollisionX(){
    if(IsOverlapping(mask_decal, solid_layer, position)){
        if(velocity.x > 0.0f){
            position.x = std::floor(position.x);
            while(IsOverlapping(mask_decal, solid_layer, position)){
                position.x -= 1.0f;
            }
        }
        if(velocity.x < 0.0f){
            position.x = std::ceil(position.x);
            while(IsOverlapping(mask_decal, solid_layer, position)){
                position.x += 1.0f;
            }
        }
        velocity.x = 0.0f;
    }
}

void
Dummy::AdjustCollisionY(){
    if(IsOverlapping(mask_decal, solid_layer, position)){
        if(velocity.y > 0.0f){
            is_grounded = true;
            position.y = std::floor(position.y);
            while(IsOverlapping(mask_decal, solid_layer, position)){
                position.y -= 1.0f;
            }
        }
        if(velocity.y < 0.0f){
            position.y = std::ceil(position.y);
            while(IsOverlapping(mask_decal, solid_layer, position)){
                position.y += 1.0f;
            }
        }

        velocity.y = 0.0f;
    }

    //SEMI SOLID

    if(IsOverlapping(mask_decal, solid_layer, position, olc::RED) &&
        velocity.y > 0.0f &&
        !is_already_in_semi_solid){
        if(velocity.y > 0.0f){
            is_grounded = true;
            position.y = std::floor(position.y);
            while(IsOverlapping(mask_decal, solid_layer, position, olc::RED)){
                position.y -= 1.0f;
            }
        }
        if(velocity.y < 0.0f){
            position.y = std::ceil(position.y);
            while(IsOverlapping(mask_decal, solid_layer, position, olc::RED)){
                position.y += 1.0f;
            }
        }

        velocity.y = 0.0f;
    }
}

void
Dummy::AdjustUpSlope(){
    //SOLID

    if(IsOverlapping(mask_decal, solid_layer, position)){
        former_position.y = std::floor(former_position.y);

        if(velocity.x > 0.0f){
            former_position.x = std::floor(former_position.x);
        }
        if(velocity.x < 0.0f){
            former_position.x = std::ceil(former_position.x);
        }

        if(velocity.x > 0.0f){

            while(std::floor(former_position.x) != std::floor(position.x)+1.0f){
                if(IsOverlappingHeight(mask_decal, solid_layer, former_position) > int(former_position.y) + snap_up_range
                    && IsOverlappingHeight(mask_decal, solid_layer, former_position) != former_position.y +
                    mask_decal->sprite->Size().y){

                    while(IsOverlapping(mask_decal, solid_layer, former_position)){
                        former_position.y -= 1.0f;
                    }

                }

                former_position.x += 1.0f;
            }
            //if you're still in collision after moving +=1.0f, then you move up again
            if(IsOverlappingHeight(mask_decal, solid_layer, former_position) > int(former_position.y) + snap_up_range){
                while(IsOverlapping(mask_decal, solid_layer, former_position)){
                    former_position.y -= 1.0f;
                }
            }
        }

        if(velocity.x < 0.0f){
            while(former_position.x != std::floor(position.x)){

                if(IsOverlappingHeight(mask_decal, solid_layer, former_position) > int(former_position.y) + snap_up_range
                    && IsOverlappingHeight(mask_decal, solid_layer, former_position) != former_position.y +
                    mask_decal->sprite->Size().y){
                    while(IsOverlapping(mask_decal, solid_layer, former_position)){
                        former_position.y -= 1.0f;
                    }

                }

                former_position.x -= 1.0f;
            }

            if(IsOverlappingHeight(mask_decal, solid_layer, former_position) > int(former_position.y) + snap_up_range){
                while(IsOverlapping(mask_decal, solid_layer, former_position)){
                    former_position.y -= 1.0f;
                }

            }
        }
    }

    //SEMI SOLID ADJUST_HEIGHT

    if(IsOverlapping(mask_decal, solid_layer, position, olc::RED) && !is_already_in_semi_solid){
        former_position.y = std::floor(former_position.y);

        if(velocity.x > 0.0f){
            former_position.x = std::floor(former_position.x);
        }
        if(velocity.x < 0.0f){
            former_position.x = std::ceil(former_position.x);
        }

        if(velocity.x > 0.0f){

            while(std::floor(former_position.x) != std::floor(position.x)+1.0f){
                if(IsOverlappingHeight(mask_decal, solid_layer, former_position, olc::RED) > int(former_position.y) + snap_up_range
                    && IsOverlappingHeight(mask_decal, solid_layer, former_position, olc::RED) != former_position.y +
                    mask_decal->sprite->Size().y){

                    while(IsOverlapping(mask_decal, solid_layer, former_position, olc::RED)){
                        former_position.y -= 1.0f;
                    }

                }

                former_position.x += 1.0f;
            }

            if(IsOverlappingHeight(mask_decal, solid_layer, former_position, olc::RED) > int(former_position.y) + snap_up_range){
                while(IsOverlapping(mask_decal, solid_layer, former_position, olc::RED)){
                    former_position.y -= 1.0f;
                }
            }
        }

        if(velocity.x < 0.0f){
            while(former_position.x != std::floor(position.x)){

                if(IsOverlappingHeight(mask_decal, solid_layer, former_position, olc::RED) > int(former_position.y) + snap_up_range
                    && IsOverlappingHeight(mask_decal, solid_layer, former_position, olc::RED) != former_position.y +
                    mask_decal->sprite->Size().y){
                    while(IsOverlapping(mask_decal, solid_layer, former_position, olc::RED)){
                        former_position.y -= 1.0f;
                    }

                }

                former_position.x -= 1.0f;
            }

            if(IsOverlappingHeight(mask_decal, solid_layer, former_position, olc::RED) > int(former_position.y) + snap_up_range){
                while(IsOverlapping(mask_decal, solid_layer, former_position, olc::RED)){
                    former_position.y -= 1.0f;
                }

            }
        }
    }
    position.y = former_position.y;
}

void
Dummy::AdjustDownSlope(){
    //HEIGHT ADJUSTMENT SNAP_TO_GROUND

    if(was_grounded == true && is_grounded == false && velocity.y > 0.0f){
        position.y = std::floor(position.y);
        if(HeightUntilGround(mask_decal, solid_layer, position) < snap_to_ground){
            while(!IsOverlapping(mask_decal, solid_layer, position)){

                position.y += 1.0f;

            }
            position.y -= 1.0f;
            is_grounded = true;
        }
    }

    //SEMI SOLID HEIGHT ADJUSTMENT SNAP_TO_GROUND
    if(was_grounded == true && is_grounded == false && velocity.y > 0.0f){
        position.y = std::floor(position.y);
        if(HeightUntilGround(mask_decal, solid_layer, position, olc::RED) < snap_to_ground){
            while(!IsOverlapping(mask_decal, solid_layer, position, olc::RED)){

                position.y += 1.0f;

            }
            position.y -= 1.0f;
            is_grounded = true;
        }
    }
}

void Dummy::WriteInputJson(){
    cJSON* input_json = cJSON_CreateObject();
    if (input_json == nullptr) std::cout << "failed to create input_json" << std::endl;
    cJSON* inputs = cJSON_CreateArray();
    inputs = cJSON_AddArrayToObject(input_json, "inputs");
    for(auto i : player_input_recorded){
        cJSON* obj = cJSON_CreateObject();
        cJSON* right_held = cJSON_CreateBool(i.right_held);
        cJSON* left_held = cJSON_CreateBool(i.left_held);
        cJSON* z_pressed = cJSON_CreateBool(i.z_pressed);
        cJSON_AddItemToObject(obj, "right_held", right_held);
        cJSON_AddItemToObject(obj, "left_held", left_held);
        cJSON_AddItemToObject(obj, "z_pressed", z_pressed);
        cJSON_AddItemToArray(inputs, obj);

    }
    std::string input_json_s = cJSON_Print(input_json);
    std::ofstream my_file;
    my_file.open("inputs.json");
    my_file << input_json_s;
    my_file.close();

    cJSON_Delete(input_json);
}

void Dummy::ParseInputJson(){
    std::ifstream ifs;
    ifs.open("inputs.json", std::ifstream::in);
    std::string sl = PutFileIntoString(ifs);
    ifs.close();
    cJSON *j = cJSON_Parse(sl.c_str());

    const cJSON *l1 = cJSON_GetObjectItemCaseSensitive(j, "inputs");
    for(int i = 0; i < cJSON_GetArraySize(l1); i++){
        const cJSON *item = cJSON_GetArrayItem(l1, i);
        bool right_held = cJSON_GetObjectItemCaseSensitive(item, "right_held") -> valueint;
        bool left_held = cJSON_GetObjectItemCaseSensitive(item, "left_held") -> valueint;
        bool z_pressed = cJSON_GetObjectItemCaseSensitive(item, "z_pressed") -> valueint;

        player_input_play.push_back(KeyInput{right_held, left_held, z_pressed});
        std::cout << right_held << "," << left_held << ","<< z_pressed << std::endl;
    }

    cJSON_Delete(j);
}

void
Dummy::Draw(){
    UfoGlobal::program.camera.DrawDecal(
        position,
        mask_decal);
}