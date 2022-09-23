#ifndef MEMBERSMANAGESERVICE_H
#define MEMBERSMANAGESERVICE_H

#include <string>
#include "MembersEntity.h"
#include "Memberinfo.h"

enum {CARD_READER, CARD_REGISTER, CARD_SCAN_NAME};

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