//Files
#include "../headers/AccountCreation.h"
#include "../headers/headers.h"

bool RegistrationProcess(vector<Users>& user){
    //Variables
    string Username, Password, PassConf, TempVar;
    bool FunctionExit = false;
    bool UsernameFound = false;
    bool PasswordConfirmed = false;

    //Program starts here
    while(!FunctionExit){
        cout << "===============================================\n\n";
        cout << "   R E G I S T R A T I O N    P R O C E S S\n\n";
        cout << "===============================================\n";
        cout << "-- You can type 'q' to quit registration process\n\n";
        cout << "ENTER A USERNAME: ";
        getline(cin, Username);
        TempVar = ValidateAccountCreation(Username);

        if(TempVar == "0"){
            cout << "Using space is prohibited." << endl;
        }
        else if(TempVar == "1"){
            cout << "Username must be longer than 8" << endl;
        }
        else if(TempVar == "100"){
            return false;
            FunctionExit = true;
        }
        else{
            for(int i = 0; i < user.size(); i++){
                if(Username == user[i].Username){
                    UsernameFound = true;
                }
            }

            if(UsernameFound){
                cout << "Username is already taken!" << endl;
                FunctionExit = true;
            }
            else{
                while(TempVar != Password){
                    PasswordConfirmed = false;
                    cout << "====================================================\n\n";
                    cout << "      R E G I S T R A T I O N    P R O C E S S\n\n";
                    cout << "====================================================\n";
                    cout << "-- You can enter 'q' to quit registration process\n\n";
                    cout << "ENTER A PASSWORD: ";
                    Password=HashingPassword();

                    TempVar = ValidateAccountCreation(Password);

                    if(TempVar == "0"){
                        cout << "Using space is prohibited." << endl;
                    }
                    else if(TempVar == "1"){
                        cout << "Password must be longer than 8" << endl;
                    }
                    else if(TempVar == "100"){
                        return false;
                        FunctionExit = true;
                    }
                    else{
                        while(!PasswordConfirmed){
                        cout << "====================================================\n\n";
                        cout << "      R E G I S T R A T I O N    P R O C E S S\n\n";
                        cout << "====================================================\n";
                        cout << "-- You can type 'q' to quit registration process\n\n";
                        cout << "CONFIRM PASSWORD: ";
                        PassConf=HashingPassword();

                        TempVar = ValidateAccountCreation(PassConf);

                        if(TempVar == "0"){
                            cout << "Using space is prohibited." << endl;
                        }
                        else if(TempVar == "1"){
                            cout << "Password must be longer than 8" << endl;
                        }
                        else if(TempVar == "100"){
                            return false;
                            FunctionExit = true;
                        }
                        else if(TempVar == Password){
                            WriteToUsersFile(Username, Password);
                            user.push_back(Users(Username, Password));
                            PasswordConfirmed = true;
                            FunctionExit = true;
                        }
                        else{
                            cout << "Passwords do not match." << endl;
                        }
                    }
                }
                }
            }
        }
    }
}

// ######################################## END OF REGISTRATION PROCESS ##############################################
string ValidateAccountCreation(string UserInput);

bool LogInProcess(vector<Users> user, int& IndexNum){
    //Variables
    bool AccountFound;
    bool FunctionExit = false;
    bool PasswordConfirmed = false;
    bool AccountCreated = false;
    string Username, Password, PassConf, TempVar;

    //Program starts here
    while(!FunctionExit){
        cout << "====================================================\n\n";
        cout << "              L O G I N   P R O C E S S\n\n";
        cout << "====================================================\n";
        cout << "-- You can type 'q' to quit login process\n\n";
        cout << "ENTER YOUR USERNAME: ";
        Username=RemovingSpecialCharacters();

        TempVar = ValidateAccountCreation(Username);

        if(TempVar == "0"){
            cout << "Using space is prohibited." << endl;
        }
        else if(TempVar == "1"){
            cout << "Username must be longer than 8" << endl;
        }
        else if(TempVar == "100"){
            return false;
            FunctionExit = true;
        }
        else{
            while(!AccountCreated){
                PasswordConfirmed = false;
                cout << "====================================================\n\n";
                cout << "              L O G I N   P R O C E S S\n\n";
                cout << "====================================================\n";
                cout << "-- You can enter 'q' to quit login process\n\n";
                cout << "ENTER YOUR PASSWORD: ";
                Password=HashingPassword();

                TempVar = ValidateAccountCreation(Password);

                if(TempVar == "0"){
                    cout << "Using space is prohibited." << endl;
                }
                else if(TempVar == "1"){
                    cout << "Password must be longer than 8" << endl;
                }
                else if(TempVar == "100"){
                    return false;
                    FunctionExit = true;
                }
                else{
                    for(int i = 0; i < user.size(); i++){
                        if(Username == user[i].Username && Password == user[i].Password){
                            IndexNum = i;
                            AccountFound = true;
                            break;
                        }
                        else if(Username == user[i].Username && Password != user[i].Password){
                            cout << "Incorrect username or password." << endl;
                            return false;
                        }
                    }
                    if(AccountFound){
                        return true;
                    }
                    else{
                        cout << "Account not found!" << endl;
                        return false;
                    }
                }
            }
        }
    }
}

string ValidateAccountCreation(string UserInput){
    for(char c : UserInput){
        if(c == ' '){
            return "0";
        }
    }

    if(UserInput == "q" || UserInput == "Q"){
        return "100";
    }
    else{
        if(UserInput.size() < 8){
            return "1";
        }
        else{
            return UserInput;
        }
    }
}
// ######################################### END OF LOGIN PROCESS ################################################
