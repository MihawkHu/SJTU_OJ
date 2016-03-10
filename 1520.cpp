#include <iostream>
using namespace std;

bool isnum(char a) {
	return (a <= '9' && a >= '0');
}

bool isop(char a) {
	return a == '+' || a == '-';
}

template <class T> class stack {
private:
	struct node {
		T data;
		node* next;

		node() : next(NULL) {}
		node(const T &x, node* nextval = NULL) {
			data = x;
			next = nextval;
		}
		~node() {}
	};

	node* top;

public:
	stack() {
		top = NULL;
	}
	~stack() {
		while (top != NULL) {
			node* tem = top;
			top = top->next;
			delete tem;
		}
	}

	bool empty() {
		return top == NULL;
	}

	T pop() {
		T x = top->data;
		node *tem = top;
		top = top->next;
		delete tem;
		return x;
	}

	void push(const T& x) {
		if (top == NULL) {
			top = new node(x);
			return;
		}
		node* tem = new node(x, top);
		top = tem;
	}

	T topvalue() {
		if (top == NULL) return '0';
		return top->data;
	}
};

char in[1000000];

int main()
{
	cin.getline(in, 1000000);
	stack<long> num;
	stack<char> cha;
	
	for (int i = 0; in[i] != '\0'; ++i) {
		if (in[i] == ' ') continue;
		else if (in[i] == '(') cha.push(in[i]);
		else if (isnum(in[i])) {
			long tem = (long)(in[i] - '0');
			while (isnum(in[i + 1])) {
				++i;
				tem = tem * 10 + (long)(in[i] - '0');
			}
			num.push(tem);
		}
		else if (isop(in[i])) {
			if (isop(cha.topvalue())) {
				char op = cha.pop();
				long num2 = num.pop();
				long num1 = num.pop();
				if (op == '+') num.push(num1 + num2);
				if (op == '-') num.push(num1 - num2);
			}
			cha.push(in[i]);
		}

		else if (in[i] == ')') {
			if (cha.topvalue() == '(') cha.pop();
			else if (isop(cha.topvalue())) {
				char op = cha.pop();
				long num2 = num.pop();
				long num1 = num.pop();
				if (op == '+') num.push(num1 + num2);
				if (op == '-') num.push(num1 - num2);
				cha.pop();
			}
		}

	}

	if (!cha.empty()) {
		char op = cha.pop();
		long num2 = num.pop();
		long num1 = num.pop();
		if (op == '+') num.push(num1 + num2);
		if (op == '-') num.push(num1 - num2);
	}

	long result = num.pop();
	cout << result;


	return 0;
}