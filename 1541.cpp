#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1000005;

struct Elem
{
	int val;
	int pos;
};

Elem maxque[N];
int maxhead, maxtail;
int maxans[N];
int cur;

int main()
{
	int n, w, num;
	cin >> w >> n;
	maxhead = maxtail = 0;
	cur = 0;
	for (int i = 0; i < w; ++i)
	{
		cin >> num;

		while (maxhead < maxtail && maxque[maxtail - 1].val <= num) --maxtail;
		maxque[maxtail].val = num;
		maxque[maxtail].pos = i;
		++maxtail;
	}
	for (int i = w; i < n; ++i)
	{
		maxans[cur] = maxque[maxhead].val;
		++cur;

		cin >> num;

		while (maxhead < maxtail && i - maxque[maxhead].pos >= w) ++maxhead;
		while (maxhead < maxtail && maxque[maxtail - 1].val <= num) --maxtail;
		maxque[maxtail].val = num;
		maxque[maxtail].pos = i;
		++maxtail;
	}
	maxans[cur] = maxque[maxhead].val;
	++cur;

	for (int i = 0; i < cur; ++i) cout << maxans[i] << " ";

	return 0;
}
