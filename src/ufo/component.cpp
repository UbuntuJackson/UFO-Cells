#include "component.h"
#include <string>

Component::Component(std::string _name) : name{_name}{}

void
Component::SuperOnReady(){}

void
Component::OnReady(){}

void
Component::SuperUpdate(){}

void
Component::SuperDraw(){}

void
Component::Update(){}

void
Component::Draw(){}

void
Component::PrintTree(int _depth = 0){
    std::string indent = "";
    for(int _ = 0; _ < _depth; _++) indent += std::string("    ");
    Console::Out(std::string(indent) + " " + name);
    for(auto node : nodes){
        node->PrintTree(_depth+1);
    }
}

void
Component::UpdateCallbacks(){
    Console::Out(name, "Update");
    SuperUpdate();
    Update();
    for(int i = 0; i < nodes.size(); i++){
        nodes[i]->UpdateCallbacks();
    }
}

void
Component::DrawCallbacks(){
    Console::Out(name, "Draw");
    SuperDraw();
    Draw();
    for(int i = 0; i < nodes.size(); i++){
        nodes[i]->DrawCallbacks();
    }
}

Component::~Component(){
    for(auto node : nodes){
        delete node;
    }
    Console::Out(name, "Destructor");
}