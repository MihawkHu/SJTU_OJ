#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;

int n, m;
int cnt = 1;
int que1[1001000], que2[1000100];
int head1 = 0, rear1 = 0, head2 = 0, rear2 = 0;

void enque1(int x) {
    que1[rear1++] = x;
}

int deque1() {
    int x = que1[head1];
    head1++;
    return x;
}

bool que1empty() {
    return head1 == rear1;
}

void enque2(int x) {
    que2[rear2++] = x;
}

int deque2() {
    int x = que2[head2];
    head2++;
    return x;
}

bool que2empty() {
    return head2 == rear2;
}


struct node {
    int num;
    node *next;

    node() : num(0), next(NULL) {}
    node(int x) : num(x), next(NULL) {}
};

node cou[10100];
node* cur[10100];
int d[10100] = { 0 };

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        cur[i] = &cou[i];
        cou[i] = i;
    }
    for(int i = 1; i <= m; ++i) {
        int a, b;  cin >> a >> b;
        d[a]++;
        cur[b]->next = new node(a);
        cur[b] = cur[b]->next;
    }

    for(int i = 1; i <= n; ++i) {
        if(d[i] == 0) enque1(i);
    }
    while(1) {
        while(!que1empty()) {
            int i = deque1();
            cur[i] = &cou[i];
            cur[i] = cur[i]->next;
            while(cur[i] != NULL) {
                d[cur[i]->num]--;
                if(d[cur[i]->num] == 0) enque2(cur[i]->num);
                cur[i] = cur[i]->next;
            }
        }
        if(que2empty()) break;  ++cnt;
        while(!que2empty()) {
            int i = deque2();
            cur[i] = &cou[i];
            cur[i] = cur[i]->next;
            while(cur[i] != NULL) {
                d[cur[i]->num]--;
                if(d[cur[i]->num] == 0) enque1(cur[i]->num);
                cur[i] = cur[i]->next;
            }
        }
        if(que1empty()) break;  ++cnt;
    }
    cout << cnt << endl;

    return 0;
}
