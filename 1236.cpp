#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

const int INF = 200000000;

int n, m, s, t;
int d[12][12];

int main()
{
    cin >> n >> m >> s >> t;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j) {
            if(i == j) d[i][j] = 0;
            else d[i][j] = INF;
        }

    for(int i = 1; i <= m; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        if(x == y) d[x][y] = 0;
        else d[x][y] = (w < d[x][y]) ? w : d[x][y];
    }

    for (int k = 1; k <= n; ++k)
        for (int j = 1; j <= n; ++j)
                for (int i = 1; i <= n; ++i) {
                    if (d[i][j] > d[i][k] + d[k][j]) d[i][j] = d[i][k] + d[k][j];
                }
    cout << d[s][t] << endl;
    return 0;
}
