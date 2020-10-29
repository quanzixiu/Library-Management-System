#include<iostream>
#include<string>
#include"supervisor.h"
#include"bookdocking.h"

string supervisor::DisplayBook(int id) {
	string value;
	bookdocking docking;
	if (docking.bookexist(id))
		value = docking.booksearch(id);
	else 
		value = "The book dose not exist!";
	return value;
}