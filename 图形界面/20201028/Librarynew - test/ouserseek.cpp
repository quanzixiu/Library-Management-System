#include "ouserseek.h"

UserSeekMw *OuserSeek::p_oseek=NULL;
OuserSeek::OuserSeek()
{

}
void OuserSeek::Init()
{
    p_oseek=new UserSeekMw();
}
