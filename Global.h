#pragma once

#ifdef _WIN32
    #define CLEAR_SCREEN system("cls")
#else
    #define CLEAR_SCREEN system("clear")
#endif

#include <iostream>
#include "clsUser.h"

clsUser currentUser = clsUser::findUser("");
