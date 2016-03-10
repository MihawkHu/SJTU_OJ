#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;

const int maxlen = 20;
const int oo = 2147483647;

int n, m, s, te;
int a[maxlen][maxlen] = { 0 };

int que[100010];
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

int d[maxlen];
bool f[maxlen];
void spfa() {
    for(int i = 1; i <= n; ++i) d[i] = oo;
    d[s] = 0;
    enque(s);
    f[s] = true;
    while(!kque()) {
        int t = deque();
        f[t] = false;
        for(int i = 1; i <= n; ++i) {
            if(i == t) continue;
            if(a[t][i] == oo) continue;
            if(a[t][i] + d[t] < d[i]) {
                d[i] = d[t] + a[t][i];
                if(!f[i]) {
                    enque(i);
                    f[i] = true;
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m >> s >> te;

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j) {
            if(i == j) a[i][j] = 0;
            else a[i][j] = oo;
        }
    for(int i = 1; i <= m; ++i) {
        int x, y, w;  cin >> x >> y >> w;
        if(x == y) a[x][y] = 0;
        else a[x][y] = (w < a[x][y]) ? w : a[x][y];
    }
    spfa();
    cout << d[te] << endl;
    return 0;
}
