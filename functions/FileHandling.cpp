#include "../headers/FileHandling.h"
#include "../headers/headers.h"

void CreateObjectsFromUsersFile(vector<Users>& user){
    //Variables
    string Username, Password;
    int Index = 0;

    ifstream file1(userfilepath + "users.txt");
    if(file1.is_open()){
        while(file1 >> Username >> Password){
            Index++;
            user.push_back(Users(Username, Password));
        }
    }
    else {
        cout << "Error: Could not open users.txt for writing!" << std::endl;
    }
    file1.close();
}

void WriteToUsersFile(string Username, string Password){

    //Program starts here
    ofstream file1(userfilepath + "users.txt", ios::app);

    if(file1.is_open()){
        file1 << Username << " " << Password << endl;
    }
    else {
        cout << "Error: Could not open users.txt for writing!" << std::endl;
        system(pause);
    }
    file1.close();
}
