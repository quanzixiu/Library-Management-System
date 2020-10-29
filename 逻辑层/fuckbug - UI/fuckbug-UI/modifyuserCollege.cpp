#include<iostream>
#include<string>
#include"supervisor.h"
#include"userdocking.h"

bool supervisor::modifyuserCollege(int id, string college) {
	userdocking udocking;
	if (!udocking.userexist(id))
		return false;
	else
	{
		college = dataformatting(4, college);
		if (udocking.usermodifycollege(id, college))
			return true;
		else
			return false;
	}
}