// Import all necessary module.
#include <iostream>
#include <string>
#include <cstdlib>
#include <windows.h>
#include <fstream>
#include "../HealthHQ/json/single_include/nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

void Login(string username, string password)
{
    ifstream file("../HealthHQ/Patient/Patient_credential.json");
    json data;
    file>> data;
    for (auto& element : data.items())
    {
        string key = element.key();
        json value = element.value();
        cout<<key<<value["personal_id"];
    }
}
int main()
{
    Login("nakenat12", "a123");
    while (true)
    {
        // Main menu
        int choice;
        cout<<"Welcome to GG_WPX Hospital"<<endl;
        cout<<"----------------------------"<<endl;
        cout<<"Please select an option from the menu below"<<endl;
        cout<<"1. Make an appointment.\n";
        cout<<"2. View my appointment.\n";
        cout<<"3. Cancel an appointment.\n";
        cout<<"4. View hospital information.\n";
        cout<<"5. Exit\n";
        cout<<": ";
        cin>>choice;
        switch (choice)
        {
        case 1:    
            break;
        case 2:
            break;
        case 3 :
            break;
        case 4 :
            break;
        case 5 :
            break;
        
        default:
            system("clear");
            cout<<"Invalid input.\n";
            Sleep(1000);
            system("clear");
            break;
        }
    }
    
}