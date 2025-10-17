#include "headers/headers.h"

int main()
{
    //Vectors
    vector<Users> user;

    //Variables
    bool ProgramExit = false;
    string UserChoice;
    int IndexNum;

    //Program starts here
    CreateObjectsFromUsersFile(user);
    TermsAndCondition();

    while(!ProgramExit){
        ClearScreen(1);
        UserChoice = AccountCreationMenu();
        if(UserChoice == "1"){
            IndexNum = -1;
            if(LogInProcess(user, IndexNum)){

            }
        }
        else if(UserChoice == "2"){
            if(RegistrationProcess(user));
        }
        else if(UserChoice == "3"){
            ProgramExit = true;
        }
    }
    cout<<"goodbye";
    return 0;
}

