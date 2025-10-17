//Files
#ifndef Classes_H
#define Classes_H
#include "common.h"


class Users{
public:
    string Username, Password;


    Users(string Username, string Password);

    //Methods for user
    void DisplayProfile();

};
#endif
