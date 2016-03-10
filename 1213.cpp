#include <iostream>
using namespace std;

template <class T> class binarytree;
template <class T> class vector;
template <class T> class queue;

template <class T> class binarytree {
public:
	struct node {
		T element;
		node *left, *right, *prev;

		node() : left(NULL), right(NULL), prev(NULL) {}
		node(T e, node *l = NULL, node *r = NULL, node *p = NULL) {
			element = e;
			left = l;
			right = r;
			prev = p;
		}
		~node() {}
	};

	node* root;



	binarytree() : root(NULL) {}
	binarytree(const int &n);
	~binarytree() {
		clear();
	}

	bool empty() {
		return root == NULL;
	}
	void clear() {
		if (root != NULL) clear(root);
		root = NULL;
	}

	void clear(node *t) {
		if (t->left != NULL) clear(t->left);
		if (t->right != NULL) clear(t->right);

	}

};

template<class T>
binarytree<T>::binarytree(const int &n)
{
	vector<node*> vec;
	vec[0] = NULL;
	for (int i = 1; i <= n; ++i) {
		vec[i] = new node;
	}
	for (int index = 1; index <= n; ++index) {
		int leftval, rightval;  cin >> leftval >> rightval;
		long elem;  cin >> elem;
		vec[index]->element = elem;
		vec[index]->left = vec[leftval];
		vec[index]->right = vec[rightval];
		if (leftval != 0) vec[leftval]->prev = vec[index];
		if (rightval != 0) vec[rightval]->prev = vec[index];
	}
	for (int i = 1; i <= n; ++i) {
		if (vec[i]->prev == NULL) {
			root = vec[i];
			break;
		}
	}
}

template <class T> class vector {
private:
	int size;
	int capacity;
	T *elem;

public:
	vector(int c = 100100, int s = 0) {
		elem = new T[capacity = c];
		size = 0;
	}
	~vector() {
		delete[] elem;
	}
	int length() const {
		return size;
	}
	int empty() const {
		return size == 0;
	}

	T &operator[](int r) const {
		return elem[r];
	}

	void store(const T& x, const int r) {
		elem[r] = x;
		size++;
	}
};

template <class T> class queue {
private:
	struct node {
		T element;
		node* next;

		node(const T &x, node* nextval = NULL) {
			element = x;
			next = nextval;
		}
		node() : next(NULL) {}
		~node() {};
	};

	node *front, *rear;

public:
	queue() {
		front = rear = NULL;
	}
	~queue() {
		node *tmp;
		while (front != NULL) {
			tmp = front;
			front = front->next;
			delete tmp;
		}
	}

	bool empty() {
		return front == NULL;
	}

	void enqueue(const T& x) {
		if (rear == NULL) front = rear = new node(x);
		else {
			rear->next = new node(x);
			rear = rear->next;
		}
	}

	T dequeue() {
		node *tmp = front;
		T x = front->element;
		front = front->next;
		if (front == NULL) rear = NULL;
		delete tmp;
		return x;
	}


};

bool checkEqual(binarytree<long>::node *t1, binarytree<long>::node *t2);

int main()
{
	int n, m;  
	
	cin >> n;
	binarytree<long> tree1(n);
	cin >> m;
	binarytree<long> tree2(m);

	bool flag;
	if (n != m) flag = false;
	else {
		flag = checkEqual(tree1.root, tree2.root);
	}

	if (flag) cout << "Y";
	else cout << "N";

	return 0;
}

bool checkEqual(binarytree<long>::node *t1, binarytree<long>::node *t2) {	
	if (t1 == NULL && t2 == NULL) return true;
	if (t1 == NULL && t2 != NULL) return false;
	if (t1 != NULL && t2 == NULL) return false;
	if (t1->element != t2->element) return false;

	return checkEqual(t1->left, t2->left) && checkEqual(t1->right, t2->right);

}