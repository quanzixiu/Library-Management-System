#include<iostream>
#include<string>
#include"supervisor.h"
#include"userdocking.h"


bool supervisor::modifyuserMajor(int id, string major) {
	userdocking udocking;
	if (!udocking.userexist(id))
		return false;
	else
	{
		major = dataformatting(4, major);
		if (udocking.usermodifymajor(id, major))
			return true;
		else
			return false;
	}
}