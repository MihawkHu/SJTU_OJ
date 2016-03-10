#include <cstdio>

int strlen(char a[]) {
	int i = 0;
	while (a[i] != '\0') ++i;
	return i;
}



int KMPfind(char t[], char p[], int *f) {
	int n = strlen(t), m = strlen(p);
	int count = 0;

	//failure function
	f[0] = 0;  f[1] = 0;
	for (int i = 1; i < m; ++i) {
		int j = f[i];
		while (j && p[i] != p[j]) j = f[i];
		if (p[i] == p[j]) f[i + 1] = j + 1;
		else f[i + 1] = 0;
	}

	int j = 0;
	for (int i = 0; i < n; ++i) {
		while (j && p[j] != t[i]) j = f[i];
		if (p[j] == t[i]) ++j;
		if (j == m) count++;
	}
	return count;
}


char in[100100];
char woca[10000][10000];


int main()
{
	scanf("%s", in);
	char sc[10000];  int j = 0;  int hang = 1;
	for (int i = 0; i < strlen(in); i++) {
		if (in[i] != 'P' && in[i] != 'B') {
			sc[j] = in[i];
			++j;
		}
		else if (in[i] == 'P') {
			for (int k = 0; k < j; ++k) {
				woca[hang][k] = sc[k];
			}
			hang++;
		}
		else if (in[i] == 'B') {
			j--;
		}
	}

	int *f = new int[100100];

	int num;  scanf("%d", &num);
	for (int v = 0; v < num; ++v) {
		int x, y;  scanf("%d%d", &x, &y);
		int output = KMPfind(woca[y], woca[x], f);
		printf("%d", output);
	}
	return 0;
}


