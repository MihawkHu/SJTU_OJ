#include <iostream>
#pragma warning(disable:4996)

using namespace std;

class fraction;
template <class T> class vector;

class fraction { //watch out that the den != 0 has not been considered
	friend ostream& operator<<(ostream &os, const fraction &obj);
	friend bool operator!=(const fraction &r1, const fraction &r2);
	friend bool operator==(const fraction &r1, const fraction &r2);
	friend bool operator>(const fraction &r1, const fraction &r2);

private:
	int num;
	int den;

	void reduct();  //yue fen

public:
	fraction(int n = 0, int d = 1) {
		num = n;
		den = d;
		reduct();
	}

	fraction &operator=(const fraction &obj);  // fuzhi yunsuanfu  chongzai
};

ostream& operator<<(ostream &os, const fraction &obj) {
	os << obj.num << '/' << obj.den;
	return os;
}

bool operator!=(const fraction &r1, const fraction &r2) {
	return r1.num * r2.den != r2.num * r1.den;
}

bool operator==(const fraction &r1, const fraction &r2) {
	return r1.num * r2.den == r1.den * r2.num;
}

bool operator>(const fraction &r1, const fraction &r2) {
	return r1.num * r2.den > r1.den * r2.num;
}

void fraction::reduct() {
	int smallone = num >= den ? den : num;
	if (smallone == 0) {
		num = 0;
		den = 1;
	}
	else {
		int tem = smallone; //max gongyueshu
		while (den % tem != 0 || num % tem != 0) {
			tem--;
		}
		den /= tem;
		num /= tem;
	}

}

fraction & fraction::operator=(const fraction & obj) {
	if (this == &obj) return *this;
	this->num = obj.num;
	this->den = obj.den;
	return *this;
}



template <class T > class vector {
private:
	int size;
	int capacity;
	T *elem; // shuzu  zhizhen

public:
	vector(int c = 15000, int s = 0) {
		elem = new T[capacity = c];
		size = 0;
	}
	~vector() {
		delete[] elem;
	}

	int length() const {
		return size;
	}
	void lengthjia1() {
		size++;
	}
	int empty() const {
		return size == 0;
	}

	T &operator[](int r) const;

	void sort();
};



template<class T>
T & vector<T>::operator[](int r) const {
	return elem[r];
}

template<class T>
void vector<T>::sort() {
	bool sorted = false;
	int n = size;
	while (!sorted) {
		sorted = true;
		for (int i = 1; i < n; i++) {
			if (elem[i - 1] > elem[i]) {
				T tem = elem[i - 1];
				elem[i - 1] = elem[i];
				elem[i] = tem;
				sorted = false;
			}
		}
		n--;
	}
}



int main() {
	vector<fraction> vec;
	int n;  cin >> n;

	if (n == 1) {
		cout << "0/1" << '\n';
		cout << "1/1" << '\n';
		return 0;
	}

	int k = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= i - 1; ++j) {
			vec[k] = fraction(j, i);
			vec.lengthjia1();
			++k;
		}


	vec.sort();


	cout << "0/1" << '\n';
	cout << vec[0] << '\n';

	for (int i = 1; i < vec.length(); ++i) {
		if (vec[i] != vec[i - 1])
			cout << vec[i] << '\n';
	}

	cout << "1/1" << '\n';


	return 0;
}
