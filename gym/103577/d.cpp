#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

char s[N];
int t, p, c[205];

int numb(){
    int h = 0;
    while(p < t && s[p] >= '0' && s[p] <= '9'){
        h *= 10;
        h += (s[p] - '0');
        p++;
    }
    return h;
}

void term(){
    int sig = 1;
    if(s[p] == '+')
        p++;
    if(s[p] == '-'){
        p++;
        sig = -1;
    }
    int h = numb(), e = 0;
    if(s[p] == 'x'){
        h = max(h, 1);
        p++;
        if(s[p] == '^'){
            p++;
            int sige = 1;
            if(s[p] == '-'){
                sige = -1;
                p++;
            }
            e = sige * numb();
        }
        else
            e = 1;
    }
    c[e + 100] += h * sig;
}

void poly(){
    while(p < t)
        term();
}

int main(){
    scanf(" %s", s);
    t = strlen(s);
    poly();
    bool k = false;
    for(int i = 0; i <= 200; i++)
        c[i] *= (i - 100);
    for(int i = 0; i <= 200; i++){
        if(c[i] != 0){
            if(c[i] > 0 && k)
                printf("+");
            if(c[i] < 0){
                printf("-");
                c[i] *= -1;
            }
            if(i != 101){
                if(c[i] != 1)
                    printf("%d", c[i]);
                printf("x");
                if(i != 102)
                    printf("^%d", i - 101);
            }
            else
                printf("%d", c[i]);
            k = true;
        }
    }
    if(!k)
        printf("0\n");
    return 0;
}