#include <iostream>
using namespace std;

template <class T> class binarytree;
template <class T> class vector;
template <class T> class queue;

template <class T> class binarytree {
private:
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

public:


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

	void depthTraverse();
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

template<class T>
void binarytree<T>::depthTraverse() {
	queue<node*> que;
	node* cur;

	if (root == NULL) return;
	que.enqueue(root);
	while (!que.empty()) {
		cur = que.dequeue();
		cout << cur->element << " ";
		if (cur->left != NULL) que.enqueue(cur->left);
		if (cur->right != NULL) que.enqueue(cur->right);
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

int main()
{
	int n;  cin >> n;
	binarytree<long> tree(n);

	tree.depthTraverse();

	return 0;
}