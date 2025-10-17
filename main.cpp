#include "headers/headers.h"

int main()
{
    vector<Users> user;
    string UserInput,choice;

    while(true){
        ClearScreen(1);
        WelcomePageMenu();
        cin>>UserInput;
        choice= ValidateUserInput(UserInput);

        if(choice=="1"){
            ClearScreen(1);
            cout<<"Register working!\n";

        }
        else if(choice=="2"){
            cout<<"Login working!\n";
            ClearScreen(1);
        }
        else if(choice=="0"){
            ClearScreen(1);
            cout<<"Invalid Input\n";
        }
        else{
            ClearScreen(1);
            cout<<"Invalid Input\n";
        }
    }
    return 0;
}
