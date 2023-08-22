#ifndef CHARACTER_ANIMATION_H
#define CHARACTER_ANIMATION_H
#include <map>
#include <string>
#include <vector>
class CharacterAnimation{
public:
    float delta_frames;
    std::map<std::string, std::vector<std::string>> animations;
private:
    bool play = true;
public:
    CharacterAnimation() = default;
    virtual void LoadAnimations();
    virtual void Play();
    virtual void Stop();
    virtual void Update(std::string _state);
    virtual void Draw();
    
};

#endif