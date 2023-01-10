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
        void showAppointments()
        {
            json appointment_data;
            ifstream file("../HealthHQ/Record/Appointment.json");
            file>>appointment_data;
            for(auto& element : appointment_data.items())
            {
                string num = element.key();
                json information = element.value();
                if (id == information["personal_id"] && birth == information["date_of_birth"])
                {
                    int appointment_num = 1;
                    for (auto & sche : information["appointment"].items())
                    {

                        string key = sche.key();
                        json sche_info = sche.value();
                        if (sche_info["status"] == "confirmed" || sche_info["status"] == "pending")
                        {

                            cout<<"--------------------------------------------------------\n";
                            cout<<"Your appointment number # "<<appointment_num<<" are the following\n";
                            cout<<"--------------------------------------------------------\n";
                            cout<<"Symptom: "<<sche_info["symptoms"]<<"\n";
                            cout<<"Date: "<<sche_info["date"]<<"\n";
                            cout<<"Doctor: "<<sche_info["doctor"]<<"\n";
                            appointment_num ++ ;
                        }
                        else
                        {
                            cout<<"Sorry there's no appointment scheduled for you.";
                        
                        }
                    
                    }
                
                }           
            }
        }

    
};
int main()
{
    Patient Patient1("1948822365845", "31122546");
    Patient1.showAppointments();
}