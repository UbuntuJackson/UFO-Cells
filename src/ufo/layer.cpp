#include "layer.h"
#include "game.h"

Layer::Layer(Camera* _camera, CellMap* _map, std::string _name, std::string _type) : camera{_camera}, map{_map}, name{_name}, type{_type}{}

Layer::~Layer(){}

void Layer::LoadLayer(){} //Map has a pointer to game tho
void Layer::Update(){}
void Layer::Draw(Camera* _camera){}