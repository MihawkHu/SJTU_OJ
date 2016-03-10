#include <iostream>
using namespace std;

char ch[10000100];
char result[10000100];

int strlen(char a[]) {
	int i = 0;
	while (a[i] != '\0') ++i;
	return i;
}

int log2(int n) {
	if (n == 1) return 0;
	int m = 1;
	int result = 0;
	while (m <= n) {
		m <<= 1;
		result++;
	}
	result -= 2;
	return result;
}

int cf(int n) {
	int result = 1;
	for (int i = 1; i <= n; ++i) {
		result <<= 1;
	}
	return result;
}

void inorder1(char ch[], int s, int m) {
	if (s * 2 > m) cout << ch[s];
	else if (s * 2 == m) cout << ch[s * 2] << ch[s];
	else {
		inorder1(ch, s * 2, m);
		cout << ch[s];
		inorder1(ch, s * 2 + 1, m);
	}
}

void posorder1(char ch[], int s, int m) {
	if (s * 2 > m) cout << ch[s];
	else if (s * 2 == m) cout << ch[s * 2] << ch[s];
	else {
		posorder1(ch, s * 2, m);
		posorder1(ch, s * 2 + 1, m);
		cout << ch[s];
	}
}

void preorder1(char ch[], int s, int m) {
	if (s * 2 > m) cout << ch[s];
	else if (s * 2 == m) cout << ch[s] << ch[s * 2];
	else {
		cout << ch[s];
		preorder1(ch, s * 2, m);
		preorder1(ch, s * 2 + 1, m);
	}
}

void inorder2(char ch[], int s, int t, int pa) {
	if (s > t) return;
	if (s == t) {
		result[pa] = ch[s];
		return;
	}
	int h = log2(t - s + 1);
	int tmp = cf(h + 1);
	int pos = tmp + (tmp - 1) / 2;
	int tem = 0;
	if (t - s + 1 <= pos) tem = cf(h) - 1;
	else tem = cf(h) - 1 + t - s + 1 - pos;

	result[pa] = ch[t - tem];

	inorder2(ch, s, t - tem - 1, pa * 2);
	inorder2(ch, t - tem + 1, t, pa * 2 + 1);
}

void posorder2(char ch[], int s, int t, int pa) {
	if (s > t) return;
	if (s == t) {
		result[pa] = ch[s];
		return;
	}
	int h = log2(t - s + 1);
	int tmp = cf(h + 1);
	int pos = tmp + (tmp - 1) / 2;
	int tem = 0;
	if (t - s + 1 <= pos) tem = cf(h) - 1;
	else tem = cf(h) - 1 + t - s + 1 - pos;

	result[pa] = ch[t];

	posorder2(ch, s, t - tem - 1, pa * 2);
	posorder2(ch, t - tem, t - 1, pa * 2 + 1);
}

void preorder2(char ch[], int s, int t, int pa) {
	if (s > t) return;
	if (s == t) {
		result[pa] = ch[s];
		return;
	}
	int h = log2(t - s + 1);
	int tmp = cf(h + 1);
	int pos = tmp + (tmp - 1) / 2;
	int tem = 0;
	if (t - s + 1 <= pos) tem = cf(h) - 1;
	else tem = cf(h) - 1 + t - s + 1 - pos;

	result[pa] = ch[s];

	preorder2(ch, s + 1, t - tem, pa * 2);
	preorder2(ch, t - tem + 1, t, pa * 2 + 1);
}


int main()
{
	int n;  cin >> n;
	for (int p = 0; p < n; p++) {
		int m;  cin >> m;
		char com[10], com2[10];  cin >> com >> com2;
		cin >> ch;

		for (int i = 0; i < m + 3; ++i) {
			ch[m - i + 1] = ch[m - i];
		}


		if (com2[0] == 'E') {
			if (com[0] == 'I') {
				inorder1(ch, 1, m);
			}
			else if (com[1] == 'O') {
				posorder1(ch, 1, m);
			}
			else if (com[1] == 'R') {
				preorder1(ch, 1, m);
			}
		}

		else if (com2[0] == 'D') {
			if (com[0] == 'I') {
				for (int i = 0; i < m + 2; i++) result[i] = '\0';
				inorder2(ch, 1, m, 1);
				for (int i = 1; i <= m; ++i) cout << result[i];
			}
			else if (com[1] == 'O') {
				for (int i = 0; i < m + 2; i++) result[i] = '\0';
				posorder2(ch, 1, m, 1);
				for (int i = 1; i <= m; ++i) cout << result[i];
			}
			else if (com[1] == 'R') {
				for (int i = 0; i < m + 2; i++) result[i] = '\0';
				preorder2(ch, 1, m, 1);
				for (int i = 1; i <= m; ++i) cout << result[i];
			}
		}
		cout << endl;
	}

	return 0;
}