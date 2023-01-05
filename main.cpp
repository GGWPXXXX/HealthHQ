#include <iostream>
#include <string>
#include <cstdlib>
#include <windows.h>
using namespace std;

int main()
{

    while (true)
    {
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