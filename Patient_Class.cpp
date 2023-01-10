// Import all necessary module.
#include <iostream>
#include <string>
#include <cstdlib>
#include <windows.h>
#include <fstream>
#include "../HealthHQ/json-develop/single_include/nlohmann/json.hpp"


using namespace std;    
using json = nlohmann::json;

class Patient{
    public: 
        string id, birth;
        // Constructor.
        Patient(string personal_id, string date_of_birth)
        {
            id = personal_id;
            birth = date_of_birth;
        }

        // Check if the id and birth in database or not
        bool isPatient()
        {   
            json data;
            ifstream file("../HealthHQ/Patient/Patient_credential.json");
            file>>data;
            cout<<id<<"\n";
            cout<<birth<<"\n";
            for (auto& element: data.items())
            {
                string key = element.key();
                json value = element.value();
                if (id == value["personal_id"] && birth == value["date_of_birth"])
                {
                    return true;
                }
            }
            return false;
        }  
    
};
int main()
{
    Patient Patient1("1948822365845", "31122546");
    cout<<Patient1.isPatient();
}