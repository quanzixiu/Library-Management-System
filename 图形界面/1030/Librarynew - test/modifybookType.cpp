#include<iostream>
#include"supervisor.h"
#include"bookdocking.h"
#include<string>

bool supervisor::modifybookType(int id, string type) {
	bookdocking docking;
	if (!docking.bookexist(id)) return false;
	else {
		type = dataformatting(4, type);
		if (docking.bookmodifyISBN(id, type))
			return true;
		else
			return false;
	}
}