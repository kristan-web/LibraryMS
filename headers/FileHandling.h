#ifndef FILEHANDLING_H
#define FILEHANDLING_H

//INCLUDES
#include "common.h"
#include "headers.h"

const string userfilepath= "../users/accounts/";

void CreateObjectsFromUsersFile(vector<Users>& user);
void WriteToUsersFile(string Username, string Password);

#endif FILEHANDLING_H
