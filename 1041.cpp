#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;

int n;

struct node{
    int num;
    int h;

    node() {}
    node(int n, int he) : num(n), h(he) {}
};

node heap[100100];
int heapsize;

void heapup(int pos) {
    int q = pos >> 1;
    int temh = heap[pos].h;
    int temn = heap[pos].num;
    while(q) {
        if(heap[q].h > temh || (heap[q].h == temh && heap[q].num > temn)) heap[pos] = heap[q];
        else break;
        pos = q;  q = pos >> 1;
    }
    heap[pos].h = temh;
    heap[pos].num = temn;
}

void heapdown(int pos) {
    int q = pos << 1;
    int temh = heap[pos].h;
    int temn = heap[pos].num;
    while(q <= heapsize) {
        if(q < heapsize && (heap[q + 1].h < heap[q].h || (heap[q + 1].h == heap[q].h && heap[q + 1].num < heap[q].num))) q++;
        if(heap[q].h < temh || (heap[q].h == temh && heap[q].num < temn)) heap[pos] = heap[q];
        else break;
        pos = q;  q = pos << 1;
    }
    heap[pos].h = temh;
    heap[pos].num = temn;
}

void buildheap(int n) {
    heapsize = n;
    for(int i = heapsize >> 1; i > 0; --i) heapdown(i);
}

void enheap(node x) {
    heap[++heapsize] = x;
    heapup(heapsize);
}

node deheap() {
    node tem = heap[1];
    heap[1] = heap[heapsize--];
    heapdown(1);
    return tem;
}


int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        heap[i].num = i;
        cin >> heap[i].h;
    }

    buildheap(n);

    char a[15];
    while(cin >> a) {
        if(a[0] == 'f') {
            int m;  cin >> m;
            int init = heapsize + 1;
            int t = init;
            while(heap[1].h <= m) {
                node tem(heap[1].num, heap[1].h);
                deheap();
                heap[init].h = tem.h;
                heap[init++].num = tem.num;
            }
            cout << heap[1].num << '\n';
            for(int i = t; i <= init - 1; ++i) enheap(heap[i]);
        }
        else if(a[0] == 'd') {
            int p, q;  cin >> p >> q;
            int pos = 0;
            for(int i = 1; i <= heapsize; ++i) {
                if(heap[i].num == p) {
                    pos = i;
                    break;
                }
            }
            heap[pos].h -= q;
            heapup(pos);
        }
    }


    return 0;
}
