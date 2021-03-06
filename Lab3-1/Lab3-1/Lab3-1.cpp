
#include "stdafx.h"
#include <iostream>
#include <stack>
#include <fstream>
#include <string>
#include <cstdio>
using namespace std;
int n, m, maxstep;
int index[1000] = { 0 };
int num[1000] = { 0 };
stack<int> resnum;
stack<char > resop;
int select_op(int num, int val1, int val2)
{
	switch (num)
	{
	case 0:return val1 + val2;
	case 1:return val1 - val2;
	case 2:return val1 * val2;
	case 3:return val1 / val2;
	}
}

char get_op(int num)
{
	switch (num)
	{
	case 0:return '+';
	case 1:return '-';
	case 2:return '*';
	case 3:return '/';
	}
}

int dfs(int dep, int cur)
{
	if (cur == m)
	{
		return 1;
	}
	else if (dep >= maxstep)
	{
		return 0;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (dep == 0)
			{
				index[i] = 1;
				if (dfs(dep + 1, num[i]))
				{
					resnum.push(num[i]);
					return 1;
				}
				index[i] = 0;
			}
			else if (index[i] == 0)
			{
				index[i] = 1;
				for (int j = 0; j < 4; j++)
				{
					if (dfs(dep + 1, select_op(j, cur, num[i])))
					{
						resop.push(get_op(j));
						resnum.push(num[i]);
						return 1;
					}
				}
				index[i] = 0;
			}
		}
		return 0;
	}
}

int main()
{
	string path;
	getline(cin, path);
	char file[500] = { 0 };
	int count = 0;
	while (1)
	{

		bool hasSolution = false;
		//read
		sprintf_s(file, "%s\\ARIT%d.IN", path.data(), count++);
		ifstream in(file);
		if (!in.is_open())
			break;
		//
		in >> n >> m;
		for (int i = 0; i < n; i++)
		{
			in >> num[i];
		}
		cout << file << endl;
		for (int i = 0; i < n; i++)
		{
			maxstep = i;
			if (dfs(0, 0))
			{
				cout << maxstep - 1 << endl;
				while (!resnum.empty())
				{
					cout << resnum.top();
					resnum.pop();
					if (!resop.empty())
					{
						cout << resop.top();
						resop.pop();
					}
				}
				hasSolution = true;
				cout << endl;
				break;
			}
		}
		if (!hasSolution)
		{
			cout << "No Solution" << endl;
		}
		in.close();
	}
	return 0;
}
