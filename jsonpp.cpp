#include "jsonpp.hpp"
#include <variant>

using namespace std;
using namespace jsonpp;

struct JsonValueVisitor{
    string& str;
    JsonValueVisitor(string& str): str(str){}
    void operator()(std::nullptr_t) const{ str += "null"; }
    void operator()(bool value) const{ str += value ? "true" : "false"; }
    void operator()(int value) const{ str += to_string(value); }
    void operator()(double value) const{ str += to_string(value); }
    void operator()(string value) const{ str += "\"" + value + "\""; }
    void operator()(Json value) const{ str += value.to_string(); }
    void operator()(shared_ptr<JsonArray> value) const{
        JsonArray arr = *value;
        str += "[";
        for(auto& val : arr.values){
            visit(JsonValueVisitor(str), val);
            str += ",";
        }
        str.pop_back();
        str += "]";
    }

    template<typename T>
    void operator()(const T& value) const{ 
        str += to_string(value);
    }
};

Json::Json(std::string key, JsonValue value)
{
    m_values[key] = value;
}

JsonValue& Json::operator[](std::string key)
{
    return m_values[key];
}

string Json::to_string() const{
    string str = "{";
    for(auto& [key, value] : m_values){
        str += "\"" + key + "\":";
        visit(JsonValueVisitor(str), value);
        str += ",";
    }
    str.pop_back();
    str += "}";
    return str;
}

string JsonArray::to_string(){
    string str = "[";
    for(auto& value : values){
        visit(JsonValueVisitor(str), value);
        str += ",";
    }
    str.pop_back();
    str += "]";
    return str;
}

ostream& jsonpp::operator<<(ostream& os, const Json& json){
    os << json.to_string();
    return os;
}
ostream& jsonpp::operator<<(ostream& os, const JsonValue jsonvalue){
    string str;
    visit(JsonValueVisitor(str), jsonvalue);
    os << str;
    return os;
}
