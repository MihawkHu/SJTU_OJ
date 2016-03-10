#include <iostream>
using namespace std;
const int oo = 2147483647;
const int maxlen = 100010;

struct node {
	int num;
	int time;
	node *next;
	int par;

	node() : time(0), next(NULL), par(0) {}
	~node() {}
};


node* tree[maxlen] = { NULL };
bool f[maxlen] = { false };
bool flag = false;

long long dfs(int i, int n, int m) {
	long long result = 0;
	int k, min;
	node *tem;
	while (1) {
		min = oo;
		for (tem = tree[i]; tem != NULL; tem = tem->next) {
			if (!f[tem->num] && min > tem->time || (min == tem->time && k > tem->num)) {
				min = tem->time;
				k = tem->num;
			}
		}
		if (min == oo) return result;
		f[k] = true;
		result += min;
		if (k == m) {
			flag = true;
			return result;
		}
		result += dfs(k, n, m);
		if (flag) break;
		result += min;
	}
	return result;
}

int main() {
	int n, m;  cin >> n >> m;
	for (int i = 1; i <= n - 1; ++i) {
		int pa, so, ti;  cin >> pa >> so >> ti;
		node *tem = tree[pa];
		if (tem == NULL) {
			tree[pa] = new node();
			tree[pa]->num = so;  tree[pa]->time = ti;  tree[pa]->par = pa;
		}
		else {
			while (tem->next != NULL) tem = tem->next;
			tem->next = new node();
			tem->next->num = so;  tem->next->time = ti;  tem->next->par = pa;
		}	
	}

	f[0] = true;
	long long result = dfs(0, n, m);
	cout << result;

	return 0;
}