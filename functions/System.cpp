#include "../headers/Menus.h"

void ClearScreen(int delay){
    Sleep(delay * 500);
    system("cls");
}

string ValidateUserInput(string UserInput){

    for(char c : UserInput){
        if(c == ' ' || c == '\t'){
            cout << "ERROR: Space(s) detected." << endl;
            return "0";
        }
    }
    if(UserInput == "1" || UserInput == "2" || UserInput == "3" || UserInput == "4" || UserInput == "5"){
        return UserInput;  // Simplified - just return the input
    }
    else{
        return "0";
    }
}
