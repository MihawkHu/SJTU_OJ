#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;
const int maxlen = 20100;

int heap[maxlen], heapsize = 0;
int n;

void heapup(int pos) {
    int q = pos >> 1, tem = heap[pos];
    while(1) {
        if(heap[q] > tem) heap[pos] = heap[q];
        else break;
        pos = q;  q = pos >> 1;
    }
    heap[pos] = tem;
}

void enheap(int x) {
    heap[++heapsize] = x;
    heapup(heapsize);
}

void find(int x) {
    int min = 2147000000;
    int pos;
    for(int i = 1; i <= heapsize; ++i)
        if(heap[i] > x && heap[i] < min) {
            min = heap[i];
            pos = i;
        }
    cout << pos << endl;
}

void dec(int pos, int x) {
    heap[pos] -= x;
    heapup(pos);
}


int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        char op[10];  cin >> op;
        if(op[0] == 'i') {
            int a;  cin >> a;
            enheap(a);
        }
        else if(op[0] == 'f') {
            int x;  cin >> x;
            find(x);
        }
        else if(op[0] == 'd') {
            int a, b;  cin >> a >> b;
            dec(a, b);
        }
    }
    return 0;
}
