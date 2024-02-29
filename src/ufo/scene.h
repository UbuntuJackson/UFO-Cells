#ifndef SCENE_H
#define SCENE_H
#include <vector>
#include <memory>
//#include "tilemap_layer.h"
#include "json_interface.h"
#include "component.h"
#include "ray2.h"
#include "button.h"
#include "updatable.h"

class SceneSystem;
class Game;

class Scene{
public:
    SceneSystem* scene_system;

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

    Scene(std::string _name = "Un-named");

    virtual void OnReady();
    virtual void SuperOnReady();
    template<typename T>
    struct Identity{typedef T type;};

    template<typename tActor ,typename ...Args>
    tActor* NewActor(Args ...args){
        return NewActor(Identity<tActor>(), args...);
    }

private:
    template<typename tActor ,typename ...Args>
    tActor* NewActor(Identity<tActor> _, Args ...args){
        tActor* actor = new tActor(args...);
        actor->scene_ptr = this; //Can scene pointer be template class?
        int id = id_count++;
        actor->id = id;
        //actor->SuperOnReady(args...); //hope this works thanks to virtual functions. if you don't declare it, then it will run the parent class's
        //actor->OnReady(args...);     
        return actor;
    }

    template<typename ...Args>
    Ray2* NewActor(Identity<Ray2> _, Args ...args){

        Ray2* actor = new Ray2(args...);   
        rays.push_back(std::unique_ptr<Ray2>(actor)); 
        return actor;
    }

    template<typename ...Args>
    Updatable* NewActor(Identity<Updatable> _, Args ...args){
        //actor->SuperOnReady(args...); //hope this works thanks to virtual functions. if you don't declare it, then it will run the parent class's
        //actor->OnReady(args...);        
        updatables.push_back(std::make_unique<Updatable>(args...)); 
        updatables.back()->scene_ptr = this; //Can scene pointer be template class?
        int id = id_count++;
        updatables.back()->id = id;
        return updatables.back()->get(); //using .back() here can be deterimental if for example the previously made updatable here adds something to updatables too.
    }
public:
    virtual void UpdateSceneBundle();
    virtual void UpdateGeometry();
    virtual void UpdateTilemap();
    virtual void UpdateScene();
    virtual void DrawScene();
    virtual void DeferActorRemoval();
    virtual void Load(std::string _path);
    virtual void CustomLoad(ujson::JsonNode _json);

};

#endif