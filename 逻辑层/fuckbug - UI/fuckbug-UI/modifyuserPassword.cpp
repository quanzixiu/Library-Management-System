#include<iostream>
#include<string>
#include"supervisor.h"
#include"userdocking.h"

bool supervisor::modifyuserPassword(int id, string password) {
	userdocking udocking;
	if (!udocking.userexist(id))
		return false;
	else
	{
		password = dataformatting(16, password);
		if (udocking.usermodifypassword(id, password))
			return true;
		else
			return false;
	}
}