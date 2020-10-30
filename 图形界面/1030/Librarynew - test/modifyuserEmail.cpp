#include<iostream>
#include<string>
#include"supervisor.h"
#include"userdocking.h"


bool supervisor::modifyuserEmail(int id, string email) {
	userdocking udocking;
	if (!udocking.userexist(id))
		return false;
	else
	{
		email = dataformatting(24, email);
		if (udocking.usermodifyemail(id, email))
			return true;
		else
			return false;
	}
}