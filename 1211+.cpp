#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;
const int maxlen = 100100;

int le[maxlen] = { 0 }, ri[maxlen] = { 0 };
int root;
bool check[maxlen] = { 0 };
int n;
int que[maxlen] = { 0 };
int head = 1, rear = 0;
int cnt = 0;
int num[maxlen] = { 0 };

void enque(int x) {
    que[++rear] = x;
}
int deque() {
    int x = que[head];
    head++;
    return x;
}
bool empty() {
    return rear + 1 == head;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> le[i] >> ri[i];
        check[le[i]] = check[ri[i]] = true;
    }
    for(int i = 1; i <= n; ++i) {
        if(check[i] == false) {
            root = i;
            break;
        }
    }
    enque(root);
    num[root] = 1;
    while(!empty()) {
        int tem = deque();
        cnt++;
        if(cnt != num[tem]) {
            cout << "N" << endl;
            return 0;
        }
        if(le[tem] != 0) enque(le[tem]);
        if(ri[tem] != 0) enque(ri[tem]);
        num[le[tem]] = cnt * 2;  num[ri[tem]] = cnt * 2 + 1;
    }
    cout << "Y" << endl;
    return 0;
}
