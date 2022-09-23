#ifndef MEMBERSMANAGESERVICE_H
#define MEMBERSMANAGESERVICE_H

#include <string>
#include "MembersEntity.h"
#include "Memberinfo.h"
#include <vector>
#include <iostream>

enum {CARD_READER, CARD_REGISTER, SCAN_NAME, SCAN_PHONENUMBER};

class MembersManageService
{
private:
    int membersManagerState;
    MembersEntity *membersEntity;

public:
    MembersManageService();
    virtual ~MembersManageService();
    void updateStateEvent(std::string devName);
    void checkCardNumber(int *cardNum);

};

#endif