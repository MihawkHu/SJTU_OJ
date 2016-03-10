#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;

int b;
char ans[10000];
char te[10000];

bool huiwen(char *a, int len) {
    for(int i = 1; i <= len / 2; ++i) {
        if(a[i] != a[len - i + 1]) return false;
    }
    return true;
}

int zh(int x, int bas, char * a) {
    int len = 0;
    while(x) {
        a[++len] = x % bas + '0';
        if(a[len] > '9') a[len] = a[len] - '9' + 'A' - 1;
        x /= bas;
    }
    return len;
}

int main()
{
    cin >> b;
    for(int i = 1; i <= 300; ++i) {
        int len = zh(i * i, b, ans);
        if(huiwen(ans, len)) {
            int ll = zh(i, b, te);
            for(int i = ll; i >= 1; --i) cout << te[i];
            cout << ' ';
            for(int i = 1; i <= len; ++i) cout << ans[i];
            cout << '\n';
        }
    }
    return 0;
}
