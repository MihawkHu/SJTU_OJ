#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;

int son[20000];
int bro[20000];
int n, root;
int que[20100];
int head = 0, rear = 0;

void enque(int x) {
    que[++rear] = x;
}
int deque() {
    int x = que[++head];
    return x;
}

void findroot() {
    bool *check = new bool[n + 1];
    for(int i = 1; i <= n; ++i) check[i] = false;
    for(int i = 1; i <= n; ++i) {
        check[son[i]] = true;
        check[bro[i]] = true;
    }
    for(int i = 1; i <= n; ++i) {
        if(!check[i]) {
            root = i;
            break;
        }
    }
    delete[] check;
}

void pre(int i) {
    cout << i << ' ';
    if(son[i] != 0) pre(son[i]);
    if(bro[i] != 0) pre(bro[i]);
}

void post(int i) {
    if(son[i] != 0) post(son[i]);
    cout << i << ' ';
    if(bro[i] != 0) post(bro[i]);
}

void cengci() {
    enque(root);
    while(head != rear) {
        int tem = deque();
        cout << tem << ' ';
        if(son[tem] != 0) enque(son[tem]);
        while(bro[tem] != 0) {
            tem = bro[tem];
            if(son[tem] != 0) enque(son[tem]);
            cout << tem << ' ';
        }
    }
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        int m;  cin >> m;
        cin >> son[m] >> bro[m];
    }
    findroot();

    pre(root);  cout << endl;
    post(root);  cout << endl;
    cengci();  cout << endl;

    return 0;
}
