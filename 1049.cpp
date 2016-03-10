#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;

int t, n, m;
int a[10010];
int stack[10010];
int size = 0;
int cur = 1;

void push(int x) {
    stack[++size] = x;
}
void pop() {
    size--;
}

int main()
{
    cin >> t;
    for(int p = 1; p <= t; ++p) {
        cur = 1; size = 0;
        bool flag1 = false, flag2 = false;
        cin >> n >> m;
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
        }
        for(int i = 0; i <= n - 1; ++i) {
            if(i != a[cur]) {
                push(i);
                if(size > m) {
                    flag1 = true;
                    break;
                }
            }
            else {
                cur++;
                if(cur == n + 1) {
                    flag2 = true;
                    break;
                }
            }
            while(size > 0 && cur <= n && stack[size] == a[cur]) {
                size--;
                cur++;
                if(cur == n + 1) {
                    flag2 = true;
                    break;
                }
            }
        }
        if(flag1) cout << "NO" << endl;
        else if(flag2) cout << "YES" << endl;
        else {
            bool flag = false;
            while(size > 0 && cur <= n) {
                if(stack[size] != a[cur]) {
                    cout << "NO" << endl;
                    flag = true;
                    break;
                }
                pop();  cur++;
            }
            if(!flag) cout << "YES" << endl;
        }
    }




    return 0;
}
