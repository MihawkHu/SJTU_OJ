#include <iostream>
using namespace std;

class set {

	friend set operator*(const set &s1, const set &s2);
	friend set operator+(const set &s1, const set &s2);
	friend set operator-(const set &s1, const set &s2);

private:
	int size;
	int *elem;

public:
	set() {
		size = 0;
		elem = new int[10000];
	}
	~set() {
		delete[] elem;
	}

	int len() const {
		return size;
	}

	bool empty() {
		return size == 0;
	}

	bool find(const int &x) const{
		for (int i = 0; i < size; i++) {
			if (elem[i] == x) return true;
		}
		return false;
	}

	void insert(const int &x) {
		if (find(x)) return;
		elem[size++] = x;
	}

	void del(T x) {
		bool flag = false;
	}

	void qsort(int s, int t) {
		if (s >= t) return;
		int i = s, j = t, mid = elem[(s + t) >> 1];
		while (i <= j) {
			while (elem[i] < mid) ++i;
			while (elem[j] > mid) --j;
			if (i <= j) {
				int tem = elem[i];
				elem[i] = elem[j];
				elem[j] = tem;
				++i;  --j;
			}
		}
		qsort(s, j);
		qsort(i, t);
	}

	void output() {
		qsort(0, size - 1);
		for (int i = 0; i < size; ++i) {
			cout << elem[i] << " ";
		}
		cout << '\n';
	}

	int operator[](const int &pos) const{
		return elem[pos];
	}


	set &operator=(const set &other) {
		size = other.len();
		delete[] elem;
		elem = new int[10000];
		for (int i = 0; i < size; ++i) {
			elem[i] = other[i];
		}
		return *this;
	}
};

set operator*(const set &s1, const set &s2) {
	set c;
	for (int i = 0; i < s1.len(); ++i) {
		if (s2.find(s1[i]))  c.insert(s1[i]);
	}
	return c;
}

set operator+(const set &s1, const set &s2) {
	set c;
	for (int i = 0; i < s1.len(); ++i) {
		c.insert(s1[i]);
	}
	for (int i = 0; i < s2.len(); ++i) {
		c.insert(s2[i]);
	}
	return c;
}

set operator-(const set &s1, const set &s2) {
	set c;
	for (int i = 0; i < s1.len(); ++i) {
		if (!s2.find(s1[i])) c.insert(s1[i]);
	}
	return c;
}



int main()
{
	int m;  cin >> m;
	set set1;
	for (int i = 0; i < m; i++) {
		char a;  cin >> a;
		if (a == '+') {
			int n; cin >> n;
			set set2;
			for (int j = 0; j < n; ++j) {
				int num;  cin >> num;
				set2.insert(num);
			}
			set1 = set1 + set2;
			set1.output();
		}

		else if (a == '*') {
			int n; cin >> n;
			set set2;
			for (int j = 0; j < n; ++j) {
				int num;  cin >> num;
				set2.insert(num);
			}
			set1 = set1 * set2;
			set1.output();
		}

		else if (a == '-') {
			int n; cin >> n;
			set set2;
			for (int j = 0; j < n; ++j) {
				int num;  cin >> num;
				set2.insert(num);
			}
			set1 = set1 - set2;
			set1.output();
		}
	}
	return 0;
}