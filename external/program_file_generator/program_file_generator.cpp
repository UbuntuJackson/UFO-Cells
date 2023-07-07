#ifdef PATH
#include <iostream>
#include <fstream>

int main(){
    std::ofstream outfile ("program.cpp");
    outfile << "#include \"../games/\"#PATH\"/game.h\""
                "Program::Program(){games.push_back(Game());}"
                "Program::OnUserUpdate(){for(auto g : games){g.state > Update();}}" << std::endl;
    outfile.close();
    return 0;
}
#endif
