#include"supervisor.h"

string supervisor::dataformatting(int n, string data)
{
	data.append(n - data.size(), ' ');
	return data;
}
