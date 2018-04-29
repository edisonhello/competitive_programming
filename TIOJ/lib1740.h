//A Special Judge For APIO'07 roads (user version)
//Author : yuscvscv

#ifndef _roads_
#define _roads_

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>

namespace _roads
{
	const int Maxn = 20010;
	const int Maxm = 100010;

	
	std::map<int, int> hash;
	
	int N, M, K, ct;
	
	int edge[Maxm][3];
	int djs[Maxn];

	int find(int x)
	{
		return djs[x] == x ? x : djs[x] = find(djs[x]);
	}
	
	void merge(int x, int y)
	{
		x = find(x);
		y = find(y);
		if (x == y) return;
		djs[x] = y;
	}
	
	void error(int n)
	{
		switch (n)
		{
			case 0:
				puts("Error 0: Read Input Error.");
				break;
			case 1:
				puts("Error 1: A, B of Solution(A, B, C) is out of range.");
				break;
			case 2:
				puts("Error 2: the edge(A, B, C) is not exist.");
				break;
		}
		exit(0);
	}
}

void Init(int &n, int &m, int &k, int U[], int V[], int C[]);
void Solution(int a, int b, int c);
void NoSolution();

void Init(int &n, int &m, int &k, int U[], int V[], int C[])
{
	int t;
	
	t = scanf("%d %d %d", &n, &m, &k);
	if(t != 3)
		_roads::error(0);
		
	_roads::N = n, _roads::M = m, _roads::K = k;
	
	for(int i=0;i<m;i++)
	{
		int a, b, c;
		
		t = scanf("%d %d %d", &a, &b, &c);
		if(t != 3)
			_roads::error(0);
			
		U[i] = a;
		V[i] = b;
		C[i] = c;
		
		_roads::hash[a * _roads::Maxn + b] = c+1;
	}
	
	for(int i=1;i<=n;i++)
		_roads::djs[i] = i;
	_roads::ct = 0;
	printf("Initialize done.\n");
}

void Solution(int a, int b, int c)
{
	if(!(1 <= a && a <= _roads::N) || !(1 <= b && b <= _roads::N))
		_roads::error(1);
		
	int t = a * _roads::Maxn + b;
	if(_roads::hash.count(t) == 0 || _roads::hash[t] != c+1)
		_roads::error(2);
	
	_roads::ct++;
	if(c == 0)
		_roads::K--;
	
	printf("Get Solution %d.\n", _roads::ct);
	
	_roads::merge(a, b);
	
	if(_roads::ct == _roads::N-1)
	{
		int s = 0;
		for(int i=1;i<=_roads::N;i++)
			if(_roads::djs[i] == i)
				s++;
				
		if(s == 1 && _roads::K == 0)
			printf("Correct.\n");
	}
}

void NoSolution()
{
	printf("No Solution.\n");
}

#endif
