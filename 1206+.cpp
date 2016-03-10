#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

int strcmp(char *a, char *b) {
    char *i = a, *j = b;
    while(*i == *j) {
        if(*i == '\0') return 0;
        i++;  j++;
    }
    return *i - *j;
}

bool flag = false;
int c1 = 0, c3 = 0;

char begin1[10] = "begin";
char end2[10] = "end";
char if3[10] = "if";
char then4[10] = "then";
char else5[10] = "else";


void wrong() {
    cout << "Error!" << endl;
}
void yes() {
    cout << "Match!" << endl;
}

int main()
{
    char in[10];
    while(cin >> in) {
        if(!strcmp(in, begin1)) {
            c1++;
        }
        else if(!strcmp(in, end2)) {
            if(c1 == 0) {
                wrong();
                return 0;
            }
            c1--;
        }
        else if(!strcmp(in, if3)) {
            c3++;
            flag = true;
        }
        else if(!strcmp(in, then4)) {
            if(c3 == 0) {
                wrong();
                return 0;
            }
            c3--;
        }
        else if(!strcmp(in, else5)) {
            if(!flag) {
                wrong();
                return 0;
            }
            flag = false;
        }
    }

    if(c1 == 0 && c3 == 0) yes();
    else wrong();
    return 0;
}
