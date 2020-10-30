#include "objuserlogin.h"
LoginOneWid *ObjuserLogin::p_userlogin=NULL;
ObjuserLogin::ObjuserLogin()
{

}
void ObjuserLogin::Init()
{
    p_userlogin=new LoginOneWid();
}
