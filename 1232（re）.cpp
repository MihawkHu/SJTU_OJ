#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;
const int maxlen = 1000000;

int n, m1, m2;
int pa[maxlen];
int que[4 * maxlen];
int head = 0, rear = 0;
int ans[maxlen];
bool f[maxlen];
bool tong[maxlen][5];
int baba[maxlen];


int zhaoshu(int x, int f) {
	int i = 1, j = 1;
	while (x > i * (i + 1) / 2) ++i;
	j = x - (i * (i - 1) / 2);
	if (f == 0) {
		if (j == 1) return -1;
		else return j - 1 + (i - 2) * (i - 1) / 2;
	}
	else if (f == 1) {
		if (j == i) return -1;
		else return j + (i - 1) * (i - 2) / 2;
	}
	else if (f == 2) {
		if (i == n) return -1;
		else return j + i * (i + 1) / 2;
	}
	else if (f == 3) {
		if (i == n) return -1;
		else return j + 1 + i * (i + 1) / 2;
	}
	return -1;
}

int find(int x) {
	if (pa[x] == 0) {
		pa[x] = -1;
		return x;
	}
	if (pa[x] < 0) return x;
	return pa[x] = find(pa[x]);
}

void un(int i, int j) {
	int s = find(i), t = find(j);
	if (s == t) return;
	if (pa[s] > pa[t]) {
		pa[t] += pa[s];
		pa[s] = t;
	}
	else {
		pa[s] += pa[t];
		pa[t] = s;
	}
}

bool tongji(int x, int y) {
	return find(x) == find(y);
}

int c = 0;
void output(int m2) {
	if (m2 == m1) {
		ans[c++] = m1;
		return;
	}
	ans[c++] = m2;
	output(baba[m2]);
}


void bfs(int m1, int m2) {
	if (!tongji(m1, m2)) return;
	int cnt = 0;
	f[m1] = true;
	for (int i = 0; i <= 3; ++i) {
		if(tong[m1][i]) {
			int tem = zhaoshu(m1, i);
			if (tem == m2) {
				cout << m1 << ' ' << m2;
				return;
			}
			if (tem > 0 && !f[tem]) {
				que[rear++] = tem;
				baba[tem] = m1;
				f[tem] = true;
			}
		}
	}
	while (1) {
		ans[++cnt] = que[head++];
		if (ans[cnt] == m2) {
			output(m2);
			for (int i = c - 1; i >= 0; --i) cout << ans[i] << ' ';
			return;
		}
		for (int i = 0; i <= 3; ++i) {
			if (tong[ans[cnt]][i]) {
				int tem = zhaoshu(ans[cnt], i);
				if (tem > 0 && !f[tem]) {
					que[rear++] = tem;
					if(!baba[tem]) {
                        baba[tem] = ans[cnt];
					}
					f[tem] = true;
				}
			}
		}
	}
}


int main()
{
	cin >> n >> m1 >> m2;
	int k, d;
	while (cin >> k) {
		cin >> d;
		tong[k][d] = true;
		int shu = zhaoshu(k, d);
		if (shu < 0) continue;
		else if (tongji(k, shu)) continue;
		else un(k, shu);
		if (!tongji(m1, m2)) continue;
		else {
			bfs(m1, m2);
			return 0;
		}
	}
	return 0;
}
