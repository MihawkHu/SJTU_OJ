#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;

int n, m1, m2;
int pa[1000000];

int lca(int m1, int m2) {
    if(m1 == 1 || m2 == 1) return 1;
    if(m1 == m2) return m1;
    if(m1 > m2) return lca(pa[m1], m2);
    else return lca(m1, pa[m2]);
}

int main()
{
    cin >> n >> m1 >> m2;
    for(int i = 1; i <= n; ++i) {
        int l1, l2;  cin >> l1 >> l2;
        pa[l1] = pa[l2] = i;
    }
    cout << lca(m1, m2);

    return 0;
}
