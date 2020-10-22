#include "usDatabase.h"

usDatabase::usDatabase()
{
	scale = 5;
	indexFile.open("index.txt", ios::in | ios::out | ios::binary);
	dataFile.open("data.txt", ios::in | ios::out | ios::binary);
	logFile.open("log.txt", ios::trunc);
	if (!indexFile)
	{
		indexFile.close();
		dataFile.close();
		ofstream index("index.txt", ios::binary);
		ofstream data("data.txt", ios::binary);
		int firstEmpty = 8;
		index.write((char *)(&ZERO), sizeof(int));
		index.write(reinterpret_cast<char *>(&firstEmpty), sizeof(int));
		firstEmpty = 4;
		data.write(reinterpret_cast<char *>(&firstEmpty), sizeof(int));
		logFile << "index and data file initialize complete." << endl;
		index.close();
		data.close();
		indexFile.open("index.txt", ios::in | ios::out | ios::binary);
		dataFile.open("data.txt", ios::in | ios::out | ios::binary);
	}
}

void usDatabase::dataFile_find(const int dataAddress, string &value)
{
	char tmp[120];
	dataFile.clear();
	dataFile.seekg(dataAddress, ios::beg);
	dataFile.read((char *)tmp, 120);
	value = tmp;
	logFile << "[dataFile_find] dataAddress:" << dataAddress << " value:" << value << " tmp:" << tmp << endl;
}

int usDatabase::dataFile_add(const string &value)
{
	int dataAddress, next = 0;
	dataFile.clear();
	dataFile.seekg(0, ios::beg);
	dataFile.read(reinterpret_cast<char *>(&dataAddress), sizeof(int));
	dataFile.seekg(dataAddress, ios::beg);
	dataFile.read(reinterpret_cast<char *>(&next), sizeof(int));
	dataFile.clear();
	dataFile.seekp(dataAddress, ios::beg);
	dataFile.write(value.c_str(), value.size() + 1);
	dataFile.seekg(dataAddress, ios::beg);
	if (next == 0)
		next = dataAddress + 120;
	dataFile.seekp(0, ios::beg);
	dataFile.write(reinterpret_cast<char *>(&next), sizeof(int));
	logFile << "[dataFile_add] value:" << value << " dataAddress:" << dataAddress << " next:" << next << endl;
	return dataAddress;
}

void usDatabase::dataFile_delete(const int dataAddress)
{
	int next;
	dataFile.seekg(0);
	dataFile.read(reinterpret_cast<char *>(&next), sizeof(int));
	dataFile.seekp(0);
	dataFile.write((char *)(&dataAddress), sizeof(int));
	dataFile.seekp(dataAddress);
	dataFile.write(reinterpret_cast<char *>(&next), sizeof(int));
}

void usDatabase::dataFile_replace(const int dataAddress, string &value)
{
	dataFile.seekp(dataAddress);
	dataFile.write(value.c_str(), value.size() + 1);
}

int usDatabase::indexFile_find(int key, int *indexAddress, int *pos, int *size, int *dataAddress)
{
	int current, next = 0;
	int begin, end, middle, tmp, last;
	indexFile.clear();
	indexFile.seekg(0, ios::beg);
	indexFile.read(reinterpret_cast<char *>(&next), sizeof(int));
	if (next == 0)
	{
		indexFile.read(reinterpret_cast<char *>(indexAddress), sizeof(int));
		*pos = 0;
		*size = 0;
		return 0;
	}
	while (next > 0)
	{
		indexFile.clear();
		indexFile.seekg(next + 8);
		indexFile.read(reinterpret_cast<char *>(size), sizeof(int));
		begin = 1;
		end = *size;
		do
		{
			middle = (begin + end) / 2;
			indexFile.seekg(next + 12 + 8 * (middle - 1));
			indexFile.read(reinterpret_cast<char *>(&tmp), sizeof(int));
			logFile << "[indexFile_find] middle:" << middle << " tmp:" << tmp << endl;
			if (tmp == key)
				begin = end = middle;
			else if (tmp > key)
				end = middle;
			else
				begin = middle;
		} while ((end - begin) > 1);
		logFile << "[indexFile_find] key:" << key << " address:" << next << " begin:" << begin << " end:" << end << " middle:" << middle << " tmp:" << tmp << " size:" << *size << endl;
		if (end == *size)
		{
			indexFile.seekg(next + 12 + 8 * (*size - 1));
			indexFile.read(reinterpret_cast<char *>(&last), sizeof(int));
			logFile << "[indexFile_find] last:" << last << endl;
			if (key >= last)
				begin = *size;
		}
		current = next;
		indexFile.seekg(next + 12 + 8 * (begin - 1) + 4);
		indexFile.read(reinterpret_cast<char *>(&next), sizeof(int));
	}
	*indexAddress = current;
	if (tmp == key)
	{
		*pos = middle;
		*dataAddress = -next;
		return 1;
	}
	if (key < tmp && begin == 1)
	{
		int first;
		indexFile.seekg(-8, ios::cur);
		indexFile.read(reinterpret_cast<char *>(&first), sizeof(int));
		if (key == first)
		{
			indexFile.read(reinterpret_cast<char *>(dataAddress), sizeof(int));
			*pos = begin;
			*dataAddress = -*dataAddress;
			return 1;
		}
		if (key < first)
		{
			*pos = 0;
			return 0;
		}
	}
	if (begin == *size)
	{
		*indexAddress = current;
		*pos = *size;
		if (last == key)
		{
			*dataAddress = -next;
			return 1;
		}
		return 4;
	}
	*pos = begin;
	return 2;
}

void usDatabase::indexFile_add(const int key, const int dataAddress, const int indexAddress, int pos, int size)
{
	logFile << "[indexFile_add] key:" << key << " dataAddress:" << dataAddress << " indexAddress:" << indexAddress << " pos:" << pos << " size:" << size << endl;
	if (size == 0)
	{
		int nextEmpty = 0;
		indexFile.seekg(indexAddress);
		indexFile.read((char *)&nextEmpty, sizeof(int));
		if (nextEmpty == 0)
			nextEmpty = indexAddress + 12 + 8 * scale + 4;
		indexFile.clear();
		indexFile.seekp(0);
		indexFile.write((char *)&indexAddress, sizeof(int));
		indexFile.write((char *)&nextEmpty, sizeof(int));
		indexFile.seekp(indexAddress);
		indexFile.write((char *)&ZERO, sizeof(int));
	}
	int *index = new int[size - pos];
	int *data = new int[size - pos];
	for (int i = size; i > pos; --i)
	{
		indexFile.seekg(indexAddress + 12 + 8 * (i - 1), ios::beg);
		indexFile.read(reinterpret_cast<char *>(&index[i - pos - 1]), sizeof(int));
		indexFile.read(reinterpret_cast<char *>(&data[i - pos - 1]), sizeof(int));
		indexFile.seekp(indexFile.tellg(), ios::beg);
		indexFile.write(reinterpret_cast<char *>(&index[i - pos - 1]), sizeof(int));
		indexFile.write(reinterpret_cast<char *>(&data[i - pos - 1]), sizeof(int));
	}
	indexFile.seekp(indexAddress + 12 + 8 * pos);
	indexFile.write((char *)(&key), sizeof(int));
	indexFile.write((char *)(&dataAddress), sizeof(int));
	size += 1;
	indexFile.seekp(indexAddress + 8);
	indexFile.write(reinterpret_cast<char *>(&size), sizeof(int));
	if (pos == 0)
	{
		int parent = 0;
		indexFile.seekg(indexAddress);
		indexFile.read(reinterpret_cast<char *>(&parent), sizeof(int));
		while (parent > 0)
		{
			logFile << "[indexFile_add] parent:" << parent << endl;
			indexFile.seekp(parent + 12, ios::beg);
			indexFile.write((char *)&key, sizeof(int));
			indexFile.seekg(parent, ios::beg);
			indexFile.read(reinterpret_cast<char *>(&parent), sizeof(int));
		}
	}
	if (dataAddress > 0)
	{
		int childrenParentPositon = pos + 1;
		indexFile.seekp(dataAddress);
		indexFile.write((char *)(&indexAddress), sizeof(int));
		indexFile.write((char *)(&childrenParentPositon), sizeof(int));
		for (int i = 0; i < size - pos - 1; ++i)
		{
			childrenParentPositon = pos + 1 + i + 1;
			indexFile.seekp(data[i] + 4);
			indexFile.write((char *)&childrenParentPositon, sizeof(int));
		}
	}
	delete[] index;
	delete[] data;
}

void usDatabase::indexFile_addAndOverflow(const int key, const int dataAddress, const int indexAddress, const int pos, const int size)
{
	logFile << "indexFile_addAndOverflow key:" << key << " dataAddress:" << dataAddress << " indexAddress:" << indexAddress << " pos:" << pos << " size:" << size << endl;
	if (size < scale)
		indexFile_add(key, dataAddress, indexAddress, pos, size);
	else
	{
		int middle = scale / 2 + 1;
		int rightSize = scale - middle + 1, leftSize;
		int *index, *data;
		int firstEmpty, nextEmpty = 0;
		int parent = 0, parentPositon = 0, parentSize = 0;
		index = new int[rightSize];
		data = new int[rightSize];
		if (pos < middle)
		{
			indexFile.seekg(indexAddress + 12 + 8 * (middle - 1));
			for (int i = 0; i < rightSize; ++i)
			{
				indexFile.read(reinterpret_cast<char *>(&index[i]), sizeof(int));
				indexFile.read(reinterpret_cast<char *>(&data[i]), sizeof(int));
			}
			leftSize = scale - rightSize;
			indexFile.seekp(indexAddress + 8);
			indexFile.write(reinterpret_cast<char *>(&leftSize), sizeof(int));
			indexFile_add(key, dataAddress, indexAddress, pos, leftSize);
		}
		else
		{
			indexFile.seekg(indexAddress + 12 + 8 * middle, ios::beg);
			for (int i = 0; i < rightSize; ++i)
			{
				if (i == pos - middle)
				{
					index[i] = key;
					data[i] = dataAddress;
				}
				else
				{
					indexFile.read(reinterpret_cast<char *>(&index[i]), sizeof(int));
					indexFile.read(reinterpret_cast<char *>(&data[i]), sizeof(int));
				}
			}
			leftSize = scale + 1 - rightSize;
			indexFile.seekp(indexAddress + 8);
			indexFile.write(reinterpret_cast<char *>(&leftSize), sizeof(int));
		}
		for (int i = 0; i < rightSize; ++i)
		{
			logFile << "[indexFile_addAndOverflow] index[" << i << "]:" << index[i] << endl;
			logFile << "[indexFile_addAndOverflow] data[" << i << "]:" << data[i] << endl;
		}
		indexFile.clear();
		indexFile.seekg(4, ios::beg);
		indexFile.read(reinterpret_cast<char *>(&firstEmpty), sizeof(int));
		indexFile.seekg(firstEmpty);
		indexFile.read(reinterpret_cast<char *>(&nextEmpty), sizeof(int));
		if (nextEmpty == 0)
			nextEmpty = firstEmpty + 12 + 8 * scale + 4;
		indexFile.clear();
		indexFile.seekp(firstEmpty + 8);
		indexFile.write(reinterpret_cast<char *>(&rightSize), sizeof(int));
		for (int i = 0; i < rightSize; ++i)
		{
			indexFile.write(reinterpret_cast<char *>(&index[i]), sizeof(int));
			indexFile.write(reinterpret_cast<char *>(&data[i]), sizeof(int));
		}
		indexFile.seekp(4);
		indexFile.write(reinterpret_cast<char *>(&nextEmpty), sizeof(int));
		logFile << "[indexFile_addAndOverflow] new node firstEmpty:" << firstEmpty << " nextEmpty:" << nextEmpty << endl;
		if (dataAddress > 0)
		{
			for (int i = 1; i <= rightSize; ++i)
			{
				indexFile.seekp(data[i - 1]);
				indexFile.write(reinterpret_cast<char *>(&firstEmpty), sizeof(int));
				indexFile.write(reinterpret_cast<char *>(&i), sizeof(int));
			}
		}
		else
		{
			int nextLeaf = 0;
			indexFile.seekg(indexAddress + 12 + 8 * scale);
			indexFile.read(reinterpret_cast<char *>(&nextLeaf), sizeof(int));
			indexFile.seekp(indexAddress + 12 + 8 * scale);
			indexFile.write(reinterpret_cast<char *>(&firstEmpty), sizeof(int));
			indexFile.seekp(firstEmpty + 12 + 8 * scale);
			indexFile.write(reinterpret_cast<char *>(&nextLeaf), sizeof(int));
			logFile << "[indexFile_addAndOverflow] currentLeaf:" << firstEmpty << " nextLeaf:" << nextLeaf << endl;
		}
		indexFile.seekg(indexAddress);
		indexFile.read(reinterpret_cast<char *>(&parent), sizeof(int));
		if (parent == 0)
		{
			int left;
			int leftChild = indexAddress;
			int right = index[0];
			int rightChild = firstEmpty;
			int rootSize = 2;
			nextEmpty = 0;
			indexFile.clear();
			indexFile.seekg(indexAddress + 12);
			indexFile.read(reinterpret_cast<char *>(&left), sizeof(int));
			indexFile.seekg(4);
			indexFile.read(reinterpret_cast<char *>(&firstEmpty), sizeof(int));
			indexFile.seekg(firstEmpty);
			indexFile.read(reinterpret_cast<char *>(&nextEmpty), sizeof(int));
			if (nextEmpty == 0)
				nextEmpty = firstEmpty + 12 + 8 * scale + 4;
			indexFile.clear();
			indexFile.seekp(firstEmpty);
			indexFile.write(reinterpret_cast<char *>(&parent), sizeof(int));
			indexFile.write(reinterpret_cast<char *>(&parentPositon), sizeof(int));
			indexFile.write(reinterpret_cast<char *>(&rootSize), sizeof(int));
			indexFile.write(reinterpret_cast<char *>(&left), sizeof(int));
			indexFile.write(reinterpret_cast<char *>(&leftChild), sizeof(int));
			indexFile.write(reinterpret_cast<char *>(&right), sizeof(int));
			indexFile.write(reinterpret_cast<char *>(&rightChild), sizeof(int));
			indexFile.clear();
			indexFile.seekp(0);
			indexFile.write(reinterpret_cast<char *>(&firstEmpty), sizeof(int));
			indexFile.write(reinterpret_cast<char *>(&nextEmpty), sizeof(int));
			parentPositon = 1;
			indexFile.seekp(leftChild);
			indexFile.write(reinterpret_cast<char *>(&firstEmpty), sizeof(int));
			indexFile.write(reinterpret_cast<char *>(&parentPositon), sizeof(int));
			parentPositon = 2;
			indexFile.seekp(rightChild);
			indexFile.write(reinterpret_cast<char *>(&firstEmpty), sizeof(int));
			indexFile.write(reinterpret_cast<char *>(&parentPositon), sizeof(int));
			logFile << "[indexFile_addAndOverflow] newRoot:" << firstEmpty << " left:" << left << " leftChild:" << leftChild << " right:" << right << " rightChild:" << rightChild << " nextEmpty:" << nextEmpty << endl;
		}
		else
		{
			indexFile.read(reinterpret_cast<char *>(&parentPositon), sizeof(int));
			indexFile.seekg(parent + 8);
			indexFile.read(reinterpret_cast<char *>(&parentSize), sizeof(int));
			indexFile_addAndOverflow(index[0], firstEmpty, parent, parentPositon, parentSize);
		}
		delete[] index;
		delete[] data;
	}
}

bool usDatabase::indexFile_delete(const int indexAddress, const int pos, int size)
{
	logFile << "[indexFile_delete] indexAddress:" << indexAddress << " pos:" << pos << " size:" << size << endl;
	int *index = new int[size - pos];
	int *data = new int[size - pos];
	for (int i = 0; i < size - pos; ++i)
	{
		indexFile.seekg(indexAddress + 12 + 8 * (pos + i));
		indexFile.read(reinterpret_cast<char *>(&index[i]), sizeof(int));
		indexFile.read(reinterpret_cast<char *>(&data[i]), sizeof(int));
		logFile << "[indexFile_delete] curKey:" << index[i] << " curPoint:" << data[i] << endl;
		indexFile.seekp((int)indexFile.tellg() - 16);
		indexFile.write(reinterpret_cast<char *>(&index[i]), sizeof(int));
		indexFile.write(reinterpret_cast<char *>(&data[i]), sizeof(int));
	}
	size = size - 1;
	indexFile.seekp(indexAddress + 8);
	indexFile.write(reinterpret_cast<char *>(&size), sizeof(int));
	if (data[0] > 0)
	{
		int childrenParentPositon;
		for (int i = 0; i < size - pos + 1; ++i)
		{
			childrenParentPositon = pos + i;
			indexFile.seekp(data[i] + 4);
			indexFile.write((char *)&childrenParentPositon, sizeof(int));
		}
	}
	if (pos == 1)
	{
		if (size == 0)
		{
			int firstEmpty;
			indexFile.seekg(4);
			indexFile.read(reinterpret_cast<char *>(&firstEmpty), sizeof(int));
			indexFile.seekp(-8, ios::cur);
			indexFile.write((char *)&ZERO, sizeof(int));
			indexFile.write((char *)&indexAddress, sizeof(int));
			indexFile.seekp(indexAddress);
			indexFile.write(reinterpret_cast<char *>(&firstEmpty), sizeof(int));
			return false;
		}
		else
		{
			int min;
			int parent = 0, parentPosition;
			int selfPosition = pos;
			indexFile.seekg(indexAddress + 12);
			indexFile.read(reinterpret_cast<char *>(&min), sizeof(int));
			logFile << "[indexFile_delete] min:" << min << endl;
			indexFile.seekg(indexAddress);
			indexFile.read(reinterpret_cast<char *>(&parent), sizeof(int));
			while (parent > 0 && selfPosition == 1)
			{
				indexFile.read(reinterpret_cast<char *>(&parentPosition), sizeof(int));
				logFile << "[indexFile_delete] parent:" << parent << " parentPositon:" << parentPosition << endl;
				indexFile.seekp(parent + 12 + 8 * (parentPosition - 1));
				indexFile.write(reinterpret_cast<char *>(&min), sizeof(int));
				indexFile.seekg(parent);
				indexFile.read(reinterpret_cast<char *>(&parent), sizeof(int));
				selfPosition = parentPosition;
			}
		}
	}
	return true;
}

void usDatabase::indexFile_borrowLeft(const int indexAddress, int size, const int left, int leftSize, int parent, int parentPosition)
{
	logFile << "[indexFile_borrowLeft] indexAddress:" << indexAddress << " size:" << size << " left:" << left << " leftSize:" << leftSize << " parent:" << parent << " parentPosition:" << parentPosition << endl;
	int borrowLeftKey, borrowLeftValue;
	int *index = new int[size];
	int *data = new int[size];
	indexFile.seekg(left + 12 + 8 * (leftSize - 1));
	indexFile.read((char *)&borrowLeftKey, sizeof(int));
	indexFile.read((char *)&borrowLeftValue, sizeof(int));
	logFile << "[indexFile_borrowLeft] borrowKey:" << borrowLeftKey << " borrowValue:" << borrowLeftValue << endl;
	leftSize -= 1;
	indexFile.seekp(left + 8);
	indexFile.write((char *)&leftSize, sizeof(int));
	indexFile.seekg(indexAddress + 12);
	for (int i = 0; i < size; ++i)
	{
		indexFile.read((char *)&index[i], sizeof(int));
		indexFile.read((char *)&data[i], sizeof(int));
	}
	for (int i = 0; i < size; ++i)
		logFile << "[indexFile_borrowLeft] index[" << i << "]:" << index[i] << " data[" << i << "]:" << data[i] << endl;
	size += 1;
	indexFile.seekp(indexAddress + 8);
	indexFile.write((char *)&size, sizeof(int));
	indexFile.write((char *)&borrowLeftKey, sizeof(int));
	indexFile.write((char *)&borrowLeftValue, sizeof(int));
	for (int i = 0; i < size; ++i)
	{
		indexFile.write((char *)&index[i], sizeof(int));
		indexFile.write((char *)&data[i], sizeof(int));
	}
	if (borrowLeftValue > 0)
	{
		int childrenParentPositon = 1;
		indexFile.seekp(borrowLeftValue);
		indexFile.write((char *)&indexAddress, sizeof(int));
		indexFile.write((char *)&childrenParentPositon, sizeof(int));
		for (int i = 0; i < size - 1; i++)
		{
			childrenParentPositon = i + 2;
			indexFile.seekp(data[i] + 4);
			indexFile.write((char *)&childrenParentPositon, sizeof(int));
		}
	}
	int selfPosition = 1;
	while (parent > 0 && selfPosition == 1)
	{
		logFile << "[indexFile_borrowLeft] parent:" << parent << " parentPosition:" << parentPosition << " selfPositon:" << selfPosition << endl;
		indexFile.seekp(parent + 12 + 8 * (parentPosition - 1));
		indexFile.write((char *)&borrowLeftKey, sizeof(int));
		selfPosition = parentPosition;
		indexFile.seekg(parent);
		indexFile.read((char *)&parent, sizeof(int));
		indexFile.read((char *)&parentPosition, sizeof(int));
	}
	delete[] index;
	delete[] data;
}

void usDatabase::indexFile_borrowRight(const int indexAddress, int size, const int right, int rightSize, int parent, int parentPosition)
{
	logFile << "[indexFile_borrowRight] indexAddress:" << indexAddress << " size:" << size << " right:" << right << " rightSize:" << rightSize << " parent:" << parent << " parentPosition:" << parentPosition << endl;
	int borrowRightKey, borrowRightValue;
	int *index = new int[rightSize - 1];
	int *data = new int[rightSize - 1];
	indexFile.seekg(right + 12);
	indexFile.read((char *)&borrowRightKey, sizeof(int));
	indexFile.read((char *)&borrowRightValue, sizeof(int));
	logFile << "[indexFile_borrowRight] borrowKey:" << borrowRightKey << " borrowValue:" << borrowRightValue << endl;
	for (int i = 0; i < rightSize - 1; ++i)
	{
		indexFile.read((char *)&index[i], sizeof(int));
		indexFile.read((char *)&data[i], sizeof(int));
	}
	for (int i = 0; i < rightSize - 1; ++i)
		logFile << "[indexFile_borrowRight] index[" << i << "]:" << index[i] << " data[" << i << "]:" << data[i] << endl;
	size += 1;
	indexFile.seekp(indexAddress + 8);
	indexFile.write((char *)&size, sizeof(int));
	indexFile.seekp(8 * (size - 1), ios::cur);
	indexFile.write((char *)&borrowRightKey, sizeof(int));
	indexFile.write((char *)&borrowRightValue, sizeof(int));
	rightSize -= 1;
	indexFile.seekp(right + 8);
	indexFile.write((char *)&rightSize, sizeof(int));
	for (int i = 0; i < rightSize; ++i)
	{
		indexFile.write((char *)&index[i], sizeof(int));
		indexFile.write((char *)&data[i], sizeof(int));
	}
	if (borrowRightValue > 0)
	{
		int childrenParentPositon = size;
		indexFile.seekp(borrowRightValue);
		indexFile.write((char *)&indexAddress, sizeof(int));
		indexFile.write((char *)&childrenParentPositon, sizeof(int));
		for (int i = 0; i < rightSize; ++i)
		{
			childrenParentPositon = i + 1;
			indexFile.seekp(data[0] + 4);
			indexFile.write((char *)&childrenParentPositon, sizeof(int));
		}
	}
	int selfPositon = 1;
	parentPosition += 1;
	while (parent > 0 && selfPositon == 1)
	{
		logFile << "[indexFile_borrowRight] parent:" << parent << " parentPosition:" << parentPosition << endl;
		indexFile.seekp(parent + 12 + 8 * (parentPosition - 1));
		indexFile.write((char *)&index[0], sizeof(int));
		selfPositon = parentPosition;
		indexFile.seekg(parent);
		indexFile.read((char *)&parent, sizeof(int));
		indexFile.read((char *)&parentPosition, sizeof(int));
	}
	delete[] index;
	delete[] data;
}

void usDatabase::indexFile_mergeLeft(const int indexAddress, const int size, const int left, int leftSize)
{
	logFile << "[indexFile_mergeLeft] indexAddress:" << indexAddress << " size:" << size << " left:" << left << " leftSize:" << leftSize << endl;
	int *index = new int[size];
	int *data = new int[size];
	int firstEmpty;
	indexFile.seekg(indexAddress + 12);
	for (int i = 0; i < size; ++i)
	{
		indexFile.read((char *)&index[i], sizeof(int));
		indexFile.read((char *)&data[i], sizeof(int));
	}
	indexFile.seekg(4);
	indexFile.read((char *)&firstEmpty, sizeof(int));
	indexFile.seekp(4);
	indexFile.write((char *)&indexAddress, sizeof(int));
	indexFile.seekp(indexAddress);
	indexFile.write((char *)&firstEmpty, sizeof(int));
	indexFile.seekp(left + 12 + 8 * leftSize);
	for (int i = 0; i < size; ++i)
	{
		indexFile.write((char *)&index[i], sizeof(int));
		indexFile.write((char *)&data[i], sizeof(int));
	}
	if (data[0] > 0)
	{
		int childrenParentPositon;
		for (int i = 0; i < size; ++i)
		{
			childrenParentPositon = leftSize + i + 1;
			indexFile.seekp(data[i]);
			indexFile.write((char *)&left, sizeof(int));
			indexFile.write((char *)&childrenParentPositon, sizeof(int));
		}
	}
	leftSize += size;
	indexFile.seekp(left + 8);
	indexFile.write((char *)&leftSize, sizeof(int));
	delete[] index;
	delete[] data;
}

void usDatabase::indexFile_mergeRight(const int indexAddress, int size, const int right, const int rightSize)
{
	logFile << "[indexFile_mergeRight] indexAddress:" << indexAddress << " size:" << size << " right:" << right << " rightSize:" << rightSize << endl;
	int firstEmpty;
	int *index = new int[rightSize];
	int *data = new int[rightSize];
	indexFile.seekg(right + 12);
	for (int i = 0; i < rightSize; ++i)
	{
		indexFile.read((char *)&index[i], sizeof(int));
		indexFile.read((char *)&data[i], sizeof(int));
	}
	indexFile.seekg(4);
	indexFile.read((char *)&firstEmpty, sizeof(int));
	indexFile.seekp(4);
	indexFile.write((char *)&right, sizeof(int));
	indexFile.seekp(right);
	indexFile.write((char *)&firstEmpty, sizeof(int));
	indexFile.seekp(indexAddress + 12 + 8 * size);
	for (int i = 0; i < rightSize; ++i)
	{
		indexFile.write((char *)&index[i], sizeof(int));
		indexFile.write((char *)&data[i], sizeof(int));
	}
	if (data[0] > 0)
	{
		int childrenParentPositon;
		for (int i = 0; i < rightSize; ++i)
		{
			childrenParentPositon = size + i + 1;
			indexFile.seekp(data[i]);
			indexFile.write((char *)&indexAddress, sizeof(int));
			indexFile.write((char *)&childrenParentPositon, sizeof(int));
		}
	}
	size += rightSize;
	indexFile.seekp(indexAddress + 8);
	indexFile.write((char *)&size, sizeof(int));
	delete[] index;
	delete[] data;
}

void usDatabase::indexFile_deleteAndUnderflow(const int indexAddress, const int pos, int size)
{
	logFile << "[indexFile_deleteAndUnderflow] indexAddress:" << indexAddress << " pos:" << pos << " size:" << size << endl;
	bool result = indexFile_delete(indexAddress, pos, size);
	if (result)
	{
		size -= 1;
		if (size < (scale + 1) / 2)
		{
			int parent = 0, parentPosition, parentSize;
			indexFile.seekg(indexAddress);
			indexFile.read((char *)&parent, sizeof(int));
			if (parent == 0)//当前节点为根节点
			{
				if (size == 1)
				{
					int dataAddress;
					indexFile.seekg(indexAddress + 12 + 4);
					indexFile.read((char *)&dataAddress, sizeof(int));
					if (dataAddress > 0)//不是叶节点
					{
						//下溢一层
						int firstEmpty;
						indexFile.seekg(4);
						indexFile.read((char *)&firstEmpty, sizeof(int));
						indexFile.seekp(indexAddress);
						indexFile.write((char *)&firstEmpty, sizeof(int));
						indexFile.seekp(0);
						indexFile.write((char *)&dataAddress, sizeof(int));
						indexFile.write((char *)&indexAddress, sizeof(int));
						indexFile.seekp(dataAddress);
						indexFile.write((char *)&ZERO, sizeof(int));
						logFile << "[indexFile_deleteAndUnderflow] old root:" << indexAddress << " new root:" << dataAddress << endl;
					}
				}
			}
			else
			{
				int left, leftSize;
				int right, rightSize;
				indexFile.read((char *)&parentPosition, sizeof(int));
				indexFile.seekg(parent + 8);
				indexFile.read((char *)&parentSize, sizeof(int));
				logFile << "[indexFile_deleteAndUnderflow] parent:" << parent << " parentPosition:" << parentPosition << " parentSize:" << parentSize << endl;
				if (parentPosition == parentSize)
				{
					indexFile.seekg(parent + 12 + 8 * (parentSize - 2) + 4);
					indexFile.read((char *)&left, sizeof(int));
					indexFile.seekg(left + 8);
					indexFile.read((char *)&leftSize, sizeof(int));
					if (leftSize > (scale + 1) / 2)
						indexFile_borrowLeft(indexAddress, size, left, leftSize, parent, parentPosition);
					else
					{
						indexFile_mergeLeft(indexAddress, size, left, leftSize);
						indexFile_deleteAndUnderflow(parent, parentPosition, parentSize);
					}
				}
				else
				{
					indexFile.seekg(parent + 12 + 8 * parentPosition + 4);
					indexFile.read((char *)&right, sizeof(int));
					indexFile.seekg(right + 8);
					indexFile.read((char *)&rightSize, sizeof(int));
					if (rightSize > (scale + 1) / 2)
						indexFile_borrowRight(indexAddress, size, right, rightSize, parent, parentPosition);
					else
					{
						if (parentPosition != 1)
						{
							indexFile.seekg(parent + 12 + 8 * (parentPosition - 1) + 4);
							indexFile.read((char *)&left, sizeof(int));
							indexFile.seekg(left + 8);
							indexFile.read((char *)&leftSize, sizeof(int));
							if (leftSize > (scale + 1) / 2)
								indexFile_borrowLeft(indexAddress, size, left, leftSize, parent, parentPosition);
							else
							{
								indexFile_mergeRight(indexAddress, size, right, rightSize);
								indexFile_deleteAndUnderflow(parent, parentPosition + 1, parentSize);
							}
						}
						else
						{
							indexFile_mergeRight(indexAddress, size, right, rightSize);
							indexFile_deleteAndUnderflow(parent, parentPosition + 1, parentSize);
						}
					}
				}
			}
		}
	}
}

bool usDatabase::file_update(const int key, string &value)
{
	logFile << endl << "[file_update] key:" << key << " value:" << value << endl;
	int indexAddress, pos, size, dataAddress;
	int result = indexFile_find(key, &indexAddress, &pos, &size, &dataAddress);
	if (result != 1)
		return false;
	dataFile_replace(dataAddress, value);
	return true;
}

bool usDatabase::select(const int key, string & value)
{
	logFile << endl << "SELECT key:" << key << endl;
	if (cache.select(key, value))
		return true;
	int indexAddress, pos, size, dataAddress;
	int result = indexFile_find(key, &indexAddress, &pos, &size, &dataAddress);
	logFile << "SELECT find result:" << result << endl;
	if (result != 1)
		return false;
	dataFile_find(dataAddress, value);
	logFile << "SELECT key:" << key << " indexAddress:" << indexAddress << " pos:" << pos << " dataAddress:" << dataAddress << " value:" << value << endl;
	int oldKey;
	string oldValue;
	result = cache.insert(key, value, &oldKey, &oldValue);
	if (result == 2)
		file_update(oldKey, oldValue);
	return true;
}

bool usDatabase::insert(const int key, const string &value)
{
	logFile << endl << "INSERT key:" << key << " value:" << value << endl;
	string fvalue;
	if (cache.select(key, fvalue))
		return false;
	int indexAddress, pos, size, dataAddress;
	int result = indexFile_find(key, &indexAddress, &pos, &size, &dataAddress);
	logFile << "INSERT find result:" << result << endl;
	if (result == 1)
		return false;
	dataAddress = -dataFile_add(value);
	logFile << "INSERT key:" << key << " dataAddress:" << dataAddress << " indexAddress:" << indexAddress << " pos:" << pos << " size:" << size << endl;
	indexFile_addAndOverflow(key, dataAddress, indexAddress, pos, size);
	int oldKey;
	string oldValue;
	result = cache.insert(key, value, &oldKey, &oldValue);
	if (result == 2)
		file_update(oldKey, oldValue);
	return true;
}

bool usDatabase::remove(const int key)
{
	logFile << endl << "REMOVE key:" << key << endl;
	cache.remove(key);
	int indexAddress, pos, size, dataAddress;
	int result = indexFile_find(key, &indexAddress, &pos, &size, &dataAddress);
	if (result != 1)
		return false;
	dataFile_delete(dataAddress);
	indexFile_deleteAndUnderflow(indexAddress, pos, size);
	return true;
}

bool usDatabase::update(const int key, string &value)
{
	logFile << endl << "UPDATE key:" << key << " value:" << value << endl;
	int result;
	result = cache.update(key, value);
	if (!result)
	{
		result = file_update(key, value);
		if (!result)
			return false;
		int oldKey;
		string oldValue;
		result = cache.insert(key, value, &oldKey, &oldValue);
		if (result == 2)
			file_update(oldKey, oldValue);
	}
	return true;
}

usDatabase::~usDatabase()
{
	vector<int> key;
	vector<string> value;
	cache.save(&key, &value);
	for (int i = 0; i < key.size(); ++i)
		file_update(key[i], value[i]);
	indexFile.close();
	dataFile.close();
	logFile.close();
}