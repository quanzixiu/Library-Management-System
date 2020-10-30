#include<iostream>
#include"supervisor.h"
#include<string>

bool supervisor::login(int id, string password) {
	int ID=123;
	string Password;
	Password = "admin";
	if (id == ID)
		if (Password == password)
			return true;
		else
			return false;
	else return false;
}