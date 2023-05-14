#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second

pair<long double, int> t[4];
long double ans, a[4];
int hh[4];

int main(){
    for(int i = 0; i < 4; i++){
        scanf("%Lf", &t[i].st);
        t[i].nd = i;
    }
    sort(t, t + 4);
    if(t[0].st * t[3].st + t[1].st + t[2].st > t[1].st * t[2].st + t[0].st + t[3].st){
        long double h = (t[1].st + t[2].st - t[3].st - t[1].st * t[2].st) / (1.0 - t[3].st);
        if(h * t[3].st + t[1].st + t[2].st > ans){
            ans = h * t[3].st + t[1].st + t[2].st;
            a[0] = h;
            a[1] = t[1].st;
            a[2] = t[2].st;
            a[3] = t[3].st;
            for(int i = 0; i < 4; i++)
                hh[i] = t[i].nd;
        }
    }
    if(t[0].st * t[3].st + t[1].st + t[2].st < t[1].st * t[2].st + t[0].st + t[3].st){
        long double h = (t[0].st + t[3].st - t[2].st - t[0].st * t[3].st) / (1.0 - t[2].st);
        if(h * t[2].st + t[0].st + t[3].st > ans){
            ans = h * t[2].st + t[0].st + t[3].st;
            a[0] = t[0].st;
            a[1] = h;
            a[2] = t[2].st;
            a[3] = t[3].st;
            for(int i = 0; i < 4; i++)
                hh[i] = t[i].nd;
        }
    }
    if(t[0].st * t[2].st + t[1].st + t[3].st > t[1].st * t[3].st + t[0].st + t[2].st){
        long double h = (t[1].st + t[3].st - t[2].st - t[1].st * t[3].st) / (1.0 - t[2].st);
        if(h * t[2].st + t[1].st + t[3].st > ans){
            ans = h * t[2].st + t[1].st + t[3].st;
            a[0] = h;
            a[1] = t[1].st;
            a[2] = t[2].st;
            a[3] = t[3].st;
            for(int i = 0; i < 4; i++)
                hh[i] = t[i].nd;
            swap(hh[2], hh[3]);
        }
    }
    if(t[0].st * t[2].st + t[1].st + t[3].st > t[1].st * t[3].st + t[0].st + t[2].st){
        long double h = (t[0].st + t[2].st - t[3].st - t[0].st * t[2].st) / (1.0 - t[3].st);
        if(h * t[3].st + t[0].st + t[2].st > ans){
            ans = h * t[3].st + t[0].st + t[2].st;
            a[0] = t[0].st;
            a[1] = h;
            a[2] = t[2].st;
            a[3] = t[3].st;
            for(int i = 0; i < 4; i++)
                hh[i] = t[i].nd;
            swap(hh[2], hh[3]);
        }
    }
    if(t[0].st * t[3].st + t[1].st + t[2].st == t[0].st + t[3].st + t[1].st * t[2].st){
        if(t[0].st * t[3].st + t[1].st + t[2].st > ans){
            ans = t[0].st * t[3].st + t[1].st + t[2].st;
            for(int i = 0; i < 4; i++){
                a[i] = t[i].st;
                hh[i] = t[i].nd;
            }
        }
    }
    swap(t[2], t[3]);
    if(t[0].st * t[3].st + t[1].st + t[2].st == t[0].st + t[3].st + t[1].st * t[2].st){
        if(t[0].st * t[3].st + t[1].st + t[2].st > ans){
            ans = t[0].st * t[3].st + t[1].st + t[2].st;
            for(int i = 0; i < 4; i++){
                a[i] = t[i].st;
                hh[i] = t[i].nd;
            }
        }
    }
    for(int i = 0; i < 4; i++)
        printf("%d ", hh[i] + 1);
    printf("\n");
    for(int i = 0; i < 4; i++)
        printf("%.9Lf ", a[i]);
    return 0;
}