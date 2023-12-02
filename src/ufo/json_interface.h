#ifndef JSON_INTERFACE_H
#define JSON_INTERFACE_H
#include "../../external/cJSON.h"
#include <string>
namespace ujson{
    cJSON* JsonParse(std::string _path);
    cJSON* GetObject(cJSON* _obj, std::string _name);
    int ArrayLen(cJSON* _obj);
    cJSON* GetElement(cJSON* _obj, int _index);
    
    class JsonNode{
    public:
        cJSON *member;
        JsonNode(std::string _path) : member{JsonParse(_path)}{}
        int GetMember(int _){
            return member->valueint;
        }
        JsonNode(cJSON *_j) : member{_j}{}

        std::string GetMember(std::string _){
            return member->valuestring;
        }

        std::vector<JsonNode> GetMember(std::vector<JsonNode> _){
            std::vector<JsonNode> v;
            for(int i = 0; i < ArrayLen(member); i++){
                v.push_back(JsonNode(GetElement(i)));
            }
            return v;
        }

        JsonNode GetObject(std::string _name){
            return JsonNode(GetObject(member, _name));
        }

        template <typename T>
        T GetAs(){
            return GetMember(T());
        }
    };
}
#endif