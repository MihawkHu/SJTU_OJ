#include <iostream>
using namespace std;

template <class T> class set {
private:
	int size;
	T *elem;

public:
	set() {
		elem = new T[3000];
		size = 0;
	}
	~set() {
		delete[] elem;
	}

	int getsize() const{
		return size;
	}
	bool empty() {
		return size == 0;
	}


	bool find(const T &x) const;
	void insert(const T&x);
};



int main()
{
	set<int> set1;
	int m;  cin >> m;
	for (int i = 0; i < m; i++) {
		int num;  cin >> num;
		set1.insert(num);
	}
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		if(set1.find(num)) cout << "Y" << '\n';
		else cout << "N" << '\n';
	}

	return 0;
}

template<class T>
bool set<T>::find(const T & x) const {
	for (int i = 0; i < size; ++i) {
		if (elem[i] == x) return true;
	}
	return false;
}

template<class T>
void set<T>::insert(const T & x){
	if (find(x)) return;
	elem[size++] = x;
}
