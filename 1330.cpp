#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;
const int maxlen = 130000;
/*
ifstream fin("001.txt");
ofstream fout("002.txt");
*/
int n, m;
int a[maxlen] = { 0 };
int next[maxlen] = { 0 };

struct node {
    int x;
    int y;

    node() {}
    node(int xx, int yy) : x(xx), y(yy) {}
};
node out[10010];
int siz = 0;

void qsort(int s, int t) {
    if(s >= t) return;
    int i = s, j = t;
    node mid = out[(i + j) >> 1];
    while(i <= j) {
        while((out[i].y < mid. y) || (out[i].y == mid.y && out[i].x < mid.x)) i++;
        while((out[j].y > mid. y) || (out[j].y == mid.y && out[j].x > mid.x)) --j;
        if(i <= j) {
            node tem = out[i];
            out[i] = out[j];
            out[j] = tem;
            ++i;  --j;
        }
    }
    qsort(s, j);
    qsort(i, t);
}

void init() {
    for(int i = 0; i <= m; ++i)
        for(int j = 0; j <= m; ++j)
            a[i * i + j * j] = 1;
}

int main()
{
    cin >> n >> m;
    init();

    int jie = m * m;
    for(int i = 0; i <= 2 * jie;) {
        if(a[i]) {
            int j;
            for(j = i + 1; j <= 2 * jie; ++j) {
                if(a[j]) {
                    next[i] = j;
                    next[j] = maxlen;
                    break;
                }
            }
            i = j;
        }
        else i++;
    }

    for(int i = 0; i <= 2 * jie; i = next[i]) {
        if(a[i]) {
            for(int j = next[i]; j <= 2 * jie; j = next[j]) {
                if(a[j]) {
                    bool flag = true;
                    int x = i, y = j - i;
                    int tem = x + y;
                    for(int p = 2; p < n; ++p) {
                        tem += y;
                        if(tem > 2 * jie) {
                            flag = false;
                            break;
                        }
                        if(!a[tem]) {
                            flag = false;
                            break;
                        }
                    }
                    if(flag) {
                        out[++siz].x = x;
                        out[siz].y = y;
                    }
                }
            }
        }
    }
    if(siz == 0) {
        cout << "NONE" << endl;
        return 0;
    }
    qsort(1, siz);
    for(int i = 1; i <= siz; ++i) {
        cout << out[i].x << ' ' << out[i].y << '\n';
    }

    return 0;
}
