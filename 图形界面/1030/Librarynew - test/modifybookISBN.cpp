#include<iostream>
#include"supervisor.h"
#include"bookdocking.h"
#include<string>

bool supervisor::modifybookISBN(int id,string ISBN) {
	bookdocking docking;
	if (!docking.bookexist(id)) return false;
	else {
		ISBN = dataformatting(6, ISBN);
		if (docking.bookmodifyISBN(id, ISBN))
			return true;
		else
			return false;
	}
}