#include "ouserborrowed.h"

UserBorrowedWid *OuserBorrowed::p_oubored=NULL;
OuserBorrowed::OuserBorrowed()
{

}
void OuserBorrowed::Init()
{
    p_oubored=new UserBorrowedWid();
}
