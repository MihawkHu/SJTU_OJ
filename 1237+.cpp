#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;

int n, m;

struct node {
    int num;
    node *next;

    node() : next(NULL) {}
    node(int nn) : num(nn), next(NULL) {}
};

node* a[10100];
int d[10100] = { 0 };
int prev[10010] = { 0 };

int que[1001000];
int head = 0, rear = 0;
void enque(int x) {
    que[rear++] = x;
}
int deque() {
    int x = que[head];
    head++;
    return x;
}
bool kque() {
    return head == rear;
}

int qishu(int x) {
    int cnt = 0;
    while(x) {
        x = prev[x];
        ++cnt;
    }
    return cnt;
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int x, y;  cin >> y >> x;
        d[y]++;
        node *tem = new node(y);
        tem->next = a[x];
        a[x] = tem;
    }

    for(int i = 1; i <= n; ++i) {
        if(d[i] == 0) enque(i);
    }
    int cnt = 0;
    while(!kque()) {
        int t = deque();
        node *tem = a[t];
        while(tem != NULL) {
            d[tem->num]--;
            if(d[tem->num] == 0) {
                enque(tem->num);
                prev[tem->num] = t;
            }
            tem = tem->next;
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        if(qishu(i) > ans) ans = qishu(i);
    }
    cout << ans << endl;

    return 0;
}
