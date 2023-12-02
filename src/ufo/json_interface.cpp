#include "json_interface.h"
#include "../../external/cJSON.h"
#include <string>
namespace ujson{
    cJSON* JsonParse(std::string _path){
        return cJSON_Parse(_path.c_str());
    }
    cJSON* GetObject(cJSON* _obj, std::string _name){
        return cJSON_GetObjectItemCaseSensitive(_obj, _name.c_str());
    }
    int ArrayLen(cJSON* _obj){
        return cJSON_GetArraySize(_obj);
    }
    cJSON* GetElement(cJSON* _obj, int _index){
        return cJSON_GetArrayItem(_obj, _index);
    }
}