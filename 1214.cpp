#include <iostream>using namespace std; template <class T> class btree;template <class T> class vector;template <class T> class queue; template <class T> class btree {private:	struct node {		T elem;		node *left, *bro, *prev; 		node() : left(NULL), bro(NULL), prev(NULL) {}		node(const T &x, node *l = NULL, node *b = NULL, node *p = NULL) {			elem = x;			left = l;			bro = b;			prev = p;		}		~node() {}	}; 	node* root; public:	btree() : root(NULL) {}	btree(const int &n);	~btree() {		clear();	}	void clear() {		if (root != NULL) clear(root);		root = NULL;	}	void clear(node* t) {		if (t->left != NULL) clear(t->left);		if (t->bro != NULL) clear(t->bro);	} 	bool empty() {		return root == NULL;	} 	void preOrder() {		preOrder(root);	}	void postOrder() {		postOrder(root);	}	void levelOrder(); private:	void preOrder(node *t);	void postOrder(node *t);}; template<class T>btree<T>::btree(const int & n) {	vector<node*> vec;	vec[0] = NULL;	for (int i = 1; i <= n; ++i) {		vec[i] = new node;	} 	for (int i = 1; i <= n; ++i) {		int lef, broth;		long vi;		cin >> lef >> broth >> vi;		vec[i]->elem = vi;		vec[i]->left = vec[lef];		vec[i]->bro = vec[broth];		if (lef != 0) vec[lef]->prev = vec[i];		if (broth != 0) vec[broth]->prev = vec[i];	} 	for (int i = 1; i <= n; ++i) {		if (vec[i]->prev == NULL) {			root = vec[i];			break;		}	}} template<class T>void btree<T>::levelOrder() {	queue<node*> que;	node *cur; 	if (root == NULL) return;	que.enque(root); 	while (!que.empty()) {		cur = que.deque();		cout << cur->elem << " ";		if (cur->left != NULL) {			cur = cur->left;			que.enque(cur);			while (cur->bro != NULL) {				cur = cur->bro;				que.enque(cur);			}		}	}} template<class T>void btree<T>::preOrder(node * t) {	if (t == NULL) return;	cout << t->elem << " ";	preOrder(t->left);	preOrder(t->bro);} template<class T>void btree<T>::postOrder(node * t) {	if (t == NULL) return;	postOrder(t->left);	cout << t->elem << " ";	postOrder(t->bro);} template <class T> class vector {private:	T *elem;public:	vector() {		elem = new T[100050];	}	~vector() {		delete[] elem;	} 	T &operator[](int r) const {		return elem[r];	}}; template <class T> class queue {private:	struct node {		T elem;		node *next; 		node() : next(NULL) {}		node(const T &x, node *n = NULL) {			elem = x;			next = n;		}		~node() {}	}; 	node *front, *rear; public:	queue() {		front = rear = NULL;	}	~queue() {		node *tmp;		while (front != NULL) {			tmp = front;			front = front->next;			delete tmp;		}	} 	bool empty() {		return front == NULL;	} 	void enque(const T &x) {		if (rear == NULL) front = rear = new node(x);		else {			rear->next = new node(x);			rear = rear->next;		}	}	T deque() {		node *tmp = front;		T x = front->elem;		front = front->next;		if (front == NULL) rear = NULL;		delete tmp;		return x;	}}; int main(){	int n;  cin >> n;	btree<long> tree(n);  	tree.preOrder();	cout << '\n';	tree.postOrder();	cout << '\n';	tree.levelOrder();  	return 0;}