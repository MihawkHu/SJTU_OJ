#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;
const int oo = 2147483647;

int n, m, s, t;

struct node {
    int num;
    int w;
    node *next;

    node() : next(NULL) {}
    node(int nn, int ww) : num(nn), w(ww), next(NULL) {}
};

node* a[10100];

int que[1000100];
int head = 0, rear = 0;
void enque(int x) {
    que[rear] = x;
    rear++;
}
int deque() {
    int result = que[head];
    head++;
    return result;
}
bool kque() {
    return head == rear;
}

int prev[10010] = { 0 };
bool f[10010];
int d[10010];
void spfa() {
    for(int i = 1; i <= n; ++i) d[i] = oo;
    enque(s);
    f[s] = true;
    d[s] = 0;
    while(!kque()) {
        int t = deque();
        f[t] = false;
        node *tem = a[t];
        while(tem != NULL) {
            if(d[tem->num] > d[t] + tem->w) {
                d[tem->num] = d[t] + tem->w;
                prev[tem->num] = t;
                if(!f[tem->num]) {
                    enque(tem->num);
                    f[tem->num] = true;
                }
            }
            tem = tem->next;
        }
    }
}

void print(int k) {
    if(prev[k]) print(prev[k]);
    cout << k << ' ';
}

int main()
{
    cin >> n >> m >> s >> t;
    for(int i = 1; i <= m; ++i) {
        int x, y, w;  cin >> x >> y >> w;
        node *tem = new node(y,w);
        tem->next = a[x];
        a[x] = tem;
    }
    spfa();
    cout << d[t] << endl;
    print(t);

    return 0;
}



