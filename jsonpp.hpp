#include <iostream>
#include <variant>
#include <vector>
#include <map>
#include <string>

namespace jsonpp{

class Json;
struct JsonArray;

using JsonValue = std::variant<
    std::nullptr_t, 
    bool, 
    int, 
    double, 
    std::string, 
    Json, 
    std::shared_ptr<JsonArray>
>;



struct JsonArray
{
    std::vector<JsonValue> values;
    std::string to_string();
};

std::ostream& operator<<(std::ostream& os, const JsonValue jsonvalue);

class Json
{
private:
    std::map<std::string, JsonValue> m_values;
public:
    Json(/* args */) = default;
    Json(std::string key, JsonValue value);
    JsonValue& operator[](std::string key);
    std::string to_string() const;
    // Json parse(std::string json);
    friend std::ostream& operator<<(std::ostream& os, const Json& json);
};



}