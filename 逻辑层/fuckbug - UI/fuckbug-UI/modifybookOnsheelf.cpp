#include<iostream>
#include"supervisor.h"
#include"bookdocking.h"
#include<string>

bool supervisor::modifybookOnsheelf(int id, string onsheelf) {
	bookdocking docking;
	if (!docking.bookexist(id)) return false;
	else {
		onsheelf = dataformatting(1, onsheelf);
		if (docking.bookmodifyISBN(id, onsheelf))
			return true;
		else
			return false;
	}
}