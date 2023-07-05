#include <iostream>
#include <fstream>

int main(){
    std::ofstream outfile ("program.cpp");
    outfile << "#include ../games/" + OUTPUT_FILE + "/game.h Program::Program(){games.push_back(Game());} Program::OnUserUpdate(){for(auto g : games){g.state > RunState();}}" << std::endl;
    outfile.close();
    return 0;
}
