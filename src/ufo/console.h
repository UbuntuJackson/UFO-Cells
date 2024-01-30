#ifndef CONSOLE_H
#define CONSOLE_H
#include <iostream>
#include <vector>
#include <string>
class Console{
public:
    template<typename Arg, typename ...Args>
    static void Out(Arg&& arg, Args&& ...args){
        std::cout << arg;
        ((std::cout << ", " << args), ...);
        std::cout << std::endl;
    }
    
    template<typename T>
    static void Out(std::vector<T> _vec){
        for(int i = 0; i < _vec.size(); i++){
            if(i != 0) std::cout << ", " << _vec[i];
            else std::cout << _vec[i];
        }
        std::cout << std::endl;
    }
};

#endif