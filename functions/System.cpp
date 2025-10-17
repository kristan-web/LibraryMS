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

string RemovingSpecialCharacters(){
    string password;
    char ch;

    // Read characters until Enter key is pressed
    while ((ch = _getch()) != 13) { // 13 is the ASCII value for Enter key
        // Handle backspace (ASCII 8
        if (ch == 8) {
            if (!password.empty()) {
                password.pop_back(); // Remove the last character from password
                std::cout << "\b \b"; // Move cursor back, print space, move cursor back again
            }
        }
        // Handle printable characters
        else if (ch >= 32 && ch <= 126) { // ASCII range for printable characters
            password += ch;
            std::cout <<ch; // Print asterisk instead of the actual character
        }
    }
    return password;
}

string HashingPassword(){
    string password;
    char ch;

    // Read characters until Enter key is pressed
    while ((ch = _getch()) != 13) { // 13 is the ASCII value for Enter key
        // Handle backspace (ASCII 8
        if (ch == 8) {
            if (!password.empty()) {
                password.pop_back(); // Remove the last character from password
                std::cout << "\b \b"; // Move cursor back, print space, move cursor back again
            }
        }
        // Handle printable characters
        else if (ch >= 32 && ch <= 126) { // ASCII range for printable characters
            password += ch;
            std::cout << '*'; // Print asterisk instead of the actual character
        }
    }
    return password;
}
