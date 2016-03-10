#include<iostream>
#include<cstring>
using namespace std;

const int maxlength = 1000000;



class list {

private:
	struct node {
		int element;
		node* next;

		node(const int &x, node* nextval = NULL) {
			element = x; next = nextval;
		}
		node() : next(NULL) {}
	};

	node* head;
	node* tail;
	node* fence;
	int size;

	void init() {
		head = tail = fence = new node;
		head->next = tail;
		tail->next = NULL;
		size = 0;
	}

public:
	list() {
		init();
	}
	list(list&);

	~list() {
		while (head != NULL) {
			fence = head;
			head = head->next;
			delete fence;
		}
	}

	int length() const {
		return size;
	}
	bool getValue(int &it) {
		if (fence == head) return false;
		it = fence->element;
		return true;
	}
	bool setValue(const int &item) {
		if (fence == head) return false;
		fence->element = item;
		return true;
	}

	bool toNext() {
		if (fence->next == NULL) return false;
		else fence = fence->next; return true;
	}
	void toHead() {
		fence = head;
	}

	void append(const int &item);
};




void read(char ch[maxlength], list& l);

void addition(list &l1, list &l2);




int main()
{
	char num1[maxlength], num2[maxlength];
	cin >> num1 >> num2;
	if ((strlen(num1) >= 1000000) || (strlen(num2) >= 1000000))  return 0;

	list l1, l2;

	read(num1, l1);
	read(num2, l2);


	addition(l1, l2);

	return 0;
}


void list::append(const int & item) {
	node* tem = new node;
	tem->element = item;
	tail->next = tem;
	tail = tem;
	tail->next = NULL;
	size++;
}

void read(char ch[maxlength], list & l) {
	int n = strlen(ch);
	for (int i = n - 1; i >= 0; i--) {
		l.append(ch[i] - '0');
	}
}


void addition(list &l1, list &l2) {
	list l3;


	list lShort = l1.length() <= l2.length() ? l1 : l2;
	list lLong = l1.length() >= l2.length() ? l1 : l2;

	lShort.toHead(); lLong.toHead();

	int it1, it2, tem;

	for (int i = 1; i <= lShort.length(); i++) {

		lShort.toNext(); lLong.toNext();

		lShort.getValue(it1);  lLong.getValue(it2);
		tem = it1 + it2;

		if (tem >= 10) {
			tem = tem - 10;
			if (!l3.toNext()) l3.append(0);
			l3.toNext();
			int it0; l3.getValue(it0);
			l3.setValue(it0 + tem);
			l3.append(1);
		}
		else {
			if (!l3.toNext()) l3.append(0);
			l3.toNext();
			int it0; l3.getValue(it0);
			if (it0 + tem >= 10) {
				l3.append(1);
				tem = tem - 10;
			}
			l3.setValue(tem + it0);
		}
	}

	for (int i = lShort.length(); i <= (lLong.length() - 1); i++) {
		lLong.toNext();
		int tem; lLong.getValue(tem);
		if (!l3.toNext()) l3.append(0);
		l3.toNext();
		int it0; l3.getValue(it0);
		if (it0 + tem >= 10) {
			l3.append(1);
			tem = tem - 10;
		}
		l3.setValue(tem + it0);
	}

	//print result
	int n = l3.length();
	l3.toHead();
	char a[maxlength];
	for (int j = 0; j <= n - 1; j++) {
		l3.toNext();
		int tem; l3.getValue(tem);
		a[j] = char(tem + '0');
	}
	for (int j = n - 1; j >= 0; j--) {
		cout << a[j];
	}
}

list::list(list &x) {
	init();
	x.toHead();
	while (x.toNext()) {
		int it; x.getValue(it);
		append(it);
	}

}
