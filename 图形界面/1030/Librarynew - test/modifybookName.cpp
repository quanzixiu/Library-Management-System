#include<iostream>
#include"supervisor.h"
#include"bookdocking.h"
#include<string>

bool supervisor::modifybookName(int id, string name) {
	bookdocking docking;
	if (!docking.bookexist(id)) return false;
	else {
		name = dataformatting(8, name);
		if (docking.bookmodifyISBN(id, name))
			return true;
		else
			return false;
	}
}