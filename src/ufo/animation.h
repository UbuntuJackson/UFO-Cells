#include "../../external/olcPixelGameEngine.h"
#include <string>
#include <vector>
class Animation{
public:
    float delta_frames;
    std::vector<std::string> frame_decals;
    std::string anim_directory;
    Animation() = default;
    Animation(std::string _directory);
    void LoadFrames(std::string _directory);
    void UpdateDraw();
};