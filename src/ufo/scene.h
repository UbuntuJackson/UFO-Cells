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
#include "component_wrapper.h"

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
    std::vector<std::unique_ptr<ComponentWrapper<Ray2>>> rays; //would need to be wrapped if I want to autodestruct. Push unique_ptr<ComponentWrapper<Ray>> instead.
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
        tActor* actor = new tActor(args...); //depends on scene_ptr being valid. I feel so dumb.
        actor->scene_ptr = this; //Can scene pointer be template class?
        int id = id_count++;
        actor->id = id;
        //actor->SuperOnReady(args...); //hope this works thanks to virtual functions. if you don't declare it, then it will run the parent class's
        //actor->OnReady(args...);     
        return actor;
    }

    /*template<typename tActor ,typename ...Args>
    ComponentWrapper<tActor>* NewActor(Identity<ComponentWrapper<tActor>> _, Args ...args){
        ComponentWrapper<tActor>* actor = new ComponentWrapper<tActor>(args...);
        actor->scene_ptr = this; //Can scene pointer be template class?
        int id = id_count++;
        actor->id = id;
        //actor->SuperOnReady(args...); //hope this works thanks to virtual functions. if you don't declare it, then it will run the parent class's
        //actor->OnReady(args...);     
        return actor->GetComponent();
    }*/

    template<typename ...Args>
    ComponentWrapper<Ray2>* NewActor(Identity<Ray2> _, Args ...args){
        ComponentWrapper<Ray2> *cwr = new ComponentWrapper(Ray2(args...))
        rays.push_back(std::unique_ptr<ComponentWrapper<Ray2>>(cwr));
        return rays.back(); //how do I know for certain that this is the element I originally pushed?
    }

    template<typename ...Args>
    Updatable* NewActor(Identity<Updatable> _, Args ...args){

        Updatable* actor = new Updatable(args...);
        actor->scene_ptr = this; //Can scene pointer be template class?
        int id = id_count++;
        actor->id = id;
        //actor->SuperOnReady(args...); //hope this works thanks to virtual functions. if you don't declare it, then it will run the parent class's
        //actor->OnReady(args...);        
        updatables.push_back(std::unique_ptr<Updatable>(actor)); 
        return actor;
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