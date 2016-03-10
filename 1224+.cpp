#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

const int p = 3999971;
int n;
int ht[4000000];
int cnt[4000000] = { 0 };
int a[510], b[510], c[510], d[510];

int find(int x) {
    int tem = x >= 0 ? x : -x;
    int pos = tem % p;
    while(1) {
        if(cnt[pos] == 0) return 0;
        if(ht[pos] == x) return cnt[pos];
        else pos++;
    }
}
void ins(int x) {
    int tem = x >= 0 ? x : -x;
    int pos = tem % p;
    while(1) {
        if(cnt[pos] == 0) {
            cnt[pos]++;
            ht[pos] = x;
            return;
        }
        if(ht[pos] == x) {
            cnt[pos]++;
            return;
        }
        pos++;
    }
}

int main()
{
    cin >> n;
    int ans = 0;
    for(int i = 1; i <= n; ++i) cin >> a[i] >> b[i] >> c[i] >> d[i];
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            ins(-(a[i] + b[j]));

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            ans += find(c[i] + d[j]);

    cout << ans << endl;
    return 0;
}
