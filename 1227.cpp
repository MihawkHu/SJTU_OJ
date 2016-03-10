#include <iostream>
using namespace std;

struct node {
	int data;
	node *next;

	node() : next(NULL) {}
	node(const int &x) {
		data = x;
		next = NULL;
	}
	~node() {}
};




int main() {
	int n;  cin >> n;
	node *head = new node;
	node *fence = head;
	for (int i = 0; i < n; i++) {
		int x;  cin >> x;
		fence->next = new node(x);
		fence = fence->next;
	}

	//sort
	fence = head->next;
	while (fence != NULL) {
		node *p = fence;
		node *min = p;
		while (p != NULL) {
			if (min->data > p->data) {
				min = p;
			}
			p = p->next;
		}
		int tem = fence->data;
		fence->data = min->data;
		min->data = tem;
		fence = fence->next;
	}
	
	fence = head->next;
	while (fence != NULL) {
		cout << fence->data << " ";
		fence = fence->next;
	}

	return 0;
}