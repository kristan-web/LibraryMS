#ifndef SYSTEM_H
#define SYSTEM_H
#include "common.h"

void ClearScreen(int delay=1);
string ValidateUserInput(string UserInput);
string RemovingSpecialCharacters();
string ValidateAccountCreation(string UserInput);
string HashingPassword();

#endif SYSTEM_H
