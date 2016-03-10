#include <iostream>
using namespace std;


void posorder(int s1, int t1, int s2, int t2, int result[], int s3, int t3, int pre[], int in[]) {
	if (s1 == t1) {
		result[s3] = pre[s1];
		return;
	}
	if(s1 > t1) return;
	int pos = 0;
	for (int i = s2; i <= t2; ++i) {
		if (in[i] == pre[s1]) {
			pos = i;
			break;
		}
	}
	result[t3] = pre[s1];
	posorder(s1 + 1, s1 + pos - s2, s2, pos - 1, result, s3, s3 + pos - s2 - 1, pre, in);
	posorder(s1 + pos - s2 + 1, t1, pos + 1, t2, result, s3 + pos - s2, t3 - 1, pre, in);
}


int main()
{
	int n;  cin >> n;
	int pre[100100], in[100100];
	int pos[100100];
	for (int i = 0; i < n; ++i) cin >> pre[i];
	for (int i = 0; i < n; ++i) cin >> in[i];

	posorder(0, n - 1, 0, n - 1, pos, 0, n - 1, pre, in);

	for (int i = 0; i < n; ++i) cout << pos[i] << " ";
	return 0;
}