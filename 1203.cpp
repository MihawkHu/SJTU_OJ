#include <iostream>
using namespace std;

int strlen(char a[]) {
	int i = 0;
	while (a[i] != '\0') i++;
	return i;
}


template <class T> class list {

//	friend list<T> operator+ (list<T> &l1, list<T> &l2);

//	friend ostream &operator<<(ostream &os, list<T> &l);

private:
	struct node {
		T element;
		node *prev;
		node *next;

		node(const T &x, node* p = NULL, node* n = NULL) {
			element = x; prev = p; next = n;
		}
		node() : next(NULL), prev(NULL) {}
		~node() {};
	};

	node *head, *fence, *tail;
	int size;


	void init() {
		head = new node;
		tail = new node;
		head->next = tail;
		fence = new node;
		fence = head;
		tail->prev = head;
		size = 0;
	}

	void removeall();

public:
	list() {
		init();
	}
	list(const list<T> &l);
	~list() {
		removeall();
		delete head;
		delete tail;
	}

	int length() const {
		return size;
	}

	bool getValue(T &it);
	bool setValue(const T &item);

	bool toNext() {
		if (fence == tail) return false;
		fence = fence->next;
		return true;
	}
	bool toPrev() {
		if (fence == head) return false;
		fence = fence->prev;
		return true;
	}

	void toHead() {
		fence = head;
	}
	void toTail() {
		fence = tail;
	}



	void insert(const T &item);
	bool remove(T &it);
	void append(const T &item);


//	list &operator=(list &other);
};



template<class T>
void list<T>::removeall(){
	fence = head->next;
	while (fence != tail) {
		head->next = fence->next;
		fence->next->prev = head;
		delete fence;
		size--;
		fence = head->next;
	}
}
/*
template<class T>
list<T>::list(const list<T>& l) {
	init();
	l.toHead();
	T tem;
	for (int i = l.length(); i >= 1; i--) {
		l.toNext();
		l.getValue(tem);
		append(tem);
		size++;
	}
}
*/
template<class T>
bool list<T>::getValue(T & it) {
	if (fence == head || fence == tail) return false;
	it = fence->element;
	return true;
}

template<class T>
bool list<T>::setValue(const T & item) {
	if (fence == head || fence == tail) return false;
	fence->element = item;
	return true;
}

template<class T>
void list<T>::insert(const T & item) {
	if (fence == head) append(item); return;
	node* teml = new node;
	teml->element = item;
	fence->next->prev = teml;
	teml->next = fence->next;
	fence->next = teml;
	teml->prev = fence;
	size++;
}

template<class T>
bool list<T>::remove(T & it) {
	if (size == 0) return false;
	if (fence == head || fence == tail) return false;
	it = fence->element;
	node* teml = new node;
	teml = fence;
	fence->prev->next = fence->next;
	fence->next->prev = fence->prev;
	fence = fence->next;
	delete teml;
	size--;
	return true;
}

template<class T>
void list<T>::append(const T & item) {
	list<T>::node* teml = new node;
	teml->element = item;
	tail->prev->next = teml;
	teml->next = tail;
	teml->prev = tail->prev;
	tail->prev = teml;
	size++;
}
/*
template<class T>
list<T> operator+(list<T>& l1, list<T>& l2) {
	list<T> l3 = l1;
	l2.toHead();
	T tem;
	for (int i = 1; i <= l2.length(); i++) {
		l2.toNext();
		l2.getValue(tem);
		l3.append(tem);
	}
	return l3;
}

template<class T>
list<T>& list<T>::operator=(list<T>& other) {
	if (this == &other) return *this;
	removeall();

	T tem;
	other.toHead();
	for (int i = 1; i <= other.length(); i++) {
		other.toNext();
		other.getValue(tem);
		append(tem);
	}
	return *this;
}

template<class T>
ostream & operator<<(ostream & os, list<T>& l) {
	l.toHead();
	T tem;
	int length = l.length();
	for (int i = length; i >= 1; i++) {
		l.toNext();
		l.getValue(tem);
		os << tem << ' ';
	}
	return os;
}
*/




int main()
{
	char a[10];
	int n, m;
	cin >> a;
	cin >> n >> m;


	if (a[0] == 'i') {
		list<int> l1, l2;
		for (int i = 1; i <= n; i++) {
			int tem1;  cin >> tem1;
			l1.append(tem1);
		}
		for (int i = 1; i <= m; i++) {
			int tem2;  cin >> tem2;
			l2.append(tem2);
		}
		list<int> l3;
		l1.toHead(); l2.toHead(); l3.toHead();
		for (int i = 1; i <= n; ++i) {
			l1.toNext();
			int tem; l1.getValue(tem);
			l3.append(tem);
		}
		for (int i = 1; i <= m; ++i) {
			l2.toNext();
			int tem; l2.getValue(tem);
			l3.append(tem);
		}

		l3.toHead();
		for (int i = 1; i <= m + n; ++i) {
			l3.toNext();
			int out;
			l3.getValue(out);
			cout << out << ' ';
		}
		
	}
	else if (a[0] == 'c') {
		list<char> l1, l2;
		for (int i = 1; i <= n; i++) {
			char tem1;  cin >> tem1;
			l1.append(tem1);
		}
		for (int i = 1; i <= m; i++) {
			char tem2;  cin >> tem2;
			l2.append(tem2);
		}
		list<char> l3;
		l1.toHead(); l2.toHead(); l3.toHead();
		for (int i = 1; i <= n; ++i) {
			l1.toNext();
			char tem; l1.getValue(tem);
			l3.append(tem);
		}
		for (int i = 1; i <= m; ++i) {
			l2.toNext();
			char tem; l2.getValue(tem);
			l3.append(tem);
		}

		l3.toHead();
		for (int i = 1; i <= m + n; ++i) {
			l3.toNext();
			char out;
			l3.getValue(out);
			cout << out << ' ';
		}
	}
	else if (a[0] == 'd') {
		list<double> l1, l2;
		for (int i = 1; i <= n; i++) {
			double tem1;  cin >> tem1;
			l1.append(tem1);
		}
		for (int i = 1; i <= m; i++) {
			double tem2;  cin >> tem2;
			l2.append(tem2);
		}
		list<double> l3;
		l1.toHead(); l2.toHead(); l3.toHead();
		for (int i = 1; i <= n; ++i) {
			l1.toNext();
			double tem; l1.getValue(tem);
			l3.append(tem);
		}
		for (int i = 1; i <= m; ++i) {
			l2.toNext();
			double tem; l2.getValue(tem);
			l3.append(tem);
		}

		l3.toHead();
		for (int i = 1; i <= m + n; ++i) {
			l3.toNext();
			double out;
			l3.getValue(out);
			cout << out << ' ';
		}
	}
	else cout << "wrong";

	return 0;
}