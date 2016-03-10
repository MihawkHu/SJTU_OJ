#include <iostream>
#include <cstdio>
using namespace std;

const int p = 3999971;
int a[510] = { 0 }, b[510] = { 0 };
int c[510] = { 0 }, d[510] = { 0 };
int ht[4000000];
bool f[4000000];
int cnt[4000000] = { 0 };

/*
int sushu(int x){
int ans = x;
for(;;ans--){
bool flag = true;
for(int i = 2; i < ans / 2 + 1; i++){
if(ans % i == 0) {
flag = false;
break;
}
}
if(flag) break;
}
return ans;
}
*/
void insert(int x) {
	int tem = (x >= 0) ? x : -x;
	int pos = tem % p;
	for (;;) {
		if (f[pos] && ht[pos] != x) pos++;
		else if (f[pos] && ht[pos] == x) {
			cnt[pos]++;
			return;
		}
		else {
			ht[pos] = x;
			f[pos] = true;
			cnt[pos]++;
			return;
		}
	}
}

void find(int x, int &count) {
	int tem = (x > 0) ? x : -x;
	int pos = tem % p;
	for (;;) {
		if (!f[pos]) return;
		else if (ht[pos] == x) {
			count += cnt[pos];
			return;
		}
		pos++;
	}
}


int main()
{
	int n;  cin >> n;
	for (int i = 0; i < n; i++) scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
	for (int i = 0; i <= n * n; i++) f[i] = false;

	int count = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			insert(-(a[i] + b[j]));
		}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			find((c[i] + d[j]), count);
		}

	cout << count;

	return 0;
}
