// Import all necessary module.
#include <iostream>
#include <string>
#include <cstdlib>
#include <windows.h>
#include <fstream>
#include "../HealthHQ/json-develop/single_include/nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

int main()

{
    Login("nakenat12", "a123");
    while (true)
    {
        // Main menu
        int choice;
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
            system("cls");
            cout<<"Invalid input.\n";
            Sleep(1000);
            system("cls");
            break;
        }
    }
    
}