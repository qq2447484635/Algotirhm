// Lab3-2.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int n, m;
char order[100] = { 0 };
int maxstep=0;
int needstep = 0;

int trans(int cur,int step)
{
	if (cur == m)
	{
		needstep = step;
		return 1;
	}
	if (step > maxstep)
	{
		return 0;
	}
	if (trans(cur * 3, step + 1))
	{
		order[step] = 'f';
		return 1;
	}
	else if (trans(cur / 2, step + 1))
	{
		order[step] = 'g';
		return 1;
	}
	return 0;
}

int main()
{
	string path;
	getline(cin, path);
	char file[500] = { 0 };
	int count = 0;

	while (1)
	{
		//read
		sprintf_s(file, "%s\\FUNC%d.IN", path.data(), count++);
		ifstream in(file);
		if (!in.is_open())
			break;

		in >> n >> m;
		for (maxstep = 0; maxstep < 30; maxstep++)
		{
			if (trans(n, 0))
			{
				cout << needstep << endl;
				for (int i = needstep-1; i >= 0; i--)
				{
					cout << order[i];
				}
				cout << endl;
				break;
			}
		}
	}
    return 0;
}

