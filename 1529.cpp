#include <iostream>
using namespace std;

int a[25];
int cnt = 0;
int cou = 0;
bool f[4];


void zyj(int n, int k){
    if(cou == n) {
        if(!f[0] || !f[1] || !f[2] || !f[3]) return;
        cnt++;
        if(cnt == k)
            for(int p = 0; p < n; ++p) cout << a[p];
        return;
    }
    bool flag = false;

    for(int i = 0; i < 4; ++i){
        if(f[1] && i == 0) continue;
        else if(!f[0] && i == 1) continue;
        else if(f[3] && i == 2) continue;
        else if(!f[2] && i == 3) continue;
        else if(cou == 0 && i == 0) continue;

        a[cou] = i;
        if(f[i] == true) flag = true;
        else {
            f[i] = true;
            flag = false;
        }
        cou++;
        zyj(n, k);
        cou--;
        if(!flag) f[i] = false;
    }
}


int main()
{
    int n, k;  cin >> n >> k;
    for(int i = 0; i < 25; ++i) a[i] = -1;
    for(int i = 0; i < 4; ++i) f[i] = false;

    zyj(n, k);

    return 0;
}
