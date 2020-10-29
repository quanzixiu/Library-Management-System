#include "obookcard.h"

UserCradWid *ObookCard::p_objcard=NULL;
ObookCard::ObookCard()
{

}
void ObookCard::Init()
{
    p_objcard=new UserCradWid();
}
