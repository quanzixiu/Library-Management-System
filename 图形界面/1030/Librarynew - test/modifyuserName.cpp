#include<iostream>
#include<string>
#include"supervisor.h"
#include"userdocking.h"

bool supervisor::modifyuserName(int id, string name) {
	userdocking udocking;
	if (!udocking.userexist(id))
		return false;
	else
	{
		name = dataformatting(8, name);
		if (udocking.usermodifyname(id, name))
			return true;
		else
			return false;
	}
}