#include "jsonpp.hpp"

using namespace std;
using namespace jsonpp;

int main()
{
    Json json;
    json["name"] = "John Doe";
    json["age"] = 30;
    json["is_student"] = false;
    json["marks"] = 95.5;
    json["address"] = Json("city", "New York");

    cout << json.to_string() << endl;
    cout << json["age"] << endl;
    cout << json["is_student"] << endl;
    cout << json["marks"] << endl;
    // cout << json["address"]["city"] << endl;

    return 0;
}