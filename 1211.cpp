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
	/*	binarytree(const T &value) {
	root = new node(value);
	}*/
	~binarytree() {
		clear();
	}
/*
	T getValue() const {
		return root->element;
	}
	T getLeftValue() const {
		return root->left->value;
	}
	T getRightValue() const {
		return root->right->element;
	}

	bool setValue(const T &x) {
		if (root == NULL) return false;
		root->element = x;
		return true;
	}
	bool setLeftValue(const T &x) {
		if (root == NULL) return false;
		if (root->left == NULL) return false;
		root->left->element = x;
		return true;
	}
	bool setRightValue(const T &x) {
		if (root == NULL) return false;
		if (root->right == NULL) return false;
		root->right->element = x;
		return true;
	}


	void makeTree(const T &x, binarytree &lt, binarytree &rt) { //combine two trees to a new tree
		root = new node(x, lt.root, rt.root);
		lt.root = NULL;
		rt.root = NULL;
	}

	void delLeft() {
	clear(root->left);
	root->left = NULL;
	}
	void delRight() {
	clear(root->right);
	root->right = NULL;
	}

	bool empty() {
		return root == NULL;
	}*/
	void clear() {
		if (root != NULL) clear(root);
		root = NULL;
	}
//	int size() const {
//		return size(root);
//	}
//	int height() const {
//		return height(root);
//	}
	/*
	void preOrder() const {
	if (root == NULL) return;
	cout << "\n preOrder:";
	preOrder(root);
	}
	void postOrder() const {
	if (root == NULL) return;
	cout << "\n posOrder:";
	posOrder(root);
	}
	void midOrder() const {
	if (root == NULL) return;
	cout << "\n midOrder";
	midOrder(root);
	}

	//	void creatTree(T flag);
	
	int height(node *t) const {
		if (t == NULL) return 0;
		int lt = height(t->left), rt = height(t->right);
		return 1 + ((lt > rt) ? lt : rt);
	}*/
	void clear(node *t) {
		if (t->left != NULL) clear(t->left);
		if (t->right != NULL) clear(t->right);

	}
/*	int size(node *t) const {
		if (t == NULL) return 0;
		return 1 + size(t->left) + size(t->right);
	}
	void preOrder(node *t) const{
		if (t == NULL) return;
		cout << t->element << ' ';
		preOrder(t->left);
		preOrder(t->right);
	}
	void posOrder(node *t) const {
	if (t == NULL) return;
	posOrder(t->left);
	posOrder(t->right);
	cout << t->element << ' ';
	}
	void midOrder(node *t) const {
	if (t == NULL) return;
	midOrder(t->left);
	midOrder(t->right);
	cout << t->element << ' ';
	midOrder(t->right);
	}
	*/
	bool isCompletetree();

};

template<class T>
bool binarytree<T>::isCompletetree(){
	queue<node*> que;
	node *cur;
	int count = 0;

	if (root == NULL) return true;
	cur = root;
	root->element = 1;
	que.enqueue(cur);

	while (!que.empty()) {
		cur = que.dequeue();
		count++;
		if (count != cur->element) return false;

		if (cur->left != NULL) {
			cur->left->element = cur->element * 2;
			que.enqueue(cur->left);
		}
		if (cur->right != NULL) {
			cur->right->element = cur->element * 2 + 1;
			que.enqueue(cur->right);
		}
	}

	return true;
}

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
		vec[index]->left = vec[leftval];
		vec[index]->right = vec[rightval];
		if(leftval != 0) vec[leftval]->prev = vec[index];
		if(rightval != 0) vec[rightval]->prev = vec[index];
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
	struct node{
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
	binarytree<int> tree(n);

	bool flag = tree.isCompletetree();

	if (flag) cout << "Y";
	else cout << "N";

	return 0;
}
