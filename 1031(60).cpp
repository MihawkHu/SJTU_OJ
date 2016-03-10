#include <iostream>
using namespace std;

struct node {
	int r, c;

	node() {};
	node(int a, int b) : r(a), c(b) {}
	~node() {}
};

class queue {
private:
	struct nod {
		node elem;
		nod* next;

		nod() : next(NULL) {}
		~nod() {}
	};

	nod *f, *r;
public:
	queue() {
		f = r = NULL;
	}
	~queue() {
		while (f != NULL) {
			nod* tem = f;
			f = f->next;
			delete tem;
		}
	}

	bool empty() const {
		return f == NULL;
	}

	node value() const {
		return f->elem;
	}

	node deque() {
		node x;
		x.r = f->elem.r;
		x.c = f->elem.c;
		nod *tem = f;
		f = f->next;
		if (f == NULL) r = NULL;
		delete tem;
		return x;
	}

	void enque(const node &x) {
		if (r == NULL) {
			f = r = new nod;
			r->elem.c = x.c;
			r->elem.r = x.r;
		}
		else {
			r->next = new nod;
			r = r->next;
			r->elem.c = x.c;
			r->elem.r = x.r;
		}
	}

};

int m[105][105] = { 0 };
bool f[105][105];
queue que;





bool bfs(int low, int high, int n) {
	if (m[1][1] < low || m[1][1] > high) return false;
	que.enque(node(1, 1));
	f[1][1] = true;

	while (!que.empty()) {
		int x = que.value().r, y = que.value().c;
		que.deque();
		if (x == n && y == n) return true;
		if (x + 1 <= n && !f[x + 1][y]) {
			f[x + 1][y] = true;
			if (m[x + 1][y] >= low && m[x + 1][y] <= high)
				que.enque(node(x + 1, y));
		}
		if (x - 1 > 0 && !f[x - 1][y]) {
			f[x - 1][y] = true;
			if (m[x - 1][y] >= low && m[x - 1][y] <= high)
				que.enque(node(x - 1, y));
		}
		if (y + 1 <= n && !f[x][y + 1]){
			f[x][y + 1] = true;
			if (m[x][y + 1] >= low && m[x][y + 1] <= high)
				que.enque(node(x, y + 1));
		}
		if (y - 1 > 0 && !f[x][y - 1]) {
			f[x][y - 1] = true;
			if (m[x][y - 1] >= low && m[x][y - 1] <= high)
				que.enque(node(x, y - 1));
		}
	}
	return false;
}


int main()
{
	int n;  cin >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			cin >> m[i][j];
			f[i][j] = false;
		}
	
	int k = 0, d = 110;
	while (d > k) {
		int mid = ((d + k) >> 1);
		bool flag = false;
		for (int low = 0; low <= 110 - mid; low++) {
			for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= n; j++)
					f[i][j] = false;
			if (bfs(low, low + mid, n)) {
				flag = true;
				break;
			}
		}
		if (flag) d = mid;
		else k = mid + 1;
	}

	cout << d;
	return 0;
}