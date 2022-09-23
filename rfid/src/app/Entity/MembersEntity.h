#ifndef MEMBERSENTITY_H
#define MEMBERSENTITY_H

#include <vector>
#include <iostream>
#include <string>
#include "Memberinfo.h"


class MembersEntity
{
private:
    std::vector<MemberInfo> vecMembersList;
    MemberInfo memberInfo;
    FILE *fpDBData;
    
    
    

public:
    MembersEntity();
    virtual ~MembersEntity();
    void loadMembersInfo();
    void addMemberInfo(MemberInfo member);
    bool delMemberInfo(int *cardNum);
    
    // void printMemberInfo();
    // void addMemberInfo(MemberInfo member);
    // void delMemberInfo(MemberInfo member);
    // void makeDBMembersInfo();
    void printMemberInfo(int index); 
    void printMemberInfo(std::string name);
    void printMemberInfo(int *cardNum);
    bool findMemberInfo(int *cardNum);
    bool findMemberInfo(std::string name);
    void memoryToDB();
    void member_reader(int*cardNum);
    void member_register(int *cardNum);
    void findMemberInfo_name();
    void findMemberInfo_PhoneNumber();
    int idcount;



};

#endif