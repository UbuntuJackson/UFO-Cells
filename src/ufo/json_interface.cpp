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
    cJSON* CreateObject(){
        return cJSON_CreateObject();
    }
    cJSON* CreateString(std::string _s){
        return cJSON_CreateString(_s.c_str());
    }
    cJSON* CreateNumber(double _num){
        return cJSON_CreateNumber(_num);
    }
    cJSON* CreateNumber(int _num){
        return cJSON_CreateNumber(_num);
    }
    cJSON* CreateArray(){
        return cJSON_CreateArray();
    }
    void AddItemToArray(cJSON* _obj_a, cJSON* _obj_b){
        cJSON_AddItemToArray(_obj_a, _obj_b);
    }
    void AddItemToObject(cJSON* _obj_a, std::string _name, cJSON* _obj_b){
        cJSON_AddItemToObject(_obj_a, _name.c_str(), _obj_b);
    }
}