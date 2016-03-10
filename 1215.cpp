#include <iostream>
using namespace std;

template <class T> class pqueue {
private:
	int size;
	T *elem;
	int maxlength;

	void buildheap();
	void shiftdown(int pos);

public:
	pqueue() {
		elem = new T[maxlength = 20000];
		size = 0;
	}
	pqueue(const T a[], int len);
	~pqueue() {
		delete[] elem;
	}

	bool empty() const {
		return size == 0;
	}
	void enque(const T &x);
	T deque();
	T getmin() const {
		return elem[1];
	}

};

template<class T>
void pqueue<T>::buildheap() {
	for (int i = size / 2; i > 0; --i) shiftdown(i);
}

template<class T>
void pqueue<T>::shiftdown(int pos) {
	int child;
	T tmp = elem[pos];

	for (; pos * 2 <= size; pos = child) {
		child = pos * 2;
		if (child != size && elem[child + 1] < elem[child]) child++;
		if (elem[child] < tmp) elem[pos] = elem[child];
		else break;
	}
	elem[pos] = tmp;
}

template<class T>
pqueue<T>::pqueue(const T a[], int len) {
	size = len;
	elem = new T[maxlength = 20000];
	for (int i = 0; i < size; ++i) elem[i + 1] = a[i];
	this->bulidheap();
}

template<class T>
void pqueue<T>::enque(const T & x) {
	int pos = ++size;
	for (; pos > 1 && x < elem[pos / 2]; pos = pos / 2) elem[pos] = elem[pos / 2];
	elem[pos] = x;
}

template<class T>
T pqueue<T>::deque() {
	T x = elem[1];
	elem[1] = elem[size--];
	shiftdown(1);
	return x;
}

int main()
{
	pqueue<int> pq;
	int m;  cin >> m;
	for (int i = 0; i <= m; i++) {
		char in[30];  cin.getline(in, 30);

		if (in[0] == 'i') {
			int tem = (int)(in[7] - '0');
			int j = 7;
			while (in[j + 1] >= '0' && in[j + 1] <= '9'){
				++j;
				tem = tem * 10 + (int)(in[j] - '0');
			}
			pq.enque(tem);
		}


		else if (in[0] == 'd') {
			pq.deque();
		}

		else if (in[0] == 'm') {
			cout << pq.getmin() << '\n';
		}
	}


	return 0;
}