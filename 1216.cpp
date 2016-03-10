#include <iostream>

using namespace std;

int a[200000], maxsize = 0;

void swap(int &x, int &y)
{
	int tmp = x;
	x = y;
	y = tmp;
}

void ins(int x)
{
	int hole = ++maxsize;
	for (;hole>1 && x < a[hole / 2]; hole /= 2) a[hole] = a[hole / 2];
	a[hole] = x;
}

int find(int x)
{
	int i, t;
	int min = 200000000;
	for (i = 1; i <= maxsize; ++i)
	{
		if (a[i]>x&&a[i]<min)
		{
			t = i;
			min = a[i];
		}
	}
	return t;
}

void dec(int x, int y)
{
	a[x] -= y;
	for (;x>1 && a[x]<a[x / 2]; x /= 2)
	{
		swap(a[x], a[x / 2]);
	}
}


int main()
{
	int M, i, num, num2;
	cin >> M;
	char s[10];
	for (i = 1; i <= M; ++i)
	{
		cin >> s;
		cin >> num;
		if (s[0] == 'd') {
			cin >> num2;
			dec(num, num2);
		}
		if (s[0] == 'f') { cout << find(num) << endl; }
		if (s[0] == 'i') { ins(num); }
	}
}
