#include "MembersManageService.h"
#include <stdio.h>
#include <cstring>
#include <iostream>

MembersManageService::MembersManageService()
{
    membersEntity = new MembersEntity();
    membersManagerState = CARD_READER;
}

MembersManageService::~MembersManageService()
{

}

void MembersManageService::updateStateEvent(std::string devName)
{
    switch (membersManagerState)
    {
        case CARD_READER:
            if(devName == "ModeButton")
            {
                membersManagerState = CARD_REGISTER;
                printf("changed to CARD_REGISTER State\n");      
            }
        break;
        case CARD_REGISTER:
            if(devName == "ModeButton")
            {
                membersManagerState = CARD_READER;
                printf("changed to SCAN_NAME State\n");
            }
        break;
        case SCAN_NAME:
            if(devName == "ModeButton")
            {
                membersManagerState = SCAN_PHONENUMBER;
                printf("changed to SCAN_PHONENUMBER State\n");
            }
            // membersEntity->findMemberInfo_name();
        break;
        case SCAN_PHONENUMBER:
            if(devName == "ModeButton")
            {
                membersManagerState = CARD_READER;
                printf("changed to CARD_READER State\n");
            }
            // membersEntity->findMemberInfo_PhoneNumber();
        break;
    }
}


void MembersManageService::checkCardNumber(int *cardNum)
{
    MemberInfo tempMember;
    
    
    switch (membersManagerState)
    {
        case CARD_READER:
            membersEntity->member_reader(cardNum);
        break;
        case CARD_REGISTER:
            membersEntity->member_register(cardNum); 
        break;
    }
}