#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;
const int maxlen = 10100;

int n, m;

//bingchaji
int ms[maxlen];
int find(int x) {
    if(ms[x] == 0) {
        ms[x] = -1;
        return x;
    }
    if(ms[x] < 0) return x;
    return ms[x] = find(ms[x]);
}
void un(int x, int y) {
    int v = find(x), u = find(y);
    if(v == u) return;
    if(ms[v] > ms[u]) {
        ms[u] += ms[v];
        ms[v] = u;
    }
    else {
        ms[v] += ms[u];
        ms[u] = v;
    }
}
bool tongji(int x, int y) {
    return find(x) == find(y);
}

struct node {
    int s;
    int t;
    int w;

    node() {}
    node(int q, int e, int r) : s(q), t(e), w(r) {}
};

node bian[maxlen * 10];

void qsort(int s, int t) {
    if(s >= t) return;
    int i = s, j = t, mid = bian[(i + j) >> 1].w;
    while(i <= j) {
        while(bian[i].w < mid) ++i;
        while(bian[j].w > mid) --j;
        if(i <= j) {
            node tem = bian[i];
            bian[i] = bian[j];
            bian[j] = tem;
            ++i;  --j;
        }
    }
    qsort(s, j);
    qsort(i, t);
}


int main()
{
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        cin >> bian[i].s >> bian[i].t >> bian[i].w;
    }
    qsort(1, m);

    int cnt = 1, ans = 0;
    for(int i = 1; ; ++i) {
        if(!tongji(bian[i].s, bian[i].t)) {
            un(bian[i].s, bian[i].t);
            cnt++;
            ans += bian[i].w;
            if(cnt == n) break;
        }
    }

    cout << ans << endl;

    return 0;
}
