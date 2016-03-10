#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

const int maxlen = 100010;

int n, x, y;
int pa[maxlen] = { 0 };
int a[maxlen], b[maxlen];


int main()
{
    cin >> n >> x >> y;
    for(int i = 1; i <= n; ++i) {
        int le, ri;  cin >> le >> ri;
        pa[le] = pa[ri] = i;
    }
    int cnt1 = 0;
    while(x) {
        a[++cnt1] = x;
        x = pa[x];
    }
    int cnt2 = 0;
    while(y) {
        b[++cnt2] = y;
        y = pa[y];
    }
    for(int i = 1; i <= cnt1; ++i)
        for(int j = 1; j <= cnt2; ++j) {
            if(a[i] == b[j]) {
                cout << a[i] << endl;
                return 0;
            }
        }
    return 0;
}
