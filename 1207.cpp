#include <iostream>
#include <cstdio>

using namespace std;

template <class T> class queue {
private:
	struct node {
		T element;
		node *next;

		node(const T &x, node *nextval = NULL) {
			element = x;
			next = nextval;
		}
		node() : next(NULL) {}
		~node() {}
	};

	node *front, *rear;

public:
	queue() {
		front = rear = NULL;
	}
	~queue() {
		node *temp;
		while (front != NULL) {
			temp = front;
			front = front->next;
			delete temp;
		}
	}

	bool empty() {
		return front == NULL;
	}

	void enqueue(const T &x);
	T dequeue();
	T headvalue() {
		return front->element;
	}

};

queue<int> keche, huoche;  //queue of keche and huoche
int sumofke = 0, sumofhuo = 0; //the total waiting time of keche and huoche
int kecheshu = 0, huocheshu = 0;

int main()
{
	int n;  cin >> n;

	int leixing;//keche  or  huoche
	int time; // wait time
	for (int i = 1; i <= n; ++i) {
		cin >> leixing >> time;
		if (leixing == 0) {
			kecheshu++;
			keche.enqueue(time);
		}
		if (leixing == 1) {
			huoche.enqueue(time);
			huocheshu++;
		}
	}

	int shiptime = 0;//shiptime = 0, 10 ,20, ....
	int cheshu;//the total numbers of keche and huoche on the ship
	while (!keche.empty() || !huoche.empty()) {
		cheshu = 0;
		
		if (!keche.empty()) {
			while (!keche.empty() && keche.headvalue() <= shiptime && cheshu < 10) {
				sumofke = sumofke + shiptime - keche.headvalue();
				cheshu++;
				keche.dequeue();
				if (cheshu == 4) {
					if (!huoche.empty() && huoche.headvalue() <= shiptime) {
						sumofhuo = sumofhuo + shiptime - huoche.headvalue();
						cheshu++;
						huoche.dequeue();
					}
					else if (!keche.empty() && keche.headvalue() <= shiptime) {
						sumofke = sumofke + shiptime - keche.headvalue();
						cheshu++;
						keche.dequeue();
					}
				}
				if (cheshu == 9) {
					if (!huoche.empty() && huoche.headvalue() <= shiptime) {
						sumofhuo = sumofhuo + shiptime - huoche.headvalue();
						cheshu++;
						huoche.dequeue();
					}
					else if (!keche.empty() && keche.headvalue() <= shiptime) {
						sumofke = sumofke + shiptime - keche.headvalue();
						cheshu++;
						keche.dequeue();
					}
				}
			}
		}
		if (keche.empty() || !huoche.empty() && huoche.headvalue() <= shiptime && cheshu < 10) {
			while (!huoche.empty() && huoche.headvalue() <= shiptime && cheshu < 10) {
				sumofhuo = sumofhuo + shiptime - huoche.headvalue();
				cheshu++;
				huoche.dequeue();
			}
		}
		shiptime += 10;
	}

	double kechepingjun = double(sumofke) / double(kecheshu);
	double huochepingjun = double(sumofhuo) / double(huocheshu);

	printf("%.3f", kechepingjun);
	cout << " ";
	printf("%.3f", huochepingjun);




	return 0;
}





template<class T>
void queue<T>::enqueue(const T & x){
	if (rear == NULL) {
		front = rear = new node(x);
	}
	else {
		rear->next = new node(x);
		rear = rear->next;
	}
}

template<class T>
T queue<T>::dequeue(){
	T x = front->element;
	node* temp = front;
	front = front->next;
	delete temp;
	if (front == NULL) rear = NULL;
	return x;
}


