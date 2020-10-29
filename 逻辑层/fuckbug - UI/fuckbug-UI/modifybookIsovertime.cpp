#include<iostream>
#include"supervisor.h"
#include"bookdocking.h"
#include<string>

bool supervisor::modifybookIsovertime(int id, string isovertime) {
	bookdocking docking;
	if (!docking.bookexist(id)) return false;
	else {
		isovertime = dataformatting(1, isovertime);
		if (docking.bookmodifyISBN(id, isovertime))
			return true;
		else
			return false;
	}
}