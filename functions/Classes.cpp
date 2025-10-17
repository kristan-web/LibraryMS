//Files
#include "../headers/Classes.h"

Users::Users(string Username, string Password){
    this->Username = Username;
    this->Password = Password;

}

void Users::DisplayProfile(){
    cout << "====================================================\n";
    cout << "PROFILE DETAILS:\n";
    cout << "USERNAME: " << Username << endl;
    cout << "====================================================\n";
}
