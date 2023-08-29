#include "state.h"
#include <string>
#include <iostream>

class Game;

State::~State(){}
void State::SetPlay(std::string _map){}
void State::SetLoad(std::string _map){}
void State::SetMenu(std::string _menu){}
void State::Update(){
    std::cout << "Empty state updates successfully" << std::endl;
}
void State::Set(std::string _data){}
std::string State::GetData(){}