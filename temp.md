```C++
bookdocking::bookdocking(){
	blank_str = string(LENGTH_ID + LENGTH_VALUE, ' ');
	firstEmpty = 0;//firstEmpty shows the first empty destination to store new datas when new data is inputed
	zero_str = "0000";//zero_str is a string to rewrite the address in fEmpty to change the isEmpty information
}


bool bookdocking::bookadd(int id,string ISBN, string name, string author, string type, string borrowtime, string returntime, string histroy, string onsheelf, string isovertime)
{	
	to_id = to_string(id);
	value = ISBN + name + author + type + borrowtime + returntime + histroy + onsheelf + isovertime;
	to_value = value;
	if (database.insert(id, value)) {
		fEmpty.open("fEmpty.txt", ios::binary); //open the file that indicates the empty place in the datafile fIndex
		if (fEmpty.peek() != EOF) {//check if the fEmpty file is not an empty one. if so, execute the following codes.
			fData.open("fIndex.txt", ios::binary);//open the file fIndex to add items
			fEmpty.seekg(0, ios::beg);//go to the head of the fEmpty
			getline(fEmpty, v_index);//read a line (serves as an address (4 bytes data per line), indicates an empty in fIndex
			while (!atoi(v_index.c_str())) {	//find the first non-zero destination of fEmpty
				firstEmpty = fEmpty.tellg();//store the present destination that the file pointer fEmpty points, in file fEmpty(read)
				getline(fEmpty, v_index);//id not non-zero, read a new data (in a new line)
			}
			fData.seekp(atoi(v_index.c_str()), ios::beg);//move the pointer fData to the empty destination
			//fEmpty.read(c_to_str.c_str(), 4);
			fData.write(to_id.c_str(), LENGTH_ID);//write the id data (within 8(?) bytes) into the fIndex
			fData.write(to_value.c_str(), LENGTH_VALUE);//write the value data (within 80 bytes) into the fIndex, whithout any blanks between id data
			fData.write("\n", sizeof(char));//start a new line in fIndex for another new datas
			fEmpty.seekp(firstEmpty, ios::beg);//go to the empty place indicated in fEmpty
			fEmpty.write(zero_str.c_str(), LENGTH_INDEXADDRESS);//change the address data to 0000(if trans to int, is 0)
			fData.close();
			fEmpty.close();
			return true;
		}
		else {//if the fEmpty is empty, execute the following codes
			fData.open("fEmpty.txt", ios::binary | ios::app);//no free spaces to write on, so start a new line at the rear of the file
			fData.write(to_id.c_str(), LENGTH_ID);//write id data
			fData.write(to_value.c_str(), LENGTH_VALUE);//write value data
			//no changes in fEmpty, so no need to change it.
			fData.close();
			fEmpty.close();
			return true;
			//fEmpty.write();
		}
	}
	else
		return false;

}
bool bookdocking::bookdelete(int id) {
	if (database.remove(id)) {
		fEmpty.open("fEmpty.txt", ios::binary);
		fData.open("fIndex.txt", ios::binary);
		address = search(id);// get the correct destination the fIndex stores that line of data (return the address of it.)
		v_index = to_string(address);//transform the address(int) to string
		fData.seekp(address, ios::beg);//move the pointer of fData to the place of address
		fData.write(blank_str.c_str(), LENGTH_ID + LENGTH_VALUE);//replace the datas with a blank string (88 bytes, a line).
		if (fEmpty.peek() == EOF) {//if fEmpty is empty
			fEmpty.seekp(0, ios::beg);
			fEmpty.write(v_index.c_str(), LENGTH_INDEXADDRESS);//write the position data into the fEmpty
			// not [fEmpty.write(new_str.c_str(), LENGTH_INDEXADDRESS);]!!!!
		}
		else {//fEmpty is not empty
			/*
			fEmpty.seekp(0, ios::beg);
			getline(fEmpty, new_str);
			while (atoi(new_str.c_str()) != address) {
				firstEmpty = fEmpty.tellg();
				getline(fEmpty, new_str);
				}
			fEmpty.seekp(firstEmpty, ios::beg);
			fEmpty.write(zero_str.c_str(),LENGTH_INDEXADDRESS);
			*/
			fEmpty.seekp(0, ios::beg);
			getline(fEmpty, new_str);
			while (!atoi(new_str.c_str()))//while new_str receives "0000" (0 in int), keep traversing for the next line
			{
				firstEmpty = fEmpty.tellg();
				getline(fEmpty, new_str);
			}
		}
		return true;
	}
	else
		return false;
}
```

