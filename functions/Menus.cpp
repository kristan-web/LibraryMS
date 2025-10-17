#include "../headers/Menus.h"
#include "../headers/headers.h"
void WelcomePageMenu(){
    cout<<"================================\n";
    cout<<"     Welcome to The Stack!!\n";
    cout<<"================================\n";
    cout<<"1. Register\n";
    cout<<"2. Login\n";
    cout<<"Choice: ";
}

void TermsAndCondition(){
    cout << "==========================================================\n\n";
    cout << "| Welcome to The Stack! Please read these terms carefully: |\n\n";
    cout << "==========================================================\n\n";

    cout << "1. ACCEPTANCE OF TERMS\n";
    cout << "   By creating an account, you agree to be bound by\n";
    cout << "   these Terms of Service.\n\n";

    cout << "2. OFFLINE APPLICATION\n";
    cout << "   Quizify operates offline. All data including:\n";
    cout << "   - User credentials\n   - Quiz progress\n   - Points balance\n";
    cout << "   are stored locally on your device.\n\n";

    cout << "3. USER RESPONSIBILITIES\n";
    cout << "   - Maintain confidentiality of your account\n";
    cout << "   - Not attempt to reverse-engineer the application\n";
    cout << "   - Use productivity features responsibly\n\n";

    cout << "4. DATA & PRIVACY\n";
    cout << "   - We don't collect personal information\n";
    cout << "   - Local data is not encrypted by default\n";
    cout << "   - You're responsible for device security\n\n";

    cout << "5. GAMIFICATION ELEMENTS\n";
    cout << "   - Points have no real-world value\n";
    cout << "   - Features may change without notice\n";
    cout << "   - No in-app purchases required\n\n";

    cout << "6. LIABILITY\n";
    cout << "   - We're not responsible for:\n";
    cout << "     * Data loss\n     * Productivity outcomes\n";
    cout << "     * Device-specific issues\n\n";
    system("pause");
}

string AccountCreationMenu(){
    string UserChoice;
    string TempVar;
    cout << "====================================================\n\n";
    cout << "          A C C O U N T   C R E A T I O N\n\n";
    cout << "====================================================\n";
    cout << " [ 1 ] L O G I N\n";
    cout << " [ 2 ] R E G I S T E R\n";
    cout << " [ 3 ] E X I T\n";
    cout << "====================================================\n";
    cout << "ENTER YOUR CHOICE [1 - 3]: ";
    getline(cin, UserChoice);
    TempVar = ValidateUserInput(UserChoice);

    if(TempVar == "1"){
        return "1";
    }
    else if(TempVar == "2"){
        return "2";
    }
    else if(TempVar == "3"){
        while(true){
            cout << "====================================================\n\n";
            cout << "          ARE YOU SURE YOU WANT TO EXIT?\n\n";
            cout << "====================================================\n";
            cout << " [ 1 ] Y E S\n";
            cout << " [ 2 ] N O\n";
            cout << "====================================================\n";
            cout << "ENTER YOUR CHOICE [1 - 2]: ";
            getline(cin, UserChoice);

            TempVar = ValidateUserInput(UserChoice);

            if(TempVar == "1"){
                return "3";
            }
            else if(TempVar == "2"){
                break;
            }
            else{
                cout << "Invalid input. Please only choose from [1 - 2]." << endl;
            }
        }
    }
    else{
        return "0";
    }
}
