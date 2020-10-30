#include "o11userwid.h"
ElevenUserwid *O11userwid::p_obj11=NULL;
O11userwid::O11userwid()
{

}
void O11userwid::Init()
{
    p_obj11=new ElevenUserwid();
}
