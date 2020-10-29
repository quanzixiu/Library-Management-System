#include<iostream>
#include<string>
#include"supervisor.h"
#include"userdocking.h"

string supervisor::DisplayUser(int id) {
	string value;
	userdocking udocking;
	if (udocking.userexist(id)) {
		value = udocking.usersearch(id);
		return value;
	}
	else {

		value = "The user does not exist!";
		return value;
	}
}
