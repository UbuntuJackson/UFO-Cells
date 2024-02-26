#ifndef SCENE_H
#define SCENE_H
#include <vector>
#include <memory>
//#include "tilemap_layer.h"
#include "json_interface.h"
class Ray2;
class Button;
class Component;

class Scene{
public:
    std::string name;
    int id_count; //This needs to be higher up the heirarchy, maybe mark this scene as the parent scene

    std::vector<std::unique_ptr<Component>> updatables;
    //std::vector<std::unique_ptr<PropertyRect>> property_rectangles;
    //std::vector<std::unique_ptr<PropertyCircle>> property_circles;
    //std::vector<std::unique_ptr<PropertyRay>> property_rays;
    std::vector<std::unique_ptr<Ray2>> rays;
    std::vector<std::unique_ptr<Scene>> scene_bundle;
    //TilemapLayer tilemap;
    //std::vector<std::unique_ptr<ufo::Renderable>> renderables;
    std::vector<std::unique_ptr<Button>> buttons;
    //std::vector<std::unique_ptr<Menu>> menus;
    //std::vector<std::unique_ptr<Event>> deferred_events;
    //std::vector<std::unique_ptr<Event>> events;

    Scene() = default;
    Scene(std::string _name = "Un-named");

    virtual void OnReady();
    virtual void SuperOnReady();

    template<typename tActor ,typename ...Args>
    tActor* NewActor(Args ...args){

        tActor* actor = new tActor(args...);
        actor->scene_ptr = this; //Can scene pointer be template class?
        int id = id_count++;
        actor->id = id;
        actor->SuperOnReady(args...); //hope this works thanks to virtual functions. if you don't declare it, then it will run the parent class's
        actor->OnReady(args...);     
        return actor.get();
    }

    virtual void UpdateSceneBundle();
    virtual void UpdateGeometry();
    virtual void UpdateTilemap();
    virtual void UpdateScene();
    virtual void DeferActorRemoval();
    virtual void Load(std::string _path);
    virtual void CustomLoad(ujson::JsonNode _json);

};

#endif