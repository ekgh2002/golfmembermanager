#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Monitor.h"
#include "DeviceData.h"
#include "MembersManageService.h"

class Controller
{
private:
    MembersManageService *membersManageService;

public:
    Controller();
    virtual ~Controller();
    void updateEvent(DeviceData data);

};

#endif