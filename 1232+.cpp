#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;
const int maxlen = 1010;

int n, x, y;
bool tong[maxlen][maxlen];

int pa[maxlen] = { 0 };
int find(int x) {
    if(pa[x] == 0) {
        pa[x] = -1;
        return x;
    }
    if(pa[x] < 0) return x;
    return pa[x] = find(pa[x]);
}
void un(int x, int y) {
    int i = find(x), j = find(y);
    if(i == j) return;
    if(pa[i] < pa[j]) {
        pa[i] += pa[j];
        pa[j] = i;
    }
    else {
        pa[j] += pa[i];
        pa[i] = j;
    }
}
bool tongji(int x, int y) {
    return find(x) == find(y);
}

int zh(int x, int y) {
    int i;
    for(i = 1;; ++i) {
        int he = i * (i + 1) / 2;
        if(he >= x) break;
    }
    int tem = i * (i - 1) / 2;
    int j = x - tem;
    if(y == 0) {
        if(j == 1) return -1;
        else {
            i--;  j--;
            return i * (i - 1) / 2 + j;
        }
    }
    if(y == 1) {
        if(i == j) return -1;
        else {
            i--;
            return i * (i - 1) / 2 + j;
        }
    }
    if(y == 2) {
        if(i == n) return -1;
        else {
            i++;
            return i * (i - 1) / 2 + j;
        }
    }
    if(y == 3) {
        if(i == n) return -1;
        else {
            i++;  j++;
            return i * (i - 1) / 2 + j;
        }
    }
}

int ans[maxlen];
bool f[maxlen];
bool flag = false;
int cnt = 0;
void dfs(int x) {
    if(flag) return;
    ans[++cnt] = x;
    if(x == y) {
        flag = true;
        for(int i = 1; i <= cnt; ++i) cout << ans[i] << ' ';
        return;
    }
    for(int i = 0; i <= 3; ++i) {
        if(flag) return;
        int tem = zh(x, i);
        if(tem != -1 && tong[x][tem] && !f[tem]) {
            f[tem] = true;
            dfs(tem);
            cnt--;
        }
    }
}

int main()
{
    cin >> n >> x >> y;
    while(1) {
        int num, fx;  cin >> num >> fx;
        int tem = zh(num, fx);
        if(tem == -1) continue;
        tong[num][tem] = tong[tem][num] = true;
        if(tongji(num, tem)) continue;
        un(num, tem);
        if(tongji(x, y)) {
            f[x] = true;
            dfs(x);
            return 0;
        }
    }
    return 0;
}
