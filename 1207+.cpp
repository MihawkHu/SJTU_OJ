#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

void output(float x) {
	x *= 10000;
	int te = (int)x;
	if (te % 10 > 4) te += 10;
	int tem = (int)(te /= 10);
	cout << tem / 1000 << '.';
	cout << (tem % 1000 - tem % 100) / 100;
	cout << (tem % 100 - tem % 10) / 10;
	cout << tem % 10;
}

const int maxlen = 21000;
int hque[maxlen] = { 0 };
int kque[maxlen] = { 0 };
int h1 = 1, h2 = 1, r1 = 0, r2 = 0;
int n;
int op[maxlen], t[maxlen];

void henque(int x) {
	hque[++r1] = x;
}
int hdeque() {
	int x = hque[h1];
	h1++;
	return x;
}
void kenque(int x) {
	kque[++r2] = x;
}
int kdeque() {
	int x = kque[h2];
	h2++;
	return x;
}
int hsize() {
	return r1 - h1;
}
int ksize() {
	return r2 - h2;
}
int huo() {
	return hque[h1];
}
int ke() {
	return kque[h2];
}


int main()
{
	cin >> n; int k = 0, h = 0;
	for (int i = 1; i <= n; ++i) {
		int op, t;  cin >> op >> t;
		if (op == 0) {
			kenque(t);
			k++;
		}
		else {
			henque(t);
			h++;
		}
	}
	henque(2147483647);  kenque(2147483647);

	int t = 0, ansk = 0, ansh = 0;
	while (1) {
		int kcnt = 0, hcnt = 0;
		while (kcnt < 4 && ke() <= t) {
			ansk += (t - kdeque());
			kcnt++;
		}
		if (huo() <= t) {
			ansh += (t - hdeque());
			hcnt++;
		}
		while (kcnt < 8 && ke() <= t) {
			ansk += (t - kdeque());
			kcnt++;
		}
		while (kcnt + hcnt < 10 && huo() <= t) {
			ansh += (t - hdeque());
			hcnt++;
		}
		while (kcnt + hcnt < 10 && ke() <= t) {
			ansk += (t - kdeque());
			kcnt++;
		}
		if (ke() == 2147483647 && huo() == 2147483647) break;
		t += 10;
	}
	float ah = float(ansh) / float(h);
	float ak = float(ansk) / float(k);

	output(ak);
	cout << ' ';
	output(ah);


	return 0;
}
