#include "objtwologin.h"

TwoLoginD *Objtwologin::p_objtwo=NULL;
Objtwologin::Objtwologin()
{

}
void Objtwologin::Init()
{
    p_objtwo=new TwoLoginD();
}
