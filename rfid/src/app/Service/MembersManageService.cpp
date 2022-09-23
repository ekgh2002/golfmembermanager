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
                membersManagerState = CARD_SCAN_NAME;
                printf("changed to CARD_SCAN_NAME\n");
            }
        break;
        case CARD_SCAN_NAME:
            
            if(devName == "ModeButton")
            {
                membersManagerState = CARD_READER;
                printf("changed to CARD_READER\n");
            }
        break;
    }
}

void MembersManageService::checkCardNumber(int *cardNum)
{
    MemberInfo tempMember;
    tempMember.id = 100001;
    
    switch (membersManagerState)
    {
        static int idcount = 100001;
        case CARD_READER:
            if(membersEntity->findMemberInfo(cardNum))
            {
                printf("Registered Member\n");
                membersEntity->printMemberInfo(cardNum);  
            }
            else
            {
                printf("Not Registered Member\n");
            }
        break;
        case CARD_REGISTER:
            MemberInfo tempMember;
            tempMember.id = idcount;
            printf("이름을 입력하세요 : ");
            scanf("%s", &tempMember.name);
            printf("\n주소를 입력하세요 : ");
            scanf("%s", &tempMember.address);
            printf("\n번호를 입력하세요 : ");
            scanf("%s", &tempMember.phoneNumber);
            // strcpy(tempMember.name, "LEESoonShin");
            // strcpy(tempMember.address, "101dong 123ho");
            // strcpy(tempMember.phoneNumber, "010-1234-5678");
            memcpy(tempMember.cardNum, cardNum, sizeof(tempMember.cardNum));
            membersEntity->addMemberInfo(tempMember);
            printf("member registered\n");
            idcount++;
        break;

        case CARD_SCAN_NAME:
            membersEntity->findMemberInfo();
        break;

    }
}