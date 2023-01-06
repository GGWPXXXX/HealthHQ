#include <iostream>
#include <string>
#include <cstdlib>
#include <windows.h>
#include <fstream>
#include "../HealthHQ/json/single_include/nlohmann/json.hpp"


using namespace std;
using json = nlohmann::json;

class Patient{
    public: 
    string personal_id, date_of_birth;
    // Constructor.
    Patient(string personal_id, string date_of_birth)
    {
        ifstream file("../HealthHQ/Patient/Patient_credential.json");
        json data;
        file>> data;
        for (auto& element : data.items())
        {
            string keys = element.key();
            json value  = element.value();
            cout<<keys<<value;
        }
        string id = personal_id;
        string birth = date_of_birth;
    }
    
};
int main()
{
    return 0
}