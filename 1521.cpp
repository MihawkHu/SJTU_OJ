#include <iostream>
using namespace std;

struct node {
	int num;
	node *next;
	bool leaf;

	node() : next(NULL), leaf(true) {}
	~node() {}
};

node* tree[20010] = { NULL };

int max1[20010] = { 0 };
int max2[20010] = { 0 };

int max(int i) {
	if (max1[i] > 0) return max1[i];
	if (tree[i] == NULL) {
		max1[i] = 0;
		return 0;
	}
	if (tree[i]->leaf) {
		max1[i] = 1;
		return 1;
	}
	
	node* tem = tree[i];
	while (tem != NULL) {
		int t = 0;
		if (max1[tem->num] == 0) {
			t = max(tem->num);
			max1[tem->num] = t;
		}
		else t = max1[tem->num];
		t++;
		if (max1[i] <= t) {
			max2[i] = max1[i];
			max1[i] = t;
		}
		else if (max2[i] < t) max2[i] = t;
		tem = tem->next;
	}
	return max1[i];
}

int main() 
{
	int n, m;  cin >> n >> m;
	for (int i = 2; i <= n + m; ++i) {
		int pa;  cin >> pa;
		if (tree[pa] == NULL) {
			tree[pa] = new node;
			tree[pa]->num = i;
			tree[pa]->leaf = false;
		}
		else {
			node *tem = tree[pa];
			while (tem->next != NULL) tem = tem->next;
			tem->next = new node;
			tem->next->num = i;
			tem->leaf = false;
		}
	}

	for (int i = 1; i <= n; ++i) {
		max(i);
	}
	int result = 0;
	for (int i = 1; i <= n; ++i) {
		if (result < max1[i] + max2[i]) result = max1[i] + max2[i];
	}
	cout << result;

	return 0;
}