#ifndef JSON_INTERFACE_H
#define JSON_INTERFACE_H
#include "../../external/cJSON.h"
#include <string>
#include <vector>
namespace ujson{
    cJSON* JsonParse(std::string _path);
    cJSON* GetObject(cJSON* _obj, std::string _name);
    int ArrayLen(cJSON* _obj);
    cJSON* GetElement(cJSON* _obj, int _index);
    cJSON* CreateObject();
    cJSON* CreateString(std::string _s);
    cJSON* CreateNumber(double _num);
    cJSON* CreateNumber(int _num);
    cJSON* CreateArray();
    void AddItemToArray(cJSON* _obj_a, cJSON* _obj_b);
    void AddItemToObject(cJSON* _obj_a, std::string _name, cJSON* _obj_b);
    
    class JsonNode{
    public:
        cJSON *member;
        //JsonNode<string>(std::string _s) : member{CreateString(std::string _s)}{}
        //JsonNode<double>(double _num) : member{CreateNumber(_num)}{}
        //JsonNode<std::vector<JsonNode*>>() : member{CreateArray()}{}
        JsonNode() : member{CreateObject()}{}
        JsonNode(std::string _path) : member{JsonParse(_path)}{}
        JsonNode(cJSON *_j) : member{_j}{}
        void JsonNodeDelete(){cJSON_Delete(member);}
        int GetMember(int _){
            return member->valueint;
        }

        std::string GetMember(std::string _){
            return member->valuestring;
        }

        std::vector<JsonNode> GetMember(std::vector<JsonNode> _){
            std::vector<JsonNode> v;
            for(int i = 0; i < ArrayLen(member); i++){
                v.push_back(JsonNode(GetElement(member, i)));
            }
            return v;
        }

        JsonNode GetJsonNode(std::string _name){
            return JsonNode(GetObject(member, _name));
        }

        template <typename T>
        T GetAs(){
            return GetMember(T());
        }

        void AddNodeToArray(JsonNode* _n){
            AddItemToArray(member, _n->member); //this object may or may not even be an array
        }

        void AddNodeToObject(std::string _s, JsonNode* _n){
            AddItemToObject(member, _s, _n->member);
        }

        std::string GetFileAsString(){
            return cJSON_Print(member);
        }
    };

    //This is to make the json object you create a number, string or array specifically

    class JsonNodeString : public JsonNode{
    public:
        JsonNodeString(std::string _s) : JsonNode(CreateString(_s)){}
    };
    class JsonNodeNumber : public JsonNode{
    public:
        JsonNodeNumber(double _num) : JsonNode(CreateNumber(_num)){}
        JsonNodeNumber(int _num) : JsonNode(CreateNumber(_num)){}
    };
    class JsonNodeArray : public JsonNode{
    public:
        JsonNodeArray() : JsonNode(CreateArray()){}
    };
}
#endif