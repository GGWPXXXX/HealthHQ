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
        Patient(){}
        // Check if the id and birth in database or not
        bool setName(string new_name, string personal_id, string date_of_birth)
        {
            json patient_data;
            ifstream file ("../HealthHQ/Patient/Patient_credential.json");
            file >> patient_data;
            for (auto & element: patient_data.items())
            {
                string key = element.key();
                json dataTable = element.value();
                if (dataTable["personal_id"] == personal_id && dataTable["date_of_birth"] == date_of_birth)
                {
                    std::map<std::string, std::string> form = {
                        {"personal_id", dataTable["personal_id"]},
                        {"name", new_name},
                        {"lastname", dataTable["lastname"]},
                        {"date_of_birth", dataTable["date_of_birth"]},
                        {"gender", dataTable["gender"]},
                        {"address", dataTable["address"]},
                        {"phone", dataTable["phone"]},
                        {"email", dataTable["email"]}
                    };
                    patient_data[key].update(form); 
                    ofstream jsonFile("../HealthHQ/Patient/Patient_credential.json");
                    jsonFile << patient_data.dump(4);
                    jsonFile.close();

                    return true;
                }
            }
            return false;
        }

};
int main()
{
    Patient Patient1;
    cout<<Patient1.setName("Kong", "1948822365845", "31122008");
}