#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

bool m[12][12];
bool f[12];
int n, m1, s, len, cnt;
int dep = 0;

void dfs(int s) {
    dep++;
    if(dep == len) cnt++;
    for(int i = 1; i <= n; ++i) {
        if(m[s][i] && !f[i]) {
            f[i] = true;
            dfs(i);
            f[i] = false;
        }
    }
    dep--;
}


int main()
{
    cin >> n >> m1 >> s >> len;
    for(int i = 1; i <= m1; ++i) {
        int h1, h2;  cin >> h1 >> h2;
        m[h1][h2] = true;
    }

    f[s] = true;
    dfs(s);
    cout << cnt << endl;

    return 0;
}
