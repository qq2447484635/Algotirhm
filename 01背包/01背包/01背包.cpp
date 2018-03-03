// 01背包.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct item
{
	int weight;
	int value;
};

int main()
{
	int bagweight;
	int itemcount;
	item items[205] = {0};
	item bag[5005] = { 0 };
	cin >> itemcount >> bagweight;
	for (int i = 0; i < itemcount; i++)
	{
		cin >> items[i].weight >> items[i].value;
	}
	for (int i=0; i < itemcount; i++)
	{
		for (int weight = bagweight ; weight > 0; weight--)
		{
			if (items[i].weight <= weight)
			{
				int a, b;
				a = bag[weight].value;
				b = bag[weight - items[i].weight].value + items[i].value;
				bag[weight].value =  a>b?a:b;
			}
		}
	}
	cout << bag[bagweight].value << endl;
    return 0;
}

