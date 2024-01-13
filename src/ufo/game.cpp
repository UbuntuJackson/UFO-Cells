#define OLC_PGE_APPLICATION
#include "game.h"

Game::Game()
{
    sAppName = "UFO-Cells";
}

Game::~Game(){
}

bool Game::OnUserCreate(){
    LoadResources();
    return true;
}

bool Game::OnUserUpdate(float fElapsedTime){
    dt = fElapsedTime;
    Clear(olc::GREY);
    SetPixelMode(olc::Pixel::NORMAL);

    SetPixelMode(olc::Pixel::NORMAL);
    return running;
}

void Game::LoadResources(){

}