#ifndef OBJUSERLOGIN_H
#define OBJUSERLOGIN_H

#include "loginonewid.h"
#include <QString>
#include <string>
class ObjuserLogin
{
public:
    ObjuserLogin();
static LoginOneWid *p_userlogin;
static void Init();
};

#endif // OBJUSERLOGIN_H
