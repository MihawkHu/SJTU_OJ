#include <iostream>
using namespace std;

const int a = 0;
const int b = 1;
const int c = 2;
short cap[3];
short curc[3] = { 0 };
struct node{
    short x[3];

    node(short x1, short x2, short x3) {
        x[a] = x1;
        x[b] = x2;
        x[c] = x3;
    }
};

node* que[1000000];
int head = 0;
int rear = 0;
int ans[100];
int siz = 0;
short tem[3] = { 0 };

bool pour(int i){
    if(i == 1){
        if(curc[a] == 0) return false;
        if(curc[b] == cap[b]) return false;
        if(curc[a] + curc[b] <= cap[b]){
            curc[b] = curc[a] + curc[b];
            curc[a] = 0;
            return true;
        }
        else {
            curc[a] = curc[a] - cap[b] + curc[b];
            curc[b] = cap[b];
            return true;
        }
    }

    if(i == 4){
        if(curc[b] == 0) return false;
        if(curc[a] == cap[a]) return false;
        if(curc[b] + curc[a] <= cap[a]){
            curc[a] = curc[b] + curc[a];
            curc[b] = 0;
            return true;
        }
        else {
            curc[b] = curc[b] - cap[a] + curc[a];
            curc[a] = cap[a];
            return true;
        }
    }

    if(i == 2){
        if(curc[c] == 0) return false;
        if(curc[b] == cap[b]) return false;
        if(curc[c] + curc[b] <= cap[b]){
            curc[b] = curc[c] + curc[b];
            curc[c] = 0;
            return true;
        }
        else {
            curc[c] = curc[c] - cap[b] + curc[b];
            curc[b] = cap[b];
            return true;
        }
    }

    if(i == 6){
        if(curc[a] == 0) return false;
        if(curc[c] == cap[c]) return false;
        if(curc[a] + curc[c] <= cap[c]){
            curc[c] = curc[a] + curc[c];
            curc[a] = 0;
            return true;
        }
        else {
            curc[a] = curc[a] - cap[c] + curc[c];
            curc[c] = cap[c];
            return true;
        }
    }

    if(i == 3){
        if(curc[c] == 0) return false;
        if(curc[a] == cap[a]) return false;
        if(curc[c] + curc[a] <= cap[a]){
            curc[a] = curc[c] + curc[a];
            curc[c] = 0;
            return true;
        }
        else {
            curc[c] = curc[c] - cap[a] + curc[a];
            curc[a] = cap[a];
            return true;
        }
    }

    if(i == 5){
        if(curc[b] == 0) return false;
        if(curc[c] == cap[c]) return false;
        if(curc[b] + curc[c] <= cap[c]){
            curc[c] = curc[b] + curc[c];
            curc[b] = 0;
            return true;
        }
        else {
            curc[b] = curc[b] - cap[c] + curc[c];
            curc[c] = cap[c];
            return true;
        }
    }
    return false;
}


bool find(short x){
    for(int i = 0; i < siz; ++i){
        if(ans[i] == x) return true;
    }
    return false;
}

void bfs(){
    curc[c] = cap[c];
    que[rear++] = new node(0, 0, cap[c]);
    for(int cnt = 0; cnt <= 200000; ++cnt){
        if(rear == head) break;
        tem[a] = curc[a] = que[head]->x[a];
        tem[b] = curc[b] = que[head]->x[b];
        tem[c] = curc[c] = que[head]->x[c];
        delete que[head++];
        for(int op = 1; op <= 6; ++op){
            bool flag = pour(op);
            if(flag) {
                que[rear++] = new node(curc[a], curc[b], curc[c]);
                if(curc[a] == 0 && !find(curc[c])){
                    ans[siz++] = curc[c];
                }
                curc[a] = tem[a];
                curc[b] = tem[b];
                curc[c] = tem[c];
            }
        }

    }
}

void qsort(int s, int t){
    if(s >= t) return;
    int i = s, j = t, mid = ans[(i + j) >> 1];
    while(i <= j){
        while(ans[i] < mid) ++i;
        while(ans[j] > mid) --j;
        if(i <= j){
            int tem = ans[i];
            ans[i] = ans[j];
            ans[j] = tem;
            ++i;  --j;
        }
    }
    qsort(s, j);
    qsort(i, t);
}

int main()
{
    cin >> cap[a] >> cap[b] >> cap[c];
    ans[siz++] = cap[c];
    bfs();
    qsort(0, siz - 1);
    for(int i = 0; i < siz; ++i) cout << ans[i] << ' ';

    return 0;
}
