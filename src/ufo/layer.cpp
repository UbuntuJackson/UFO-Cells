#include "layer.h"
#include "game.h"
#include "level.h"

Layer::Layer(Level* _level, std::string _name, std::string _type) : level{_level}, name{_name}, type{_type}{}

Layer::~Layer(){}

void Layer::LoadLayer(){} //Map has a pointer to game tho
void Layer::Update(){}
void Layer::Draw(Camera* _camera){}