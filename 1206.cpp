#include <iostream>
#include <cstring>


using namespace std;

class stack {
private:
	struct node {
		char element;
		node* next;

		node(const char &x, node* nextval = NULL) {
			element = x;
			next = nextval;
		}
		node() : next(NULL) {}
		~node() {}
	};

	node* top;

public:
	stack() { top = NULL; }
	~stack() {
		node* temp;
		while (top != NULL) {
			temp = top;
			top = top->next;
			delete top;
		}
	}

	bool empty() const { return top == NULL; };

	void push(const char &x) {
		node *tmp = new node(x, top);
		top = tmp;
	}

	char pop() {
		node *tmp = top;
		top = top->next;
		char x = tmp->element;
		delete tmp;
		return x;
	}

	char topValue() const { return top->element; }

};


bool flag = true;


int main()
{
	char a[1000];
	stack charstack;

	bool youif = false; //判读else前是否有if与then

	while(cin >> a){
		if (!strcmp(a, "begin")) {
			charstack.push('b');
		}

		else if (!strcmp(a, "end")) {
			if (charstack.empty()) {
				flag = false;
				break;
			}
			else if (charstack.topValue() != 'b') {
				flag = false;
				break;
			}
			else {
				charstack.pop();
			}
		}

		else if (!strcmp(a, "if")) {
			charstack.push('i');
		}
		
		else if (!strcmp(a, "then")) {
			if (charstack.empty()) {
				flag = false;
				break;
			}
			else if (charstack.topValue() != 'i') {
				flag = false;
				break;
			}
			else {
				charstack.pop();
				youif = true;
			}
		}

		else if (!strcmp(a, "else")) {
			if (!youif) {
				flag = false;
				break;
			}
			else {
				youif = false;
			}
		}
	}
	if (flag) {
		if (!charstack.empty())
			flag = false;
	}


	if (!flag) {
		cout << "Error!" << endl;
	}
	else {
		cout << "Match!" << endl;
	}


	return 0;
}



