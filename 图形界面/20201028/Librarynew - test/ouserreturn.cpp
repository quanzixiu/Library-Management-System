#include "ouserreturn.h"

UserReturnWid *OuserReturn::p_oureturn=NULL;
OuserReturn::OuserReturn()
{

}
void OuserReturn::Init()
{
    p_oureturn=new UserReturnWid();
}
