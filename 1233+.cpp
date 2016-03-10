#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;

int n, m , s, len;

struct node {
    int num;
    node *next;

    node() : next(NULL) {}
    node(int nn) : num(nn), next(NULL) {}
};

node a[1000];


int cnt = -1;
int ans = 0;
bool f[1000];
void dfs(int x) {
    cnt++;
    if(cnt == len) {
        ans++;
        cnt--;
        return;
    }
    node *tem = a[x].next;
    while(tem != NULL) {
        if(!f[tem->num]) {
            f[tem->num] = true;
            dfs(tem->num);
            f[tem->num] = false;
        }
        tem = tem->next;
    }
    cnt--;
}


int main()
{
    cin >> n >> m >> s >> len;
    for(int i = 1; i <= m; ++i) {
        int x, y;  cin >> x >> y;
        node *tem = &a[x];
        if(tem->next == NULL) tem->next = new node(y);
        else {
            while(tem->next != NULL && tem->next->num < y) tem = tem->next;
            node *tmp = new node(y);
            tmp->next = tem->next;
            tem->next = tmp;
        }
    }
    f[s] = true;
    dfs(s);
    cout << ans << endl;
    return 0;
}
