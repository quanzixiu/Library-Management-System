#include "objone.h"

OneWelcomeW *Objone::p_objone=NULL;
Objone::Objone()
{

}
void Objone::Init()
{
    p_objone=new OneWelcomeW();
}
