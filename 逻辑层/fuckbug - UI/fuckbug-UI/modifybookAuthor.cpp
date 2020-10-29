#include<iostream>
#include"supervisor.h"
#include"bookdocking.h"
#include<string>

bool supervisor::modifybookAuthor(int id, string author) {
	bookdocking docking;
	if (!docking.bookexist(id)) return false;
	else {
		author = dataformatting(4, author);
		if (docking.bookmodifyISBN(id, author))
			return true;
		else
			return false;
	}
}