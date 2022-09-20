#ifndef MEMBERINFO_H_
#define MEMBERINFO_H_
#include <iostream>

struct MemberInfo
{
    int id;
    char name[10];
    char address[40];
    char phoneNumber[15];
    uint8_t cardNum[5];
};

#endif