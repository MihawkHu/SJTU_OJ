#include <iostream>
using namespace std;

int a[10000000];

void qsort(int s, int t) {
	if (s >= t) return;
	int i = s, j = t, mid = a[(s + t) >> 1];
	while (i <= j) {
		while (a[i] < mid) ++i;
		while (a[j] > mid) --j;
		if (i <= j) {
			int tem = a[i];
			a[i] = a[j];
			a[j] = tem;
			++i;  --j;
		}
	}
	qsort(s, j);
	qsort(i, t);
}

int main()
{
	int n;  cin >> n;
	for (int i = 0; i < n; ++i) {
		int x;  cin >> x;
		a[i] = x;
	}
	qsort(0, n - 1);

	int i = 1, j = 0;
	for (; i < n; ++i) {
		if (a[i] != a[j]) {
			j++;
			a[j] = a[i];
		}
	}
	j++;
	cout << j;

	return 0;
}