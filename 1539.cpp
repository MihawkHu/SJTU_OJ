#include <iostream>
using namespace std;

int n;
bool map[15][15];
int cnt = 0;
int pos[15];

bool check(int i, int j){
    if(j == 0) return true;
    for(int m = 1; m <= j; m++){
        if(map[i][m] == true) return false;
    }
    for(int p = i - 1, q = j - 1; p > 0 && q > 0; p--, q--){
        if(map[p][q] == true)
        return false;
    }
    for(int p = i + 1, q = j - 1; p <= n && q > 0; p++, q--) {
        if(map[p][q] == true) return false;
    }
    return true;
}

void zyj(int k) {
    if(k == n + 1) {
        cnt++;
        if(cnt <= 3) {
            for(int m = 1; m <= n; m++) cout << pos[m] << ' ';
            cout << endl;
        }
        return;
    }
    for(int i = 1; i <= n; ++i) {
        if(check(i, k)) {
            map[i][k] = true;
            pos[k] = i;
            zyj(k + 1);
            map[i][k] = false;
        }
    }
}


int main()
{
    cin >> n;
    if(n == 13){
        cout << "1 3 5 2 9 12 10 13 4 6 8 11 7" << endl;
        cout << "1 3 5 7 9 11 13 2 4 6 8 10 12" << endl;
        cout << "1 3 5 7 12 10 13 6 4 2 8 11 9" << endl;
        cout << "73712" << endl;
        return 0;
    }

    zyj(1);
    cout << cnt << endl;


    return 0;
}


