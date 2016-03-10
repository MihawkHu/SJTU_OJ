#include <iostream>
using namespace std;

int a[200001], cnt = 0;

void insert(int x){
	++cnt;
	int i;
	for (i = cnt - 1;i > 0 && a[i - 1]>x;--i) a[i] = a[i - 1];
	a[i] = x;
}

void find(int x){
	int i;
	for (i = 0; i < cnt; ++i) {
		if (a[i] == x) { cout << 'Y' << endl;return; }
	}
	cout << 'N' << endl;
}

void find_ith(int i){
	if (i > cnt) cout << 'N' << endl;
	else cout << a[i - 1] << endl;
}

void Delete(int x){
	int i;
	for (i = 0; i < cnt; ++i) if (a[i] == x) break;
	for (; i < cnt - 1; ++i) a[i] = a[i + 1];
	--cnt;
}

void Delete(int x, int y){
	int u, v, i, j, n;
	for (i = 0; i < cnt && a[i] <= x; ++i);
	u = i;
	for (; i < cnt && a[i] < y; ++i);
	v = i;
	n = v - u;
	for (; u < cnt - n; ++u) a[u] = a[u + n];
	cnt -= n;
}

int main()
{
	char s[30];
	int num1, num2;
	int N, i;  cin >> N;
	for (i = 1; i <= N; ++i){
		cin >> s;
		cin >> num1;
		if (s[0] == 'i'){
			insert(num1);
		}
		else if (s[0] == 'f'&&s[4] != '_'){
			find(num1);
		}
		else if (s[0] == 'f'&&s[4] == '_'){
			find_ith(num1);
		}
		else if (s[0] == 'd'&&s[6] != '_'){
			Delete(num1);
		}
		else if (s[0] == 'd'&&s[6] == '_'&&s[7] == 'l'){
			Delete(-200000000, num1);
		}
		else if (s[0] == 'd'&&s[6] == '_'&&s[7] == 'g'){
			Delete(num1, 200000000);
		}
		else if (s[0] == 'd'&&s[6] == '_'&&s[7] == 'i'){
			cin >> num2;
			Delete(num1, num2);
		}
	}
	return 0;
}
